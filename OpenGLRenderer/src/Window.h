#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>

namespace Renderer {

	class Window {
	public:
		Window(const int32_t width, const int32_t height, const std::string& name);

		~Window();

		Window(const Window& window) = delete;
		void operator =(const Window& window) = delete;

		bool ShouldClose();
		void SwapBuffers();
		void PollEvents();

		inline GLFWwindow* GetWindow() { return window; }
 	private:
		GLFWwindow* window = nullptr;

		void glfwInitialization();
		void glewInitialization();
	};

}