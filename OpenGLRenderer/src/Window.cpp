#include <Window.h>

#include <stdexcept>

using namespace std;

namespace Renderer {

	Window::Window(const int32_t width, const int32_t height, const string& name) {
		glfwInitialization();
		window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
		if (!window) {
			glfwTerminate();
			throw runtime_error("Failed to create GLFW Window");
		}
		glfwMakeContextCurrent(window);
		glewInitialization();
		glViewport(0, 0, width, height);
		glEnable(GL_DEPTH_TEST);
	}

	Window::~Window() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	bool Window::ShouldClose() {
		return glfwWindowShouldClose(window);
	}

	void Window::SwapBuffers() {
		glfwSwapBuffers(window);
	}

	void Window::PollEvents() {
		glfwPollEvents();
	}

	void Window::glfwInitialization() {
		if (!glfwInit())
			throw runtime_error("Failed to initialize GLFW!");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	}

	void Window::glewInitialization() {
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			throw runtime_error("Failed to initialize GLEW!");
	}

}