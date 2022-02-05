namespace gfx {

class Texture {
public:
	Texture();
	~Texture();
public:
	GLsizei width() const;
	GLsizei height() const;
public:
	void format(GLenum target, GLenum format, GLenum internal_format, GLenum type);
	void resize(GLsizei width, GLsizei height);
	void create(const util::Image<uint8_t> &image);
	void reload(const util::Image<uint8_t> &image);
	void create(const util::Image<float> &image);
	void reload(const util::Image<float> &image);
	void change_filtering(GLint filter);
public:
	void bind(GLenum unit) const;
	void bind(GLuint unit, GLenum access) const;
public:
	GLuint binding();
	void set_binding(GLuint bind);
private:
	GLsizei m_width = 0;
	GLsizei m_height = 0;
	GLuint m_binding = 0;
	GLenum m_target = GL_TEXTURE_2D;
	GLenum m_format = GL_RED;
	GLenum m_internal_format = GL_R8;
	GLenum m_type = GL_UNSIGNED_BYTE;
};

};
