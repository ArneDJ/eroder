#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <memory>
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "mesh.h"

namespace gfx {

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

static size_t typesize(GLenum type);

BufferObject::BufferObject()
{
	glGenBuffers(1, &m_buffer);
}

BufferObject::~BufferObject()
{
	glDeleteBuffers(1, &m_buffer);
}
	
void BufferObject::set_target(GLenum target)
{
	glBindBuffer(target, m_buffer);
	m_target = target;
}

void BufferObject::bind() const
{
	glBindBuffer(m_target, m_buffer);
}

void BufferObject::bind_base(GLuint index) const
{
	glBindBufferBase(m_target, index, m_buffer);
}

void BufferObject::bind_explicit(GLenum target, GLuint index) const
{
	glBindBuffer(target, m_buffer);
	glBindBufferBase(target, index, m_buffer);
}
	
GLsizei BufferObject::size() const
{
	return m_size;
}
	
void BufferObject::store_immutable(GLsizei size, const void *data, GLbitfield flags)
{
	glBindBuffer(m_target, m_buffer);
	glBufferStorage(m_target, size, data, flags);
	m_size = size;
}
	
void BufferObject::store_mutable(GLsizei size, const void *data, GLenum usage)
{
	glBindBuffer(m_target, m_buffer);
	glBufferData(m_target, size, data, usage);
	m_size = size;
}

// When replacing the entire data store, consider using glBufferSubData rather than completely recreating the data store with glBufferData. This avoids the cost of reallocating the data store.
void BufferObject::store_mutable_part(GLintptr offset, GLsizei size, const void *data)
{
	glBindBuffer(m_target, m_buffer);
	glBufferSubData(m_target, offset, size, data);
}

VertexArrayObject::VertexArrayObject()
{
	glGenVertexArrays(1, &m_array);
}

VertexArrayObject::~VertexArrayObject()
{
	glDeleteVertexArrays(1, &m_array);
}

void VertexArrayObject::bind() const
{
	glBindVertexArray(m_array);
}

void VertexArrayObject::set_attribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid *pointer)
{
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

void VertexArrayObject::set_integer_attribute(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid *pointer)
{
	glEnableVertexAttribArray(index);
	glVertexAttribIPointer(index, size, type, stride, pointer);
}
	
void TesselationMesh::create(uint32_t resolution, const geom::Rectangle &bounds)
{
	m_vertices.clear();

	const glm::vec2 offset = { 
		glm::distance(bounds.min.x, bounds.max.x) / float(resolution), 
		glm::distance(bounds.min.y, bounds.max.y) / float(resolution) 
	};

	glm::vec3 origin = { bounds.min.x, 0.f, bounds.min.y };
	for (int x = 0; x < resolution; x++) {
		for (int z = 0; z < resolution; z++) {
			m_vertices.push_back(glm::vec3(origin.x, origin.y, origin.z));
			m_vertices.push_back(glm::vec3(origin.x + offset.x, origin.y, origin.z));
			m_vertices.push_back(glm::vec3(origin.x, origin.y, origin.z + offset.y));
			m_vertices.push_back(glm::vec3(origin.x + offset.x, origin.y, origin.z + offset.y));
			origin.x += offset.x;
		}
		origin.x = bounds.min.x;
		origin.z += offset.y;
	}

	m_vao.bind();

	m_vbo.set_target(GL_ARRAY_BUFFER);
	m_vbo.store_mutable(sizeof(glm::vec3) * m_vertices.size(), m_vertices.data(), GL_STATIC_DRAW);

	m_vao.set_attribute(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (char*)0);
}
	
void TesselationMesh::draw() const
{
	m_vao.bind();

	glPatchParameteri(GL_PATCH_VERTICES, 4);
	glDrawArrays(GL_PATCHES, 0, m_vertices.size());
}

GLenum index_type(size_t size)
{
	switch (size) {
	case sizeof(GLubyte): return GL_UNSIGNED_BYTE;
	case sizeof(GLushort): return GL_UNSIGNED_SHORT;
	case sizeof(GLuint): return GL_UNSIGNED_INT;
	default: return GL_BYTE;
	}
}
	
static size_t typesize(GLenum type)
{
	switch (type) {
	case GL_UNSIGNED_BYTE: return sizeof(GLubyte);
	case GL_UNSIGNED_SHORT: return sizeof(GLushort);
	case GL_UNSIGNED_INT: return sizeof(GLuint);
	};

	return 0;
}

};
