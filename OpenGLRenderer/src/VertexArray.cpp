#include <VertexArray.h>

namespace Renderer {

	VertexArray::VertexArray() {
		glGenVertexArrays(1, &id);
		glBindVertexArray(id);
	}

	VertexArray::~VertexArray() {
		glDeleteVertexArrays(1, &id);
	}

	void VertexArray::AddBuffer(const VertexBuffer& vertexBuffer) {
		Bind();
		vertexBuffer.Bind();
		uint32_t offset = 0;
		uint32_t stride = 0;

		for (const auto& layout : layouts)
			stride += layout.byteSize;
		 
		for (size_t i = 0; i < layouts.size(); ++i) {
			glVertexAttribPointer(i, layouts[i].size, layouts[i].type, GL_FALSE, stride, (void*)offset);
			glEnableVertexAttribArray(i);
			offset += layouts[i].byteSize;
		}
	}

	void VertexArray::Bind() const {
		glBindVertexArray(id);
	}

	void VertexArray::UnBind() const {
		glBindVertexArray(0);
	}

}