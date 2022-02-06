#version 430 core

layout(vertices = 4) out;

void main(void)
{
	float detail = 8.0;
	if (gl_InvocationID == 0) {
		gl_TessLevelOuter[0] = detail;
		gl_TessLevelOuter[1] = detail;
		gl_TessLevelOuter[2] = detail;
		gl_TessLevelOuter[3] = detail;
		gl_TessLevelInner[0] = detail;
		gl_TessLevelInner[1] = detail;
	}

	gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
}
