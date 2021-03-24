#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <array>

#include <VertexBuffer.h>
#include <BufferLayout.h>

namespace Renderer {

	class VertexArray {
	public:
		VertexArray();
		~VertexArray();

		void AddBuffer(const VertexBuffer& vertexBuffer);

		void Bind() const;
		void UnBind() const;

	private:
		uint32_t id;
	};

}