#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/gl.h>

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "geometry.h"
#include "image.h"
#include "texture.h"
#include "shader.h"
#include "erode.h"

// TODO remove
#define INT_CEIL(n,d) (int)ceil((float)n/d)

Eroder::Eroder()
{
	m_copy.compile("shaders/erosion/copy.comp", GL_COMPUTE_SHADER);
	m_copy.link();

	m_terrain_ping.format(GL_TEXTURE_2D, GL_RED, GL_R32F, GL_FLOAT);
	m_terrain_pong.format(GL_TEXTURE_2D, GL_RED, GL_R32F, GL_FLOAT);
}
	
void Eroder::reset(const gfx::Texture &input)
{
	m_width = input.width();
	m_height = input.height();

	m_terrain_ping.resize(input.width(), input.height());
	m_terrain_pong.resize(input.width(), input.height());

	// copy input data
	m_copy.use();
	input.bind(0, GL_READ_ONLY);
	m_terrain_ping.bind(1, GL_WRITE_ONLY);

	glDispatchCompute(INT_CEIL(m_width, 32), INT_CEIL(m_height, 32), 1);
	glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
		
	m_terrain_ping.bind(GL_TEXTURE0);
}
