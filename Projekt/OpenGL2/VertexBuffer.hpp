using namespace std;

struct Vertex {
	vec3 position;
	vec3 normal;
	vec3 color;
	vec2 textureUv;
};

class VertexBuffer
{
	
public:
	GLuint vbo;
	VertexBuffer(vector<Vertex> &vertices) {
		glGenBuffers(1, &this->vbo);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

	}

	void Bind() {
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	}
	
	void Unbind() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Delete() {
		glDeleteBuffers(1, &this->vbo);
	}
};