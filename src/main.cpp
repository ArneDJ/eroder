#include <iostream>
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

#include "extern/imgui/imgui.h"
#include "extern/imgui/imgui_impl_sdl.h"
#include "extern/imgui/imgui_impl_opengl3.h"

#include "geometry.h"
#include "input.h"
#include "timer.h"
#include "camera.h"
#include "mesh.h"
#include "shader.h"

void run(SDL_Window *window)
{
	util::Camera camera;
	camera.set_projection(90.f, 1920, 1080, 0.1f, 2000.f);
	camera.position = glm::vec3(0.f, 200.f, 0.f);
	camera.target(glm::vec3(1000.f, 0.f, 1000.f));

	gfx::Shader shader;
	shader.compile("shaders/terrain.vert", GL_VERTEX_SHADER);
	shader.compile("shaders/terrain.tesc", GL_TESS_CONTROL_SHADER);
	shader.compile("shaders/terrain.tese", GL_TESS_EVALUATION_SHADER);
	shader.compile("shaders/terrain.frag", GL_FRAGMENT_SHADER);
	shader.link();

	gfx::TesselationMesh mesh;
	geom::Rectangle rectangle = { { 0.f, 0.f }, { 1024.f, 1024.f } };
	mesh.create(32, rectangle);

	util::FrameTimer timer;

	while (!util::InputManager::exit_request()) {
		timer.begin();
		float delta = timer.delta_seconds();

		util::InputManager::update();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL2_NewFrame(window);

		ImGui::NewFrame();
		ImGui::Begin("Debug");
		ImGui::SetWindowSize(ImVec2(400, 300));
		ImGui::Text("cam position: %f, %f, %f", camera.position.x, camera.position.y, camera.position.z);
		ImGui::Text("cam direction: %f, %f, %f", camera.direction.x, camera.direction.y, camera.direction.z);
		ImGui::End();

		if (util::InputManager::key_down(SDL_BUTTON_MIDDLE)) {
			glm::vec2 offset = delta * 0.1f * util::InputManager::rel_mouse_coords();
			camera.add_offset(offset);
		}

		float speed = 50.f * delta;

		if (util::InputManager::key_down(SDLK_w)) { camera.move_forward(speed); }
		if (util::InputManager::key_down(SDLK_s)) { camera.move_backward(speed); }
		if (util::InputManager::key_down(SDLK_d)) { camera.move_right(speed); }
		if (util::InputManager::key_down(SDLK_a)) { camera.move_left(speed); }

		camera.update_viewing();
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.use();
		shader.uniform_mat4("CAMERA_VP", camera.VP);

		mesh.draw();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		SDL_GL_SwapWindow(window);
		
		timer.finish();
	}
}

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow("Eroder", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_OPENGL);

	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	SDL_GLContext glcontext = SDL_GL_CreateContext(window);

	GLenum error = glewInit();

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	(void)io;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

	// Setup Platform/Renderer bindings
	ImGui_ImplSDL2_InitForOpenGL(window, glcontext);
	ImGui_ImplOpenGL3_Init("#version 460");

	glClearColor(0.5f, 0.5f, 0.8f, 1.f);
	glEnable(GL_DEPTH_TEST);

	run(window);

	SDL_GL_DeleteContext(glcontext);

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
