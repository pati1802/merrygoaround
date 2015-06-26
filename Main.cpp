/*****************************************************************************
 *	Computer Graphics Proseminar SS 2015
 *	
 *	Authors: Raphael Gruber & Patrick Franz
 *
 ****************************************************************************/
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "GraphicObject.hpp"
#include "Shader.hpp"

#ifndef DEBUG
#define DEBUG true
#endif

using namespace std;

/**
 * Global Variables
 */
vector<GraphicObject*> gObjects;

GLuint programID;
GLuint MatrixID;

glm::mat4 ProjectionMatrix;
glm::mat4 ViewMatrix;
glm::mat4 ModelMatrix;

/**
 * Function to initialize the open gl program
 */
int initialize() {
	if(DEBUG) cout << "Main | initializing ..." << endl;

	if(DEBUG) cout << "Main | clearing color space ... ";
	glClearColor(0.0, 0.0, 0.0, 0.0); // set color to black (RGBA)
	if(DEBUG) cout << "done" << endl;
	
	/* enable and use depth functions */
	if(DEBUG) cout << "Main | enabling depth functions ... ";
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	if(DEBUG) cout << "done" << endl;

	/* loading objects from .obj files to program */
	if(DEBUG) cout << "Main | start loading objects ... ";
	gObjects.push_back(new GraphicObject("obj/cube.obj"));
	if(DEBUG) cout << "Main | done loading objects" << endl;
	
	/* loading shader programs */
	if(DEBUG) cout << "Main | initializing shaders ... ";
	programID = LoadShaders("TransformVertexShader.vertexshader",
		"TextureFragmentShader.fragmentshader");
	if(DEBUG) cout << "done" << endl;
	
	if(DEBUG) cout << "Main | initializing matricies ... ";
	ProjectionMatrix = glm::perspective(45.0f, 4.0f/3.0f, 0.1f, 100.0f);
	ViewMatrix = glm::lookAt(
		glm::vec3(4,3,-3),
		glm::vec3(0,0,0),
		glm::vec3(0,1,0));
	ModelMatrix = glm::mat4(1.0f);
	MatrixID = glGetUniformLocation(programID, "MVP");
	if(DEBUG) cout << "done" << endl;

	//createShaderProgram();
	if(DEBUG) cout << "Main | initializing done" << endl;
}

/* what happens before each frame */
void onIdle() {
	
	// TODO : animate graphical objects here

	glutPostRedisplay();
}

/* how should everything be displayed */
void onDisplay() {
	/* reset colors of background buffer */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

	/* call drawing functions for each object */
	for(int i = 0; i < gObjects.size(); i++) {
		gObjects.at(i)->draw();
	}

	/* swap forground and background buffers */
	glutSwapBuffers();
}

int main(int argc, char **argv) {
	if(DEBUG) cout << "starting merry-go-around" << endl;
	
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
