#include "IndexBuffer.hpp"

using namespace std;


class Light
{
	ShaderUseClass* lightShader;
public:
	vector<Vertex> vertices;
	vector<GLuint> indicies;
	VertexArray vertexMeshArray;

	vec3 position = vec3(0.0f, 0.0f, 0.0f);
	vec4 color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	mat4 modelMatrix = mat4(1.0f);
	vec3 rotation = vec3(0.0f, 0.0f, 0.0f);
	vec3 scale = vec3(1.0f, 1.0f, 1.0f);

	Light(){}
	
	~Light(){}


	Light(vector <Vertex>& vertices, vector<GLuint>& indicies, ShaderUseClass* lightShader) {

		this->lightShader = lightShader;
		this->vertices = vertices;
		this->indicies = indicies;
		this->vertexMeshArray.Bind();

		VertexBuffer vertexMeshBuffer(this->vertices);
		IndexBuffer indexMeshBuffer(this->indicies);

		this->vertexMeshArray.LinkAttribute(vertexMeshBuffer, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
		this->vertexMeshArray.LinkAttribute(vertexMeshBuffer, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
		this->vertexMeshArray.LinkAttribute(vertexMeshBuffer, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
		this->vertexMeshArray.LinkAttribute(vertexMeshBuffer, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));

		this->vertexMeshArray.Unbind();
		vertexMeshBuffer.Unbind();
		indexMeshBuffer.Unbind();
	}

	void DrawLight(Camera& camera) {
		this->lightShader->UseShader();
		this->vertexMeshArray.Bind();
		glUniform3f(glGetUniformLocation(lightShader->shaderID, "fragCameraPosition"), camera.position.x, camera.position.y, camera.position.z);
		camera.Matrix(*lightShader, "vertCamMatrix");
		glDrawElements(GL_TRIANGLES, this->indicies.size(), GL_UNSIGNED_INT, 0);
	}

	void SetPosition(vec3 position) {
		this->position = position;
	}

	void SetRotation(vec3 rotation) {
		this->rotation = rotation;

	}

	void SetScale(vec3 scale) {
		this->scale = scale;
	}

	void SetUniform() {
		this->modelMatrix = mat4(1.0f);
		this->modelMatrix = rotate(this->modelMatrix, radians(this->rotation.x), vec3(1.f, 0.f, 0.f));
		this->modelMatrix = rotate(this->modelMatrix, radians(this->rotation.y), vec3(0.f, 1.f, 0.f));
		this->modelMatrix = rotate(this->modelMatrix, radians(this->rotation.z), vec3(0.f, 0.f, 1.f));
		this->modelMatrix = glm::scale(this->modelMatrix, this->scale);
		this->modelMatrix = translate(this->modelMatrix, this->position);
		this->lightShader->UseShader();
		this->lightShader->UseShader();
		glUniformMatrix4fv(glGetUniformLocation(lightShader->shaderID, "vertModel"), 1, GL_FALSE, value_ptr(modelMatrix));
		glUniform4f(glGetUniformLocation(lightShader->shaderID, "fragLightColor"), color.x, color.y, color.z, color.w);

	}
};