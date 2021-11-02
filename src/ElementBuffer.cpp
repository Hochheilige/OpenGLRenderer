#include <ElementBuffer.h>

namespace Renderer {

	ElementBuffer::ElementBuffer(const void* data, const size_t size) {
		glGenBuffers(1, &id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	ElementBuffer::ElementBuffer(const std::vector<uint32_t>& vertexes)
		: ElementBuffer(vertexes.data(), sizeof(uint32_t)* vertexes.size()) {
	}

	ElementBuffer::~ElementBuffer() {
		glDeleteBuffers(1, &id);
	}

	void ElementBuffer::Bind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	}

	void ElementBuffer::UnBind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}