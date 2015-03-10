#pragma once
#include <glm/glm.hpp>			//OpenGL Mathematics 
struct GameElement {
	glm::fvec3 translate;
	float angle;
	glm::fvec3 rotate;
	glm::fvec3 scale;
	int idObject;
};