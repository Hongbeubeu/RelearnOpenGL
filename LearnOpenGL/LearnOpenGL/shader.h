#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h> // include glad to get all the required OpenGL header
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class shader
{
public:
	// the program ID
	unsigned int ID;

	// constructor reads and builds the shader
	shader(const char* vertexPath, const char* fragmentPath);
	// use/activate the shader
	void use();
	// Utility uniform functions
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;

private:
	void checkCompileErrors(unsigned int shader, std::string type);
};

#endif