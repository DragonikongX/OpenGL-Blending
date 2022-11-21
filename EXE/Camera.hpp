#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/rotate_vector.hpp>
#include <gtx/vector_angle.hpp>

using namespace glm;

class Camera {
public:
	vec3 position, orientation, upVector;
	int width, height;
	float speed, sensitivity;
	mat4 cameraMatrix;

	bool fClick;

	Camera(int width, int height, vec3 position) {
		this->position = position;
		this->orientation = vec3(0.0f, 0.0f, -1.0f);
		this->upVector = vec3(0.0f, 1.0f, 0.0f);
		this->width = width;
		this->height = height;
		this->speed = 0.1f;
		this->sensitivity = 100.0f;
		this->cameraMatrix = mat4(1.0f);
		this->fClick = true;
	}

	void Matrix(ShaderUseClass& shader, const char* uniform) {
		glUniformMatrix4fv(glGetUniformLocation(shader.shaderID, uniform), 1, GL_FALSE, value_ptr(this->cameraMatrix));
	}

	void UpdateMatrix(float fovDegrees, float near, float far) {
		mat4 view = mat4(1.0f);
		mat4 projection = mat4(1.0f);

		view = lookAt(this->position, this->position + this->orientation, this->upVector);
		projection = perspective(radians(fovDegrees), (float)(this->width / this->height), near, far);

		this->cameraMatrix = projection * view;
	}

	void Input(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			this->position += speed * this->orientation;
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{
			this->position += speed * -glm::normalize(glm::cross(this->orientation, this->upVector));
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		{
			this->position += speed * -this->orientation;
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		{
			this->position += speed * glm::normalize(glm::cross(this->orientation, this->upVector));
		}

		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		{
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

			if (this->fClick)
			{
				glfwSetCursorPos(window, (width / 2), (height / 2));
				this->fClick = false;
			}

			double mouseX;
			double mouseY;
			glfwGetCursorPos(window, &mouseX, &mouseY);

			float rotationX = sensitivity * (float)(mouseY - (height / 2)) / height;
			float rotationY = sensitivity * (float)(mouseX - (width / 2)) / width;

			glm::vec3 newOrientation = glm::rotate(this->orientation, glm::radians(-rotationX), glm::normalize(glm::cross(this->orientation, this->upVector)));

			if (abs(glm::angle(newOrientation, this->upVector) - glm::radians(90.0f)) <= glm::radians(85.0f))
			{
				this->orientation = newOrientation;
			}

			this->orientation = glm::rotate(this->orientation, glm::radians(-rotationY), this->upVector);

			glfwSetCursorPos(window, (width / 2), (height / 2));
		}
		else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
		{
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			this->fClick = true;
		}
	}
};