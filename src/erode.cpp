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

static void swap_textures(gfx::Texture &a, gfx::Texture &b)
{
	GLuint binding_a = a.binding();
	GLuint binding_b = b.binding();

	a.set_binding(binding_b);
	b.set_binding(binding_a);
}

Eroder::Eroder()
{
	m_copy.compile("shaders/erosion/copy.comp", GL_COMPUTE_SHADER);
	m_copy.link();

	m_water.compile("shaders/erosion/water.comp", GL_COMPUTE_SHADER);
	m_water.link();

	m_flux.compile("shaders/erosion/flux.comp", GL_COMPUTE_SHADER);
	m_flux.link();

	m_velocity.compile("shaders/erosion/velocity.comp", GL_COMPUTE_SHADER);
	m_velocity.link();

	m_soil.compile("shaders/erosion/soil.comp", GL_COMPUTE_SHADER);
	m_soil.link();

	m_transport.compile("shaders/erosion/transport.comp", GL_COMPUTE_SHADER);
	m_transport.link();

	m_evaporate.compile("shaders/erosion/evaporate.comp", GL_COMPUTE_SHADER);
	m_evaporate.link();

	m_terrain_ping.format(GL_TEXTURE_2D, GL_RED, GL_R32F, GL_FLOAT);
	m_terrain_pong.format(GL_TEXTURE_2D, GL_RED, GL_R32F, GL_FLOAT);
	m_water_ping.format(GL_TEXTURE_2D, GL_RED, GL_R32F, GL_FLOAT);
	m_water_pong.format(GL_TEXTURE_2D, GL_RED, GL_R32F, GL_FLOAT);
	m_flux_ping.format(GL_TEXTURE_2D, GL_RGBA, GL_RGBA32F, GL_FLOAT);
	m_flux_pong.format(GL_TEXTURE_2D, GL_RGBA, GL_RGBA32F, GL_FLOAT);
	m_velocity_field.format(GL_TEXTURE_2D, GL_RG, GL_RG32F, GL_FLOAT);
	m_sediment_ping.format(GL_TEXTURE_2D, GL_RED, GL_R32F, GL_FLOAT);
	m_sediment_pong.format(GL_TEXTURE_2D, GL_RED, GL_R32F, GL_FLOAT);
	m_normal_map.format(GL_TEXTURE_2D, GL_RGBA, GL_RGBA32F, GL_FLOAT);
}
	
void Eroder::bind_textures() const
{
	m_terrain_ping.bind(GL_TEXTURE10);
	m_water_ping.bind(GL_TEXTURE11);
	m_flux_ping.bind(GL_TEXTURE12);
	m_sediment_ping.bind(GL_TEXTURE13);
	m_normal_map.bind(GL_TEXTURE14);
}
	
void Eroder::reset(const gfx::Texture &input)
{
	m_width = input.width();
	m_height = input.height();

	m_terrain_ping.resize(input.width(), input.height());
	m_terrain_pong.resize(input.width(), input.height());
	m_water_ping.resize(input.width(), input.height());
	m_water_pong.resize(input.width(), input.height());
	m_flux_ping.resize(input.width(), input.height());
	m_flux_pong.resize(input.width(), input.height());
	m_velocity_field.resize(input.width(), input.height());
	m_sediment_ping.resize(input.width(), input.height());
	m_sediment_pong.resize(input.width(), input.height());
	m_normal_map.resize(input.width(), input.height());

	// copy input data
	m_copy.use();
	input.bind(0, GL_READ_ONLY);
	m_terrain_ping.bind(1, GL_WRITE_ONLY);

	glDispatchCompute(INT_CEIL(m_width, 32), INT_CEIL(m_height, 32), 1);
	glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
}
	
void Eroder::step(float time)
{
	//increment_water(time);
	simulate_flow(time);
	update_water_velocity(time);
	erosion_deposition();
	transport_sediment(time);
	evaporate_water(time);
}

void Eroder::increment_water(float time)
{
	m_water.use();
	m_water.uniform_float("TIME", time);

	m_water_ping.bind(0, GL_READ_ONLY);
	m_water_pong.bind(1, GL_WRITE_ONLY);

	glDispatchCompute(INT_CEIL(m_width, 32), INT_CEIL(m_height, 32), 1);
	glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);

	swap_textures(m_water_ping, m_water_pong);
}
	
void Eroder::simulate_flow(float time)
{
	m_flux.use();
	m_flux.uniform_float("TIME", time);
	m_flux.uniform_int("WIDTH", m_width);
	m_flux.uniform_int("HEIGHT", m_height);

	m_terrain_ping.bind(0, GL_READ_ONLY);
	m_water_ping.bind(1, GL_READ_ONLY);
	m_flux_ping.bind(2, GL_READ_ONLY);

	m_flux_pong.bind(3, GL_WRITE_ONLY);

	glDispatchCompute(INT_CEIL(m_width, 32), INT_CEIL(m_height, 32), 1);
	glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
	
	swap_textures(m_flux_ping, m_flux_pong);
}
	
void Eroder::update_water_velocity(float time)
{
	m_velocity.use();
	m_velocity.uniform_float("TIME", time);

	m_water_ping.bind(0, GL_READ_ONLY);
	m_flux_ping.bind(1, GL_READ_ONLY);

	m_water_pong.bind(2, GL_WRITE_ONLY);
	m_velocity_field.bind(3, GL_WRITE_ONLY);

	glDispatchCompute(INT_CEIL(m_width, 32), INT_CEIL(m_height, 32), 1);
	glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
	
	swap_textures(m_water_ping, m_water_pong);
}
	
void Eroder::erosion_deposition()
{
	m_soil.use();
	m_soil.uniform_float("Ks", dissolve_factor);
	m_soil.uniform_float("Kd", deposition_factor);
	m_soil.uniform_float("Kc", transport_capacity);

	m_terrain_ping.bind(0, GL_READ_ONLY);
	m_sediment_ping.bind(1, GL_READ_ONLY);
	m_velocity_field.bind(2, GL_READ_ONLY);

	m_terrain_pong.bind(3, GL_WRITE_ONLY);
	m_sediment_pong.bind(4, GL_WRITE_ONLY);
	m_normal_map.bind(5, GL_WRITE_ONLY);

	glDispatchCompute(INT_CEIL(m_width, 32), INT_CEIL(m_height, 32), 1);
	glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);

	swap_textures(m_terrain_ping, m_terrain_pong);
	swap_textures(m_sediment_ping, m_sediment_pong);
}
	
void Eroder::transport_sediment(float time)
{
	m_transport.use();
	m_transport.uniform_float("TIME", time);

	m_sediment_ping.bind(0, GL_READ_ONLY);
	m_velocity_field.bind(1, GL_READ_ONLY);
	m_sediment_pong.bind(3, GL_WRITE_ONLY);

	glDispatchCompute(INT_CEIL(m_width, 32), INT_CEIL(m_height, 32), 1);
	glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);

	swap_textures(m_sediment_ping, m_sediment_pong);
}
	
void Eroder::evaporate_water(float time)
{
	m_evaporate.use();
	m_evaporate.uniform_float("TIME", time);
	m_evaporate.uniform_float("Ke", evaporation_factor);

	m_water_ping.bind(0, GL_READ_ONLY);
	m_water_pong.bind(1, GL_WRITE_ONLY);

	glDispatchCompute(INT_CEIL(m_width, 32), INT_CEIL(m_height, 32), 1);
	glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);

	swap_textures(m_water_ping, m_water_pong);
}
