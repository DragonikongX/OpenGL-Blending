#version 460 core

out vec4 FragColor;

uniform vec4 fragLightColor;

void main(){
    FragColor = fragLightColor;
};