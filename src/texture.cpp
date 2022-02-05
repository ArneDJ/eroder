#include <vector>
#include <fstream>
#include <array>
#include <algorithm>
#include <memory>
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "image.h"
#include "texture.h"

namespace gfx {

Texture::Texture()
{
	glGenTextures(1, &m_binding);
}

Texture::~Texture()
{
	if (glIsTexture(m_binding) == GL_TRUE) {
		glDeleteTextures(1, &m_binding);
	}
}
	
GLsizei Texture::width() const
{
	return m_width;
}
	
GLsizei Texture::height() const
{
	return m_height;
}

void Texture::create(const util::Image<uint8_t> &image)
{
	m_target = GL_TEXTURE_2D;

	m_internal_format = 0;
	m_type = GL_UNSIGNED_BYTE;

	switch (image.channels()) {
	case 1:
		m_internal_format = GL_R8;
		m_format = GL_RED;
		break;
	case 2:
		m_internal_format = GL_RG8;
		m_format = GL_RG;
		break;
	case 3:
		m_internal_format = GL_RGB8;
		m_format = GL_RGB;
		break;
	case 4:
		m_internal_format = GL_RGBA8;
		m_format = GL_RGBA;
		break;
	}

	m_width = image.width();
	m_height = image.height();

	glBindTexture(m_target, m_binding);

	glTexStorage2D(m_target, 1, m_internal_format, image.width(), image.height());
	glTexSubImage2D(m_target, 0, 0, 0, image.width(), image.height(), m_format, m_type, image.raster().data());

	glTexParameteri(m_target, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(m_target, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexParameteri(m_target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(m_target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glBindTexture(m_target, 0);
}

void Texture::create(const util::Image<float> &image)
{
	m_target = GL_TEXTURE_2D;

	m_internal_format = 0;
	m_type = GL_FLOAT;

	switch (image.channels()) {
	case 1:
		m_internal_format = GL_R32F;
		m_format = GL_RED;
		break;
	case 2:
		m_internal_format = GL_RG32F;
		m_format = GL_RG;
		break;
	case 3:
		m_internal_format = GL_RGB32F;
		m_format = GL_RGB;
		break;
	case 4:
		m_internal_format = GL_RGBA32F;
		m_format = GL_RGBA;
		break;
	}

	m_width = image.width();
	m_height = image.height();

	glBindTexture(m_target, m_binding);

	glTexStorage2D(m_target, 1, m_internal_format, image.width(), image.height());
	glTexSubImage2D(m_target, 0, 0, 0, image.width(), image.height(), m_format, m_type, image.raster().data());

	glTexParameteri(m_target, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(m_target, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexParameteri(m_target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(m_target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glBindTexture(m_target, 0);
}
	
void Texture::format(GLenum target, GLenum format, GLenum internal_format, GLenum type)
{
	m_target = target;
	m_format = format;
	m_internal_format = internal_format;
	m_type = type;

	glBindTexture(target, m_binding);

	glTexImage2D(target, 0, internal_format, 1, 1, 0, format, type, NULL);

	glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glBindTexture(target, 0);
}
	
void Texture::resize(GLsizei width, GLsizei height)
{
	m_width = width;
	m_height = height;
	
	glBindTexture(m_target, m_binding);

	glTexImage2D(m_target, 0, m_internal_format, width, height, 0, m_format, m_type, NULL);
}

void Texture::reload(const util::Image<uint8_t> &image)
{
	m_width = image.width();
	m_height = image.height();

	glBindTexture(m_target, m_binding);
	glTexSubImage2D(m_target, 0, 0, 0, image.width(), image.height(), m_format, m_type, image.raster().data());
}

void Texture::reload(const util::Image<float> &image)
{
	m_width = image.width();
	m_height = image.height();

	glBindTexture(m_target, m_binding);
	glTexSubImage2D(m_target, 0, 0, 0, image.width(), image.height(), m_format, m_type, image.raster().data());
}

void Texture::bind(GLenum unit) const
{
	glActiveTexture(unit);
	glBindTexture(m_target, m_binding);
}
	
void Texture::bind(GLenum unit, GLenum access) const
{
	glBindImageTexture(unit, m_binding, 0, GL_FALSE, 0, access, m_internal_format);
}
	
GLuint Texture::binding()
{
	return m_binding;
}

void Texture::change_filtering(GLint filter)
{
	glBindTexture(m_target, m_binding);
	glTexParameteri(m_target, GL_TEXTURE_MAG_FILTER, filter);
	glTexParameteri(m_target, GL_TEXTURE_MIN_FILTER, filter);
}

};
