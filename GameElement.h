#pragma once
#include <glm/glm.hpp>			//OpenGL Mathematics 
struct GameElement {
	glm::fvec3 translate;
	float angle;
	glm::fvec3 rotate;
	glm::fvec3 scale;
	int idObject;
	bool _textureRepetion;			//It is used to force the texture repetition in a geometric model
	GLuint _textureID;				//Identifier that OpenGL has set to its associated texture
	std::string _textureFile;		//This is the path where the texture is stored
	int _materialType;
};