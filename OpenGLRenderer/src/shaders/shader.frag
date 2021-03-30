#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D containerTex;
uniform sampler2D smileTex;

void main()
{
	FragColor = mix(texture(containerTex, TexCoord), texture(smileTex, TexCoord), 0.2);
}