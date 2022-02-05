#version 430 core

in TESSEVAL {
	vec3 position;
	vec2 texcoord;
	float zclipspace;
} fragment;

out vec4 fcolor;

uniform sampler2D DISPLACEMENT;
//uniform sampler2D TILES;
//uniform sampler2D NORMALMAP;

uniform vec3 SUN_POS = vec3(0.2, 0.5, 0.1);

void main(void)
{
	float height = texture(DISPLACEMENT, fragment.texcoord).r;

	fcolor = vec4(vec3(height), 1.0);
	//fcolor = vec4(0.5, 0.5, 0.5, 1.0);

	//vec3 normal = texture(NORMALMAP, fragment.texcoord).rgb;

	// terrain lighting
	//const vec3 light_color = vec3(1.0, 1.0, 1.0);
	//float diffuse = max(0.0, dot(normal, SUN_POS));

	//vec3 scattered_light = light_color * diffuse;

	//fcolor.rgb = mix(min(fcolor.rgb * scattered_light, vec3(1.0)), fcolor.rgb, 0.5);
}
