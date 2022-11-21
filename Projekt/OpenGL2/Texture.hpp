#include <stb_image.h>

using namespace std;

class Texture
{

public:
	GLuint textureID;
	const char* type;
	GLuint unit;
	Texture() {};
	Texture(const char* imagePath, const char* textureType, GLuint slot, GLenum format, GLenum pixelType, GLuint channels) {

		int imgWidth, imgHeight, imgChannels;

		unsigned char* imgBytes = stbi_load(imagePath, &imgWidth, &imgHeight, &imgChannels, channels);
		if (!imgBytes) {
			cout << "Texture Loading Error!" << endl;
			return;
		}
		this->type = textureType;
		glGenTextures(1, &textureID);
		glActiveTexture(GL_TEXTURE0 + slot);
		this->unit = slot;
		glBindTexture(GL_TEXTURE_2D, textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, format, pixelType, imgBytes);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(imgBytes);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void textureUnit(ShaderUseClass shader, const char *uniform, GLuint unit) {
		GLuint texID = glGetUniformLocation(shader.shaderID, uniform);
		shader.UseShader();
		glUniform1i(texID, unit);
	}

	void Bind() {
		glActiveTexture(GL_TEXTURE0 + this->unit);
		glBindTexture(GL_TEXTURE_2D, textureID);
	}

	void Unbind() {
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Delete() {
		glDeleteTextures(1, &textureID);
	}

};