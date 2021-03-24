#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Vertex.h>

namespace Renderer {

	template<class BufferType>
	class Buffer {
	public:
		void Bind() const { MakeBuffer().Bind(); }
		void UnBind() const { MakeBuffer().UnBind(); }

	private:
		uint32_t id;

		friend BufferType;
		Buffer() = default;

		inline BufferType& MakeBuffer() { return static_cast<BufferType&>(*this); }
	};

}
