#version 460 core

out vec3 fragCurrentPosition;
out vec3 fragNormals;
out vec3 fragColor;
out vec2 fragTexture;

layout (location = 0) in vec3 vertPosition;
layout (location = 1) in vec3 vertNormals;
layout (location = 2) in vec3 vertColor;
layout (location = 3) in vec2 vertTexturePosition;

uniform mat4 vertCamMatrix;
uniform mat4 vertModel;

void main(){
	fragCurrentPosition = vec3(vertModel * vec4(vertPosition, 1.0f));
	gl_Position = vertCamMatrix * vec4(fragCurrentPosition, 1.0f);

	fragColor = vertColor;
	fragTexture = vertTexturePosition;
	fragNormals = vertNormals;
};