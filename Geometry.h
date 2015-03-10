#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <glm/glm.hpp>			//OpenGL Mathematics 
#include "Vertex.h"
#include "GameElement.h"
#include <vector>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;

//Class for the managment of the figures
class Geometry
{
	//For the managment of the figure transformations
	vector <GameElement> _gameElements;
	//Vertex to store the vertex information
	Vertex **_data;
	//To store the number of figures
	int _numberOfPrimitives;
public:
	//Constructor
	Geometry();
	//Destructor
	~Geometry();
	//Read the txt file, store and create the figures
	void LoadScene();
	//Create the cube figure
	void CreateCube(int position);
	//Return the figure data
	Vertex* ReturnData(int position);
	//Return the scale transformation
	glm::vec3 returnScale(int i);
	//Return the translate transformation
	glm::vec3 returnTranslate(int i);
	//Return the angle transformation
	float returnAngle(int i);
	//Return the rotate trasnformation
	glm::vec3 returnRotate(int i);
	//Return the number of figures
	int returnPrimitives();
	//Move the Figure
	void Move(int i, int j);
	//Creates the pyramid figure
	void CreatePyramid(int position);
	//Creates a random movement
	void randomMovement();
	void MovePlayer();
};


