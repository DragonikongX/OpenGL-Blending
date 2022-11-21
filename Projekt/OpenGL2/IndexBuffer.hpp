using namespace std;

class IndexBuffer
{

public:
	GLuint ibo;
	IndexBuffer(vector<GLuint>& indices) {
		glGenBuffers(1, &this->ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
	}

	void Bind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
	}

	void Unbind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void Delete() {
		glDeleteBuffers(1, &this->ibo);
	}
};