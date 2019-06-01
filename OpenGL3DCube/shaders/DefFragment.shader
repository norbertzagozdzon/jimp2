#version 420 core

out vec4 color;

varying vec3 vColor;

void main()
{
	
	color = vec4(vColor,1.0);
}