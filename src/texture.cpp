#include <iostream>
#include <texture.h>

Texture::Texture()
{
    this->bedrock = this->load("tex/texture/bedrock.bmp");
    this->stone = this->load("tex/texture/stone.bmp");
    this->dirt = this->load("tex/texture/dirt.bmp");
    this->grass_top = this->load("tex/texture/grass/grass_block_top.bmp");
    this->grass_side = this->load("tex/texture/grass/grass_block_side.bmp");
    this->grass_bottom = this->load("tex/texture/grass/grass_block_bottom.bmp");
}

bool Texture::powerOfTwo(int num)
{
    if (num <= 0) return 0;
    return (num & (num-1)) == 0;
}

GLint Texture::load(const char* file_name)
{
	FILE *f; GLubyte* pixels = 0;
	GLint width, height, totalBytes;
	GLuint lastID = 0, texID = 0;
	if (! (f=fopen(file_name, "rb"))) return 0;
	fseek(f, 0x0012, SEEK_SET);
	fread(&width, 4, 1, f);
	fread(&height, 4, 1, f);
	fseek(f, this->BMP_HEADER_LENGTH, SEEK_SET);
	{
		GLint lineBytes = width * 3;
		while (lineBytes % 4 != 0) lineBytes ++; // 24 位位图。
		totalBytes = lineBytes * height;
	}
	
	if(! (pixels=(GLubyte*)malloc(totalBytes)))
	{ fclose(f); return 0; }
	if (! fread(pixels, totalBytes, 1, f))
	{ free(pixels); fclose(f); return 0; }
	{
		GLint max;
		glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max);
		if (!this->powerOfTwo(width) || !this->powerOfTwo(height)
            || width>max || height>max)
		{
			GLubyte* newPixels = 0;
			GLint newLineBytes, newTotalBytes;
			const GLint new_width = 256, new_height = 256;
			newLineBytes = new_width * 3;
			while (newLineBytes % 4 != 0) newLineBytes ++;
			newTotalBytes = newLineBytes * new_height;
			if (! (newPixels=(GLubyte*)malloc(newTotalBytes)))
			{ free(pixels); fclose(f); return 0; }
			gluScaleImage(GL_RGB, width, height, GL_UNSIGNED_BYTE, pixels,
				new_width, new_height, GL_UNSIGNED_BYTE, newPixels);
			free(pixels);
			pixels = newPixels;
			width = new_width;
			height = new_height;
		}
	}
	glGenTextures(1, &texID);
	if (texID == 0) { free(pixels); fclose(f); return 0; }
	GLint lastTextureID = lastID;
	glGetIntegerv(GL_TEXTURE_BINDING_2D, &lastTextureID);
	glBindTexture(GL_TEXTURE_2D, texID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
		GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);
	glBindTexture(GL_TEXTURE_2D, lastTextureID);
	free(pixels); fclose(f);
	return texID;
}