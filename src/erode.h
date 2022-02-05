
class Eroder {
public:
	Eroder();
	void reset(const gfx::Texture &input);
private:
	int m_width = 0;
	int m_height = 0;
private:
	gfx::Shader m_copy;
private:
	gfx::Texture m_terrain_ping;
	gfx::Texture m_terrain_pong;
};
