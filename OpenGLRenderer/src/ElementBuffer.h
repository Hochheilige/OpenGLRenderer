#pragma once

#include <Buffer.h>

#include <vector>

namespace Renderer {

	class ElementBuffer : public Buffer<ElementBuffer> {
	public:
		ElementBuffer(const std::vector<uint32_t>& vertexes);

		ElementBuffer(const ElementBuffer&) = delete;
		void operator=(const ElementBuffer&) = delete;

		~ElementBuffer();

		void Bind() const;
		void UnBind() const;
	private:
		ElementBuffer(const void* data, const size_t size);
	};

}