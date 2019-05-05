#version 330 core

in vec2 texCoord;
in vec3 normalCoord;
in vec3 fragPos;

out vec4 FragColor;

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light light;
uniform	vec3 viewPos;
uniform sampler2D texture1;

void main()
{
	// ambient
	vec3 ambient = light.ambient;

	// diffuse
	vec3 norm = normalize(normalCoord);
	vec3 lightDir = normalize(light.position - fragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse * diff;

	// specular
	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);
	vec3 specular = light.specular * spec;

	// attenuation (constants for distance < 160)
	float constant = 1.0;
	float linear = 0.027;
	float quadratic = 0.0028;

	float distance = length(light.position - fragPos);
	float attenuation = 1.0 / (constant + linear * distance + quadratic * (distance * distance));

	ambient  *= attenuation;
	diffuse  *= attenuation;
	specular *= attenuation;

	FragColor = vec4(ambient + diffuse + specular, 1.0) * texture(texture1, texCoord);
}