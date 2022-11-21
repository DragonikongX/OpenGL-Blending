#include "Mesh.hpp"

using namespace std;

class Window : public Mesh
{
	
public:
	vector<GLuint> indicies;

	using Mesh::Mesh;

	Window(vector <Vertex>& vertices, vector<GLuint>& indicies, vector<Texture>& textures, ShaderUseClass* shader) {
		this->shader = shader;
		this->vertices = vertices;
		this->indicies = indicies;
		this->textures = textures;
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

	void DrawWindow(Camera& camera) {
		
		this->shader->UseShader();
		this->vertexMeshArray.Bind();
		if (!this->textures.empty()) {
			
			GLuint textureDiffuseNumber = 0;
			GLuint textureSpecularNumber = 0;

			for (int i = 0; i < textures.size(); i++) {
				string textureName;
				string textureType = textures[i].type;
				if (textureType == "Diffuse") {
					textureName = to_string(textureDiffuseNumber++);
				}
				else if (textureType == "Specular") {
					textureName = to_string(textureSpecularNumber++);
				}
				textures[i].textureUnit(*shader, ("fragTexture" + textureType + textureName).c_str(), i);
				textures[i].Bind();
			}	
		}
		glUniform3f(glGetUniformLocation(shader->shaderID, "fragCameraPosition"), camera.position.x, camera.position.y, camera.position.z);
		camera.Matrix(*shader, "vertCamMatrix");
		if (indicies.empty()) {
			glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());
			return;
		}
		glDrawElements(GL_TRIANGLES, this->indicies.size(), GL_UNSIGNED_INT, 0);
	}
};
