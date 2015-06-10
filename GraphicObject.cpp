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
	for(glm::vec3 vertex : obj.vertices) {
		glm::vec3 *tmp = new glm::vec3;;
		tmp = &vertex;
		vertices.push_back(*tmp);
	}
}

/**
 * used to delete one object from memory
 */
GraphicObject::~GraphicObject() {}

