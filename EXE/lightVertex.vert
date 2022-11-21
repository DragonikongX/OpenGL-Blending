#version 460 core

layout (location = 0) in vec3 vertPosition;

uniform mat4 vertCamMatrix;
uniform mat4 vertModel;

void main(){
	gl_Position = vertCamMatrix * vertModel * vec4(vertPosition,1.0f);
};
