#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace Renderer {

	enum class TextureFormat  {
		RGB = GL_RGB,
		RGBA = GL_RGBA
	};

	enum class TextureWrap {
		CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
		CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER,
		MIRRORED_REPEAT = GL_MIRRORED_REPEAT,
		REPEAT = GL_REPEAT
	};

	class Texture {
	public:
		Texture();

		~Texture();

		void Load(const std::string& path, TextureFormat format);

		void SetWrapType(TextureWrap wrap);

		void GenerateMipmaps();

		void Bind(uint32_t slot = 0);

		void UnBind();
	private:
		uint32_t id = 0;
		int32_t width = 0, height = 0;
		int32_t channels = 0;
		uint8_t* data = nullptr;
	};

}