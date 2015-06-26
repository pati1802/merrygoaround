#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include <fstream>
#include <streambuf>
#include <cstring>
#include <vector>

#include <GL/glew.h>
#include <GL/freeglut.h>

class Shader {
	private:
		GLuint shaderProgram;
		std::string vertexShader;
		std::string fragmentShader;
		
		void addShader(std::string shaderCode, GLenum shaderType);
		std::string loadShader(std::string shaderFile);
	public:
		/* default constructor */
		Shader(std::string vertexShaderFile, std::string fragmentShaderFile);
		/* copy constructor */
		Shader(const Shader& other);
		/* default destructor */
		virtual ~Shader();

		/* function to create shader program */
		void createShaderProgram();

		/* getters */
		GLuint getShaderProgram();
};

#endif
