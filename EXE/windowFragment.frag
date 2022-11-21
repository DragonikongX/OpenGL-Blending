#version 460 core

out vec4 FragColor;

in vec3 fragCurrentPosition;
in vec3 fragNormals;
in vec3 fragColor;
in vec2 fragTexture;

uniform sampler2D fragTextureDiffuse0;
uniform sampler2D fragTextureSpecular0;
uniform vec4 fragLightColor;
uniform vec3 fragLightPos;
uniform vec3 fragCameraPosition;

vec4 PointLight(float ambientValue, float specularValue, float a, float b){
    vec3 lightVector = fragLightPos - fragCurrentPosition;
    float distance = length(lightVector);
    float intensity = 1.0f / (a * pow(distance,2) + b * distance + 1.0f);
    float ambient = ambientValue;

    vec3 normalizedNormals = normalize(fragNormals);
    vec3 lightDirection = normalize(fragLightPos - fragCurrentPosition);
    float diffuse = max(dot(normalizedNormals, lightDirection), 0.0f);

    float specular = 0.0f;
    if(diffuse != 0.0f){
        float specularLight = specularValue;
        vec3 viewDirection = normalize(fragCameraPosition - fragCurrentPosition);
        vec3 halfLength = normalize(viewDirection + lightDirection);
        vec3 reflectionDirection = reflect(-lightDirection, normalizedNormals);
        float specAmount = pow(max(dot(normalizedNormals, halfLength), 0.0f), 32);
        specular = specAmount * specularLight;
    };

    return (texture(fragTextureDiffuse0, fragTexture) * (diffuse * intensity + ambient ) + texture(fragTextureSpecular0, fragTexture).r * specular * intensity) * fragLightColor;
}

void main(){
    FragColor = PointLight(0.2f, 0.5f, 1.0f, 0.5f) * vec4(fragColor, 0.8f);
};