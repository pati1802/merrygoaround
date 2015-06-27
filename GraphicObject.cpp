#include "GraphicObject.hpp"

/**
 * used to create a new object
 */
GraphicObject::GraphicObject(std::string file) {
	bool res = loadOBJ(file, vertices, uvs, normals);
	if(res == false) {
		std::cerr << "Coudln't load object!" << std::endl;
		return;
	}

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3),
		&vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &uvBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0],
		GL_STATIC_DRAW);
}

/**
 * used to copy one object to anoter
 */
GraphicObject::GraphicObject(const GraphicObject& obj) {
	// TODO : test if this works
	std::copy(obj.vertices.begin(), obj.vertices.end(),
		this->vertices.begin());
	std::copy(obj.uvs.begin(), obj.uvs.end(), this->uvs.begin());
	std::copy(obj.normals.begin(), obj.normals.end(), this->normals.begin());
}

/**
 * used to delete one object from memory
 */
GraphicObject::~GraphicObject() {}

/**
 * used to draw the graphical object on the screen
 */
void GraphicObject::draw(GLuint texture, GLuint ShaderProgram) {
	//glEnableVertexAttribArray();
	// TODO : add drawing code
	
	glActiveTexture(GL_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	int texture_location = glGetUniformLocation(ShaderProgram, "myTextureSampler");
	glUniform1i(texture_location, 0);
	glBindTexture(GL_TEXTURE_2D, texture);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glVertexAttribPointer(
		0,			// attribute
		3,			// size
		GL_FLOAT,	// type
		GL_FALSE,	// normalized?
		0,			// stride
		(void*) 0	// array buffer offset
	);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, this->uvBuffer);
	glVertexAttribPointer(
		1,			// attribute
		2,			// size
		GL_FLOAT,	// type
		GL_FALSE,	// normalized
		0,			// stride
		(void*) 0	// array buffer offset
	);

	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	glActiveTexture(GL_TEXTURE);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}
