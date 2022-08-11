#pragma once


#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	unsigned int ID;
	
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	~Shader();
	void use();

	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, bool value) const;
	void setFloat(std::string& name, bool value) const;


};


