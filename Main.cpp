/*****************************************************************************
 *	Computer Graphics Proseminar SS 2015
 *	
 *	Authors: Raphael Gruber & Patrick Franz
 *
 ****************************************************************************/
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "GraphicObject.h"

using namespace std;

bool debug = true;

int initialize() {
	if(debug) cout << "initializing ..." << endl;

	glClearColor(0.0, 0.0, 0.0, 0.0); // set color to black (RGBA)
	
	/* enable and use depth functions */
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// TODO : initialize grafical objects here
	// TODO : setup data buffers of all grafical objects

	//createShaderProgram();
	if(debug) cout << "initializing done" << endl;
}

/* what happens before each frame */
void onIdle() {
	
	// TODO : animate graphical objects here

	glutPostRedisplay();
}

void onDisplay() {
	/* reset colors of background buffer */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// TODO : draw graphical objects here

	/* swap forground and background buffers */
	glutSwapBuffers();
}

int main(int argc, char **argv) {
	if(debug) cout << "starting merry-go-around" << endl;
	
	/* initialize glut here */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("merry-go-around v1.0");

	/* initialize glut extension wrangerl */
	GLenum res = glewInit();
	if(res != GLEW_OK) {
		cerr << "glew " << glewGetErrorString(res) << endl;
		exit(-1);
	}
	
	initialize();

	glutIdleFunc(onIdle);
	glutDisplayFunc(onDisplay);

	glutMainLoop();
	
	exit(0);
}
