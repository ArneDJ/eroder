
class Eroder {
public:
	Eroder();
	void reset(const gfx::Texture &input);
	void step(float time);
	void bind_textures() const;
private:
	int m_width = 0;
	int m_height = 0;
private:
	gfx::Shader m_copy;
	gfx::Shader m_water;
private:
	gfx::Texture m_terrain_ping;
	gfx::Texture m_terrain_pong;
	gfx::Texture m_water_ping;
	gfx::Texture m_water_pong;
private:
	void increment_water(float time);
};
