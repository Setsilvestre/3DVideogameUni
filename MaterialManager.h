#pragma once
#include <glm/glm.hpp>			//OpenGL Mathematics 
#include <string>

#define COOPER 0
#define SILVER 1 
#define WHITE_RUBBER 2
#define CHROME 3
#define GOLD 4
#define LIGHT 5
#define NUMMATERIALS 6

struct material {
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float shininess;
};

class MaterialManager
{
	material _materialData[NUMMATERIALS];
	std::string _materialType[NUMMATERIALS];
	
public:
	MaterialManager(){

	}
	~MaterialManager(){

	}
	void createMaterialDefinitions(){
		_materialData[0].ambient = glm::vec3(0.19125, 0.0735, 0.0225);
		_materialData[0].diffuse = glm::vec3(0.7038, 0.27048, 0.0828);
		_materialData[0].specular = glm::vec3(0.256777, 0.137622, 0.086014);
		_materialData[0].shininess = 0.1f;
	}
	material getMaterialComponents(int materialID){
		return _materialData[materialID];
	}
	int getMaterialID(std::string materialName){
		for (int i = 0; i < NUMMATERIALS; i++){
			if (_materialType[i] == materialName){
				return i;
			}
		}
	}

	float returnShininess(){
		return _materialData[0].shininess;
	}

	glm::vec3 returnDiffuse(){
		return _materialData[0].diffuse;
	}

	glm::vec3 returnAmbient(){
		return _materialData[0].ambient;
	}

	glm::vec3 returnSpecular(){
		return _materialData[0].specular;
	}
};
