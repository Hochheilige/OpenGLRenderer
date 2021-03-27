#include <Texture.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace Renderer {

	Texture::Texture() {
        glGenTextures(1, &id);
	}

    Texture::~Texture(){
        glDeleteTextures(1, &id);
        id = 0;

    }

    void Texture::Load(const std::string& path, TextureFormat format) {
        Bind();

        stbi_set_flip_vertically_on_load(true);
        data = stbi_load(path.c_str(), &width, &height, &channels, 0);
        if (data) 
            glTexImage2D(GL_TEXTURE_2D, 0, (GLint)format, width, height, 0, (GLint)format, GL_UNSIGNED_BYTE, data);
        else 
            std::cout << "Failed to load texture" << std::endl;
        
        GenerateMipmaps();

        stbi_image_free(data);
    }

    void Texture::SetWrapType(TextureWrap wrap) {
        Bind();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, (GLint)wrap);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, (GLint)wrap);
    }

    void Texture::GenerateMipmaps() {
        Bind();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    void Texture::Bind() {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, id);
    }

    void Texture::UnBind() {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

}