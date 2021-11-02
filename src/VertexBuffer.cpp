#include <VertexBuffer.h>

namespace Renderer {

	VertexBuffer::VertexBuffer(const void* data, const size_t size) {
		glGenBuffers(1, &id);
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	VertexBuffer::VertexBuffer(const std::vector<Vertex>& vertexes)
		: VertexBuffer(vertexes.data(), sizeof(Vertex) * vertexes.size()) {
	}

	VertexBuffer::~VertexBuffer() {
		glDeleteBuffers(1, &id);
	}

	void VertexBuffer::Bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, id);
	}

	void VertexBuffer::UnBind() const {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

}