#pragma once

#include <vector>

#include <Buffer.h>

namespace Renderer {

	class VertexBuffer : public Buffer<VertexBuffer> {
	public:
		VertexBuffer(const std::vector<Vertex>& vertexes);

		VertexBuffer(const VertexBuffer&) = delete;
		void operator=(const VertexBuffer&) = delete;

		~VertexBuffer();

		void Bind() const;
		void UnBind() const;

	private:
		VertexBuffer(const void* data, const size_t size);
	};
	 
}