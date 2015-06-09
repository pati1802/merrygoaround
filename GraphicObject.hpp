#ifndef _GRAPHICOBJECT_H_
#define _GRAPHICOBJECT_H_

#include <cstring>

#include <GL/glew.h>
#include <GL/freeglut.h>

class GraphicObject {

	private:
		GLfloat *vertexBuffer;
		GLfloat *indexBuffer;
	public:
		/* default constructor */
		GraphicObject();
		/* copy constructor */
		GraphicObject(const GraphicObject& obj);
		/* default destructor */
		virtual ~GraphicObject();
};

#endif
