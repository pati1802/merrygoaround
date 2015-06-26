#include "Shader.hpp"

Shader::Shader(std::string vertexShaderFile, std::string fragmentShaderFile) {
	this->vertexShader = loadShader(vertexShaderFile);
	this->fragmentShader = loadShader(fragmentShaderFile);
}

Shader::Shader(const Shader& other) {

}

Shader::~Shader() {
	
}

std::string Shader::loadShader(std::string shaderFile) {
	/* create input stream & string for shader program */
	std::ifstream file(shaderFile);
	std::string program;
	std::string tmp;

	/* read each line and add it to the program */
	while(std::getline(file, tmp)) {
		program += tmp;
		program.push_back('\n');
	}
	
	return program;
}

void Shader::addShader(std::string shaderCode, GLenum shaderType) {
	/* create shader object */
	GLuint shaderObject = glCreateShader(shaderType);

	if(shaderObject == 0) {
		std::cerr << "Shader | error creating shader object!" << std::endl;
		exit(1);
	}

	/* link shader code to shader object */
	const GLchar *shader = NULL;
	switch(shaderType) {
		default:
			std::cerr << "Shader | unknown shader type!" << std::endl;
			exit(1);
		case GL_VERTEX_SHADER:
			shader = this->vertexShader.data();
			break;
		case GL_FRAGMENT_SHADER:
			shader = this->fragmentShader.data();
			break;
	}
	glShaderSource(shaderObject, 1, &shader, NULL);

	GLint success;
	GLchar infoLog[1024];

	/* Compile shader source */
	glCompileShader(shaderObject);
	glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &success);
	
	if(!success) {
		glGetShaderInfoLog(shaderObject, 1024, NULL, infoLog);
		std::cerr << "Shader | error while compiling shader code: "
			<< shaderType << std::endl << infoLog << std::endl;
		exit(1);
	}
	
	/* attach compiled shader source to shader program */
	glAttachShader(this->shaderProgram, shaderObject);
}

void Shader::createShaderProgram() {
	this->shaderProgram = glCreateProgram();

	if(this->shaderProgram == 0) {
		std::cerr << "Shader | error creating shader program!" << std::endl;
		exit(1);
	}

	addShader(this->vertexShader, GL_VERTEX_SHADER);
	addShader(this->fragmentShader, GL_FRAGMENT_SHADER);

	GLint success = 0;
	GLchar error[1024];
	
	/* link shader code into executable shader program */
	glLinkProgram(this->shaderProgram);
	
	/* check result of linking step */
	glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);

	if(success == 0) {
		glGetProgramInfoLog(this->shaderProgram, sizeof(error), NULL, error);
		std::cerr << "Shader | error while loading shader!" << std::endl;
		std::cerr << error << std::endl;
		exit(1);
	}

	glValidateProgram(this->shaderProgram);
	glGetProgramiv(this->shaderProgram, GL_VALIDATE_STATUS, &success);

	if(!success) {
		glGetProgramInfoLog(this->shaderProgram, sizeof(error), NULL, error);
		std::cerr << "Shader | error while validating shader!" << std::endl;
		std::cerr << error << std::endl;
		exit(1);
	}

	/* put linked shader into drawing pipeline */
	glUseProgram(this->shaderProgram);
}

GLuint Shader::getShaderProgram() {
	return this->shaderProgram;
}
