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
layout (binding = 13) uniform sampler2D SEDIMENT;
layout (binding = 14) uniform sampler2D NORMAL_MAP;
//uniform sampler2D TILES;
//uniform sampler2D NORMALMAP;

uniform vec3 SUN_POS = vec3(0.2, 0.5, 0.1);

void main(void)
{
	float height = texture(DISPLACEMENT, fragment.texcoord).r;
	float water = texture(WATER, fragment.texcoord).r;
	float sediment = texture(SEDIMENT, fragment.texcoord).r;

	vec3 normal = texture(NORMAL_MAP, fragment.texcoord).rgb;
	
	fcolor = vec4(0.8, 0.8, 0.8, 1.0);

	//fcolor = texture(FLUX, fragment.texcoord);

	//fcolor = vec4(vec3(height), 1.0);
	//fcolor = vec4(normal, 1.0);
	//fcolor.rgb = mix(fcolor.rgb, vec3(0.5, 0.5, 0.), sediment);
	//fcolor = vec4(vec3(sediment), 1.0);

	//fcolor.rgb = mix(fcolor.rgb, vec3(0.0, 0.0, 1.0), water);
	//fcolor = vec4(0.5, 0.5, 0.5, 1.0);

	//vec3 normal = texture(NORMALMAP, fragment.texcoord).rgb;

	// terrain lighting
	const vec3 light_color = vec3(1.0, 1.0, 1.0);
	float diffuse = max(0.0, dot(normal, SUN_POS));

	vec3 scattered_light = light_color * diffuse;

	fcolor.rgb = mix(min(fcolor.rgb * scattered_light, vec3(1.0)), fcolor.rgb, 0.5);
}
