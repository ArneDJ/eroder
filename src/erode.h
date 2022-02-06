
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
	gfx::Shader m_flux;
	gfx::Shader m_velocity;
	gfx::Shader m_soil;
	gfx::Shader m_transport;
	gfx::Shader m_evaporate;
private:
	gfx::Texture m_terrain_ping;
	gfx::Texture m_terrain_pong;
	gfx::Texture m_water_ping;
	gfx::Texture m_water_pong;
	gfx::Texture m_flux_ping;
	gfx::Texture m_flux_pong;
	gfx::Texture m_velocity_field;
	gfx::Texture m_sediment_ping;
	gfx::Texture m_sediment_pong;
private:
	void increment_water(float time);
	void simulate_flow(float time);
	void update_water_velocity(float time);
	void erosion_deposition();
	void transport_sediment(float time);
	void evaporate_water(float time);
};
