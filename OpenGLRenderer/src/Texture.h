#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <iostream>

namespace Renderer {
	
	enum class TextureFormat : uint8_t {
		RGB,
		RGBA
	};

	enum class TextureWrap : uint8_t {
		CLAMP_TO_EDGE,
		CLAMP_TO_BORDER,
		MIRRORED_REPEAT,
		REPEAT
	};
	
	class Texture {
	public:
		Texture(const char* texturePath, const TextureFormat);

		void Bind();
	private:
		uint32_t id;
	};

}