#pragma once 

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cassert>
#include <array>

#include <Vertex.h>

namespace Renderer {

	struct Data {
		size_t size;
		GLenum type;
		size_t byteSize;
	};

	template<typename T>
	struct Layout;

	template<>
	struct Layout<Vector3> {
		Data data = Data{
			Vector3::length(),
			GL_FLOAT, 
			sizeof(Vector3) 
		};
	};

	template<>
	struct Layout<Vector2> {
		Data data = Data{
			Vector2::length(),
			GL_FLOAT,
			sizeof(Vector2)
		};
	};
 
	static std::array<Data, 2> layouts{
		Layout<Vector3>().data,
		Layout<Vector2>().data
	};

	[[maybe_unused]] static uint32_t GetSizeOfType(uint32_t type) {
		switch (type) {
			case GL_FLOAT: return sizeof(float);
			default: return 0;
		}
	}
}
