#include "Geometry.h"
#define MAXVERTICES 36
//Constructor
Geometry::Geometry(){
	_data = 0;
}
//Destructor
Geometry::~Geometry(){
	if (_data != 0){
		delete[]_data;
	}
}
/**
* Read a txt file to store and create figures
*/
void Geometry::LoadScene(){
	//Read the txt file
	fstream myfile;
	string line, x, y, z;
	GameElement myElement;
	myfile.open("Vertex.txt", ios::in);
	myfile >> line;
	int lenght;
	lenght = stoi(line);
	//Store the number of figures
	_numberOfPrimitives = lenght;
	//Allocate memory
	_data = new Vertex*[lenght];
	for (int i = 0; i < lenght; i++){
		_data[i] = new Vertex[36*3];
	}
	//Store the transformation data
	for (int i = 0; i < lenght; i++){
		_gameElements.push_back(myElement);
		for (int j = 0; j < 11; j++){
			if (j==0){
				myfile >> line;
				_gameElements[i].idObject = stoi(line);
				if (_gameElements[i].idObject == 0){
					CreateCube(i);
				}
				else if (_gameElements[i].idObject == 1){
					CreateCube(i);
				}
				else if (_gameElements[i].idObject == 2){
					CreateCube(i);
				}
				else if (_gameElements[i].idObject == 3){
					CreatePyramid(i);
				}
			}
			if (j >=1 && j<=3){
				myfile >> x;
				myfile >> y;
				myfile >> z;
				_gameElements[i].translate = glm::vec3(stof(x), stof(y), stof(z));
				j = 3;
			}
			if (j ==4 ){
				myfile >> x;
				_gameElements[i].angle = stof(x);
			}
			if (j>=5 && j<=7 ){
				myfile >> x;
				myfile >> y;
				myfile >> z;
				_gameElements[i].rotate = glm::vec3(stof(x), stof(y), stof(z));
				j = 7;
			}
			if (j >=8 && j<=10 ){
				myfile >> x;
				myfile >> y;
				myfile >> z;
				_gameElements[i].scale = glm::vec3(stof(x), stof(y), stof(z));
				j = 10;
			}
		}
	}
	myfile.close();
}

/**
* Creates the cube data
* @position is the row position in the array
*/
void Geometry::CreateCube(int position){
	_data[position][0].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position ][ 1].setPosition(-1.0f, -1.0f, 1.0f);
	_data[position ][ 2].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position ][ 3].setPosition(1.0f, 1.0f, -1.0f);
	_data[position ][ 4].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position ][ 5].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position ][ 6].setPosition(1.0f, -1.0f, 1.0f);
	_data[position ][ 7].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position ][ 8].setPosition(1.0f, -1.0f, -1.0f);
	_data[position ][ 9].setPosition(1.0f, 1.0f, -1.0f);
	_data[position ][ 10].setPosition(1.0f, -1.0f, -1.0f);
	_data[position ][ 11].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position ][ 12].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position ][ 13].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position ][ 14].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position ][ 15].setPosition(1.0f, -1.0f, 1.0f);
	_data[position ][ 16].setPosition(-1.0f, -1.0f, 1.0f);
	_data[position ][ 17].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position ][ 18].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position ][ 19].setPosition(-1.0f, -1.0f, 1.0f);
	_data[position ][ 20].setPosition(1.0f, -1.0f, 1.0f);
	_data[position ][ 21].setPosition(1.0f, 1.0f, 1.0f);
	_data[position ][ 22].setPosition(1.0f, -1.0f, -1.0f);
	_data[position ][ 23].setPosition(1.0f, 1.0f, -1.0f);
	_data[position ][ 24].setPosition(1.0f, -1.0f, -1.0f);
	_data[position ][ 25].setPosition(1.0f, 1.0f, 1.0f);
	_data[position ][ 26].setPosition(1.0f, -1.0f, 1.0f);
	_data[position ][ 27].setPosition(1.0f, 1.0f, 1.0f);
	_data[position ][ 28].setPosition(1.0f, 1.0f, -1.0f);
	_data[position ][ 29].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position ][ 30].setPosition(1.0f, 1.0f, 1.0f);
	_data[position ][ 31].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position ][ 32].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position ][ 33].setPosition(1.0f, 1.0f, 1.0f);
	_data[position ][ 34].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position ][ 35].setPosition(1.0f, -1.0f, 1.0f);
	if (_gameElements[position].idObject == 0){
		for (int i = 0; i < 36; i++){
			_data[position ][ i].setColor(50, 20, 255, 255);
		}
	}
	else if (_gameElements[position].idObject == 1){
		for (int i = 0; i < 36; i++){
			_data[position ][ i].setColor(255, 20, 50, 255);
		}
	}
	else if (_gameElements[position].idObject == 2){
		for (int i = 0; i < 36; i++){
			_data[position ][ i].setColor(123, 123, 123, 255);
		}
	}
}

/**
* Returns the data in the array row
* @position is the row position
*/
Vertex* Geometry::ReturnData(int position){
	return _data[position];
}

/**
* Returns the scale transformation
* @i is the figure position in the array row
*/
glm::vec3 Geometry::returnScale(int i){
	return _gameElements[i].scale;
}

/**
* Returns the translate transformation
* @i is the figure position in the array row
*/
glm::vec3 Geometry::returnTranslate(int i){
	return _gameElements[i].translate;
}

/**
* Returns the number of figures
*/
int Geometry::returnPrimitives(){
	return _numberOfPrimitives;
}

/**
* Returns the angle transformation
* @i is the figure position in the array row
*/
float Geometry::returnAngle(int i){
	return _gameElements[i].angle;
}

/**
* Returns the rotation transformation
* @i is the figure position in the array row
*/
glm::vec3 Geometry::returnRotate(int i){
	return _gameElements[i].rotate;
}

/**
* Move a specific figure
* @i is the figure position in the array row
* @j is the up/down/right/left key pressed
*/
void Geometry::Move(int i, int j){
	if (j == 0){
		
			_gameElements[i].translate+=glm::vec3(-0.5,0,0);
		
	}
	else if (j == 1){
		
			_gameElements[i].translate += glm::vec3(0.5, 0, 0);
		
	}
	else if (j == 2){
		
			_gameElements[i].translate += glm::vec3(0, 0.5, 0);
		
	}
	else if (j == 3){
		
			_gameElements[i].translate += glm::vec3(0, -0.5, 0);
		
	}
}

void Geometry::MovePlayer(){
	_gameElements[0].translate += glm::vec3(0.0025, 0, 0);
}

/**
* Creates the pyramid data
* @position is the row position in the array
*/
void Geometry::CreatePyramid(int position){
	_data[position][0].setPosition(0.0f, 1.0f, 0.0f);
	_data[position][1].setPosition(1.0f, -1.0f, -1.0f);
	_data[position][2].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][3].setPosition(0.0f, 1.0f, 0.0f);
	_data[position][4].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][5].setPosition(0.0f, -1.0f, 1.0f);
	_data[position][6].setPosition(0.0f, 1.0f, 0.0f);
	_data[position][7].setPosition(0.0f, -1.0f, 1.0f);
	_data[position][8].setPosition(1.0f, -1.0f, -1.0f);
	_data[position][9].setPosition(0.0f, -1.0f, 1.0f);
	_data[position][10].setPosition(1.0f, -1.0f, -1.0f);
	_data[position][11].setPosition(-1.0f, -1.0f, -1.0f);
	for (int i = 0; i < 12; i++){
		_data[position][i].setColor(230, 120, 200, 230);
	}
}

/**
* Creates a random movement
*/
void Geometry::randomMovement(){
	for (int i = 0; i < returnPrimitives(); i++){
		if (_gameElements[i].idObject == 1){
			_gameElements[i].translate += glm::vec3(rand() / (RAND_MAX + 1)*(0.1 - 0.01) - 0.01, rand() / (RAND_MAX + 1)*(0.1 - 0.01) - 0.01, rand() / (RAND_MAX + 1)*(0.1 - 0.01) - 0.01);
		}
	}
}