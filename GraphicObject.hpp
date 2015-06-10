#ifndef _GRAPHICOBJECT_H_
#define _GRAPHICOBJECT_H_

#include <iostream>
#include <cstring>
#include <vector>

#include "glm/glm.hpp"

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "ObjLoader.hpp"

class GraphicObject {

	private:
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec2> uvs;
		std::vector<glm::vec3> normals;
		GLuint vertexBuffer;
		GLuint uvBuffer;
	public:
		/* default constructor */
		GraphicObject(std::string file);
		/* copy constructor */
		GraphicObject(const GraphicObject& obj);
		/* default destructor */
		virtual ~GraphicObject();
};

#endif
