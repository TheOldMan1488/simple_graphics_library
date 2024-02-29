#version 430
layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
uniform mat4 projection;
uniform mat4 model;
out vec4 vertexColor;

void main()
{
	gl_Position = projection * model * vec4(position, 1.0);
	vertexColor = color;
};