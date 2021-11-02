#pragma once

#include <glm/glm.hpp>

namespace Renderer {

	using Vector3 = glm::vec3;
	using Vector2 = glm::vec2;

	struct Vertex {
		Vector3 position;
		//glm::vec3 color;
		Vector2 textureCoord;

		constexpr static size_t size = Vector3::length() + Vector2::length();
	};

}

