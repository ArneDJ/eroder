#version 430 core

in TESSEVAL {
	vec3 position;
	vec2 texcoord;
	float zclipspace;
} fragment;

out vec4 fcolor;

layout (binding = 10) uniform sampler2D DISPLACEMENT;
layout (binding = 11) uniform sampler2D WATER;
layout (binding = 12) uniform sampler2D FLUX;
//uniform sampler2D TILES;
//uniform sampler2D NORMALMAP;

uniform vec3 SUN_POS = vec3(0.2, 0.5, 0.1);

void main(void)
{
	float height = texture(DISPLACEMENT, fragment.texcoord).r;
	float water = texture(WATER, fragment.texcoord).r;

	fcolor.rgb = vec3(0.0, 0.0, 1.0);
}
