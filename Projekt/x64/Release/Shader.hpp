#include <fstream>

using namespace std;

static class ShaderLoadClass
{
public:
	static string readFile(const string& filePath) {
		ifstream fs(filePath, ios::in);
		stringstream buffer;
		string line;
		while (getline(fs, line)) {
			buffer << line << "\n";
		}
		fs.close();
		return buffer.str();
	}

	static GLuint compileShader(GLuint type, const string& source)
	{
		GLuint hShader = glCreateShader(type);
		GLint result;
		const char* src = source.c_str();

		glShaderSource(hShader, 1, &src, nullptr);
		glCompileShader(hShader);
		glGetShaderiv(hShader, GL_COMPILE_STATUS, &result);

		return hShader;
	}
};

class ShaderUseClass
{
public:
	GLuint shaderID;
	ShaderUseClass(const string& vertexShader, const string& fragmentShader) {
		this->CreateShader(vertexShader, fragmentShader);
	}
	void CreateShader(const string& vertexShader, const string& fragmentShader) {
		GLint result;
		GLuint fs = ShaderLoadClass::compileShader(GL_FRAGMENT_SHADER, fragmentShader);
		GLuint vs = ShaderLoadClass::compileShader(GL_VERTEX_SHADER, vertexShader);
		if (vs == 0 || fs == 0) {
			return;
		}
		this->shaderID = glCreateProgram();
		glAttachShader(shaderID, vs);
		glAttachShader(shaderID, fs);
		glLinkProgram(shaderID);
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
		glValidateProgram(shaderID);
		glDetachShader(shaderID, vs);
		glDetachShader(shaderID, fs);
	}

	void UseShader() {
		glUseProgram(shaderID);
	}

	void DeleteShader() {
		glDeleteProgram(shaderID);
	}
};