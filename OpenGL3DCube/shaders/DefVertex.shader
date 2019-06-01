#version 420 core
in vec3 position;
in vec3 vertexColor;

varying vec3 vColor;

uniform mat4 Model;

void main() 
{
	gl_Position = Model * vec4(position,1.0);
	vColor = vertexColor;
}
