#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <iostream>

#include <Window.h>
#include <VertexArray.h>
#include <ElementBuffer.h>
#include <Shaders.h>
#include <Texture.h>
#include <Camera.h>

using namespace Renderer;

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

int main() {
	Window window(800, 600, "Application");
	
	std::vector<Vertex> vertexes = {
		{{ 0.5f,  0.5f, -0.5f}, {1.0f, 1.0f}},
		{{ 0.5f, -0.5f, -0.5f}, {1.0f, 0.0f}},
		{{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f}},
		{{-0.5f,  0.5f, -0.5f}, {0.0f, 1.0f}},
		{{ 0.5f,  0.5f,  0.5f}, {0.0f, 1.0f}},
		{{ 0.5f, -0.5f,  0.5f}, {0.0f, 0.0f}},
		{{-0.5f, -0.5f,  0.5f}, {1.0f, 0.0f}},
		{{-0.5f,  0.5f,  0.5f}, {1.0f, 1.0f}},
		{{-0.5f,  0.5f,  0.5f}, {0.0f, 0.0f}},
		{{ 0.5f, -0.5f,  0.5f}, {1.0f, 1.0f}},
		{{ 0.5f,  0.5f,  0.5f}, {1.0f, 0.0f}},
		{{-0.5f, -0.5f,  0.5f}, {0.0f, 1.0f}}
	};

	std::vector<uint32_t> indices = { 
		0, 1, 3,
		1, 2, 3,
		0, 1, 4,
		1, 4, 5,
		2, 3, 7,
		2, 6, 7,
		4, 5, 7,
		5, 6, 7,
		0, 3, 10,
		3, 10, 8,
		1, 2, 9,
		2, 9, 11
	};

	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	Texture blue;
	blue.SetWrapType(TextureWrap::REPEAT);
	TextureFormat rgb = TextureFormat::RGB;
	blue.Load("textures/blue.jpg", TextureFormat::RGB);
	Shader shaders("shaders/shader.vert", "shaders/shader.frag");

	VertexArray vao;
	VertexBuffer vbo(vertexes);
	ElementBuffer ebo(indices);

	vao.AddBuffer(vbo);

	shaders.Use();
	shaders.SetInt("ourTexture", 0);
	
	glm::mat4 projection;
	glm::mat4 model;
	glm::mat4 view;

	while (!window.ShouldClose()) {

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glClearColor(0.2f, 0.5f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		blue.Bind();
		shaders.Use();

		projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		shaders.setMat4("projection", projection);

		// camera/view transformation
		view = camera.GetViewMatrix();
		shaders.setMat4("view", view);

		vao.Bind();
		for (uint32_t i = 0; i < 10; ++i) {
			model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);
			float angle = 20.0f * (i + 1);
			model = glm::rotate(model, (float)glfwGetTime() * glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			shaders.setMat4("model", model);

			glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
		}

		window.SwapBuffers();
		window.PollEvents();
	}

	return 0;
}
