#include "Cube.h"

unsigned int cube_vao;

void createCube()
{
	float side = 0.15f;

	GLfloat cube_vertices[] = { side, side, side, 1.0f,  // v0,v1,v2,v3 (front)
							   -side, side, side, 1.0f,
							   -side, -side, side, 1.0f,
								side, -side, side, 1.0f,
								side, side, side, 1.0f,  // v0,v3,v4,v5 (right)
								side, -side, side, 1.0f,
								side, -side, -side, 1.0f,
								side, side, -side, 1.0f,
								side, side, side, 1.0f,  // v0,v5,v6,v1 (top)
								side, side, -side, 1.0f,
							   -side, side, -side, 1.0f,
							   -side, side, side, 1.0f,
							   -side, side, side, 1.0f, // v1,v6,v7,v2 (left)
							   -side, side, -side, 1.0f,
							   -side, -side, -side, 1.0f,
							   -side, -side, side, 1.0f,
							   -side, -side, -side, 1.0f,// v7,v4,v3,v2 (bottom)
							   side, -side, -side, 1.0f,
							   side, -side, side, 1.0f,
							   -side, -side, side, 1.0f,
							   side, -side, -side, 1.0f,// v4,v7,v6,v5 (back)
							   -side, -side, -side, 1.0f,
							   -side, side, -side, 1.0f,
							   side, side, -side, 1.0f };

	GLfloat cube_colors[] = {
		//Front face of cube (cyan)
		0.0, 1.0, 1.0, 1.0,
		0.0, 1.0, 1.0, 1.0,
		0.0, 1.0, 1.0, 1.0,
		0.0, 1.0, 1.0, 1.0,

		//Right face of cube (magenta)
		1.0, 0.0, 1.0, 1.0,
		1.0, 0.0, 1.0, 1.0,
		1.0, 0.0, 1.0, 1.0,
		1.0, 0.0, 1.0, 1.0,

		//Top face of cube (yellow)
		1.0, 1.0, 0.0, 1.0,
		1.0, 1.0, 0.0, 1.0,
		1.0, 1.0, 0.0, 1.0,
		1.0, 1.0, 0.0, 1.0,

		//Left face of cube (magenta)
		1.0, 0.0, 1.0, 1.0,
		1.0, 0.0, 1.0, 1.0,
		1.0, 0.0, 1.0, 1.0,
		1.0, 0.0, 1.0, 1.0,

		//Bottom face of cube (yellow)
		1.0, 1.0, 0.0, 1.0,
		1.0, 1.0, 0.0, 1.0,
		1.0, 1.0, 0.0, 1.0,
		1.0, 1.0, 0.0, 1.0,

		//Back face of cube (cyan)
		0.0, 1.0, 1.0, 1.0,
		0.0, 1.0, 1.0, 1.0,
		0.0, 1.0, 1.0, 1.0,
		0.0, 1.0, 1.0, 1.0,
	};
	


	GLushort cube_indices[] = { 0, 1, 2, 2, 3, 0,      // front
		4, 5, 6, 6, 7, 4,      // right
		8, 9, 10, 10, 11, 8,      // top
		12, 13, 14, 14, 15, 12,      // left
		16, 17, 18, 18, 19, 16,      // bottom
		20, 21, 22, 22, 23, 20 };    // back

	glGenVertexArrays(1, &cube_vao);
	glBindVertexArray(cube_vao);

	//handle is the number of buffers (this is increased from 2 to 3)
	//handle acts as both ebo and vbo[2] combined
	unsigned int handle[3];
	glGenBuffers(3, handle);

	glBindBuffer(GL_ARRAY_BUFFER, handle[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);  // Vertex position

	glBindBuffer(GL_ARRAY_BUFFER, handle[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_colors), cube_colors, GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)1, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);  // Vertex color

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle[2]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_indices), cube_indices, GL_STATIC_DRAW);

	glBindVertexArray(0);

}

void drawCube() {
	glBindVertexArray(cube_vao);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
}
