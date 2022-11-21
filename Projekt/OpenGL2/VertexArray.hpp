#include "VertexBuffer.hpp"

using namespace std;

class VertexArray
{
	
public:
	GLuint vao;
	VertexArray() {
		glGenVertexArrays(1, &this->vao);
	}

	void LinkAttribute(VertexBuffer& vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {
		vbo.Bind();
		glVertexAttribPointer(layout, numComponents, type, GL_TRUE, stride, offset);
		glEnableVertexAttribArray(layout);
		vbo.Unbind();
	}
	void Bind() {
		glBindVertexArray(this->vao);
	}
	void Unbind() {
		glBindVertexArray(0);
	}

	void Delete() {
		glDeleteVertexArrays(1, &this->vao);
	}
};