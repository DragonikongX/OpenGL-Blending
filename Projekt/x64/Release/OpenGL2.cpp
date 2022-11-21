#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <string>
#include <sstream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <map>

#include "Shader.hpp"
#include "Window.hpp"
#include "SoloFunctions.hpp"
#include "Databases.hpp"

using namespace glm;
using namespace std;

const int width = 800;
const int height = 800;


int main()
{
	GLFWwindow* window;
	if (!glfwInit())
	{
		return -1;
	}
	window = glfwCreateWindow(width, height, "OpenGL - Blending", NULL, NULL);
	if (window == NULL) {
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		return -1;
	}
	glViewport(0, 0, width, height);

	ShaderUseClass lightShader(ShaderLoadClass::readFile("lightVertex.vert"), ShaderLoadClass::readFile("lightFragment.frag"));
	ShaderUseClass shader(ShaderLoadClass::readFile("vertex.vert"), ShaderLoadClass::readFile("fragment.frag"));
	ShaderUseClass windowShader(ShaderLoadClass::readFile("windowVertex.vert"), ShaderLoadClass::readFile("windowFragment.frag"));
	ShaderUseClass flowerShader(ShaderLoadClass::readFile("flowerVertex.vert"), ShaderLoadClass::readFile("flowerFragment.frag"));

	Database database = Database(lightShader, shader, windowShader, flowerShader);
	Camera camera(width, height, vec3(0.0f, 0.0f, 0.0f));
	

	glEnable(GL_DEPTH_TEST);
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

		camera.Input(window);
		camera.UpdateMatrix(45.0f, 0.1f, 100.0f);

		database.DrawDatabase(camera);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	shader.DeleteShader();
	lightShader.DeleteShader();
	flowerShader.DeleteShader();
	windowShader.DeleteShader();
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}