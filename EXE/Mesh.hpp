#include "Texture.hpp"
#include "Camera.hpp"
#include "VertexArray.hpp"
#include "Light.hpp"

using namespace std;

class Mesh
{
public:
	ShaderUseClass* shader;
	vector<Vertex> vertices;
	vector<Texture> textures;
	VertexArray vertexMeshArray;

	vec3 position = vec3(0.0f, 0.0f, 0.0f);
	vec3 rotation = vec3(0.0f, 0.0f, 0.0f);
	vec3 scale = vec3(1.0f, 1.0f, 1.0f);
	mat4 modelMatrix = mat4(1.0f);
	
	Mesh() {};
	~Mesh() {};

	Mesh(const char* filename,ShaderUseClass* shader ,vector<Texture> newtextures, float textureScale = 5.0f) {
		this->shader = shader;
		this->vertexMeshArray.Bind();
		this->textures = newtextures;
		this->vertices = loadOBJ(filename, textureScale);
		VertexBuffer vertexMeshBuffer(this->vertices);
		
		this->vertexMeshArray.LinkAttribute(vertexMeshBuffer, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
		this->vertexMeshArray.LinkAttribute(vertexMeshBuffer, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
		this->vertexMeshArray.LinkAttribute(vertexMeshBuffer, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
		this->vertexMeshArray.LinkAttribute(vertexMeshBuffer, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));
		
		this->vertexMeshArray.Unbind();
		
		vertexMeshBuffer.Unbind();
	}

	vector<Vertex> loadOBJ(const char* file_name, float textureScale = 5.0f)
	{
		std::vector<glm::fvec3> vertex_positions;
		std::vector<glm::fvec2> vertex_texcoords;
		std::vector<glm::fvec3> vertex_normals;

		std::vector<GLint> vertex_position_indicies;
		std::vector<GLint> vertex_texcoord_indicies;
		std::vector<GLint> vertex_normal_indicies;

		std::vector<Vertex> vertices;

		std::stringstream ss;
		std::ifstream in_file(file_name);
		std::string line = "";
		std::string prefix = "";
		glm::vec3 temp_vec3;
		glm::vec2 temp_vec2;
		GLint temp_glint = 0;

		if (!in_file.is_open())
		{
			throw "ERROR::OBJLOADER::Could not open file.";
		}

		while (std::getline(in_file, line))
		{
			ss.clear();
			ss.str(line);
			ss >> prefix;

			if (prefix == "v")
			{
				ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
				vertex_positions.push_back(temp_vec3);
			}
			else if (prefix == "vt")
			{
				ss >> temp_vec2.x >> temp_vec2.y;
				vertex_texcoords.push_back(temp_vec2);
			}
			else if (prefix == "vn")
			{
				ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
				vertex_normals.push_back(temp_vec3);
			}
			else if (prefix == "f")
			{
				int counter = 0;
				while (ss >> temp_glint)
				{
					if (counter == 0)
						vertex_position_indicies.push_back(temp_glint);
					else if (counter == 1)
						vertex_texcoord_indicies.push_back(temp_glint);
					else if (counter == 2)
						vertex_normal_indicies.push_back(temp_glint);

					if (ss.peek() == '/')
					{
						++counter;
						ss.ignore(1, '/');
					}
					else if (ss.peek() == ' ')
					{
						++counter;
						ss.ignore(1, ' ');
					}

					if (counter > 2)
						counter = 0;
				}
			}
		}
		vertices.resize(vertex_position_indicies.size(), Vertex());

		for (size_t i = 0; i < vertices.size(); ++i)
		{
			vertices[i].position = vertex_positions[vertex_position_indicies[i] - 1];
			vertices[i].normal = vertex_normals[vertex_normal_indicies[i] - 1];
			vertices[i].textureUv = vertex_texcoords[vertex_texcoord_indicies[i] - 1] * textureScale;
		}
		return vertices;
	}

	void DrawMesh(Camera& camera) {
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
		glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());
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

	void SetUniform(Light light) {
		this->modelMatrix = mat4(1.0f);
		this->modelMatrix = rotate(this->modelMatrix, radians(this->rotation.x), vec3(1.f, 0.f, 0.f));
		this->modelMatrix = rotate(this->modelMatrix, radians(this->rotation.y), vec3(0.f, 1.f, 0.f));
		this->modelMatrix = rotate(this->modelMatrix, radians(this->rotation.z), vec3(0.f, 0.f, 1.f));
		this->modelMatrix = glm::scale(this->modelMatrix, this->scale);
		this->modelMatrix = translate(this->modelMatrix, this->position * (1.0f/this->scale));
		this->shader->UseShader();
		glUniformMatrix4fv(glGetUniformLocation(shader->shaderID, "vertModel"), 1, GL_FALSE, value_ptr(this->modelMatrix));
		glUniform4f(glGetUniformLocation(shader->shaderID, "fragLightColor"), light.color.x, light.color.y, light.color.z, light.color.w);
		glUniform3f(glGetUniformLocation(shader->shaderID, "fragLightPos"), light.position.x, light.position.y, light.position.z);
	}
};
