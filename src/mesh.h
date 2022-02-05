#pragma once 
#include "geometry.h"

namespace gfx {

struct Vertex {
	glm::vec3 position = {};
	glm::vec3 normal = {};
};

struct Primitive {
	GLuint first_index = 0;
	GLsizei index_count = 0;
	GLuint first_vertex = 0;
	GLsizei vertex_count = 0;
	GLenum mode = GL_TRIANGLES; // rendering mode (GL_TRIANGLES, GL_PATCHES, etc)
	GLenum index_type = GL_UNSIGNED_INT;
	geom::AABB bounds;
};

class BufferObject {
public:
	BufferObject();
	~BufferObject();
public:
	void set_target(GLenum target);
	void store_immutable(GLsizei size, const void *data, GLbitfield flags);
	void store_mutable(GLsizei size, const void *data, GLenum usage);
	void store_mutable_part(GLintptr offset, GLsizei size, const void *data);
public:
	void bind() const;
	void bind_base(GLuint index) const;
	void bind_explicit(GLenum target, GLuint index) const;
	GLsizei size() const;
private:
	GLenum m_target = GL_ARRAY_BUFFER;
	GLsizei m_size = 0;
	GLuint m_buffer = 0;
};

class VertexArrayObject {
public:
	VertexArrayObject();
	~VertexArrayObject();
public:
	void bind() const;
	void set_attribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid *pointer);
	void set_integer_attribute(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid *pointer);
private:
	GLuint m_array = 0;
};

class TesselationMesh {
public:
	void create(uint32_t resolution, const geom::Rectangle &bounds);
	void draw() const;
private:
	BufferObject m_vbo;
	VertexArrayObject m_vao;
	std::vector<glm::vec3> m_vertices;
};

GLenum index_type(size_t size);

};
