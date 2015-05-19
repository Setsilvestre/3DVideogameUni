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
	AABB myAABB;
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
		_AABB.push_back(myAABB);
		for (int j = 0; j < 12; j++){
		
			_gameElements[i]._textureRepetion = false;
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
				else if (_gameElements[i].idObject == 4){
					CreateSkyBox(i);
					_gameElements[i]._textureFile = "./resources/textures/galaxy2.jpg";
				}
			}
			if (j >=1 && j<=3){
				myfile >> x;
				myfile >> y;
				myfile >> z;
				_gameElements[i].translate = glm::vec3(stof(x), stof(y), stof(z));
				_AABB[i].center = glm::vec3(stof(x), stof(y), stof(z));
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
				_AABB[i].extent = glm::vec3(stof(x)*2, stof(y)*2, stof(z)*2);
				j = 10;
			}
			if (j == 11){
				myfile >> _gameElements[i]._materialType;
		
			}
		}
	}
	myfile.close();
}

bool Geometry::gettextureRepetion(int i){
	return _gameElements[i]._textureRepetion;
}

GameElement Geometry::getGameElement(int i){
	return _gameElements[i];
}

void Geometry::setTexture(int i, GLuint j){
	_gameElements[i]._textureID = j;
}

void Geometry::CreateSkyBox(int position){
	_data[position][0].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][0].setUV(1.0, 0.0);
	_data[position][0].setNormalVector(glm::normalize(glm::vec3(1, 1, 1)));

	_data[position][1].setPosition(-1.0f, -1.0f, 1.0f);
	_data[position][1].setUV(0.0, 0.0);
	_data[position][1].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f,- 1.0f)));

	_data[position][2].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position][2].setUV(0.0, 1.0);
	_data[position][2].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, -1.0f)));

	_data[position][3].setPosition(1.0f, 1.0f, -1.0f);
	_data[position][3].setUV(1.0, 1.0);
	_data[position][3].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, 1.0f)));

	_data[position][4].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][4].setUV(0.0, 0.0);
	_data[position][4].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f)));

	_data[position][5].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position][5].setUV(0.0, 1.0);
	_data[position][5].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, 1.0f)));

	_data[position][6].setPosition(1.0f, -1.0f, 1.0f);
	_data[position][6].setUV(1.0, 0.0);
	_data[position][6].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, -1.0f)));

	_data[position][7].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][7].setUV(0.0, 1.0);
	_data[position][7].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f)));

	_data[position][8].setPosition(1.0f, -1.0f, -1.0f);
	_data[position][8].setUV(1.0, 1.0);
	_data[position][8].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, 1.0f)));

	_data[position][9].setPosition(1.0f, 1.0f, -1.0f);
	_data[position][9].setUV(1.0, 1.0);
	_data[position][9].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, 1.0f)));

	_data[position][10].setPosition(1.0f, -1.0f, -1.0f);
	_data[position][10].setUV(1.0, 0.0);
	_data[position][10].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, 1.0f)));

	_data[position][11].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][11].setUV(0.0, 0.0);
	_data[position][11].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f)));

	_data[position][12].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][12].setUV(1.0, 0.0);
	_data[position][12].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f)));

	_data[position][13].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position][13].setUV(0.0, 1.0);
	_data[position][13].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, -1.0f)));

	_data[position][14].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position][14].setUV(1.0, 1.0);
	_data[position][14].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, 1.0f)));

	_data[position][15].setPosition(1.0f, -1.0f, 1.0f);
	_data[position][15].setUV(1.0, 0.0);
	_data[position][15].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, -1.0f)));

	_data[position][16].setPosition(-1.0f, -1.0f, 1.0f);
	_data[position][16].setUV(0.0, 0.0);
	_data[position][16].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, -1.0f)));

	_data[position][17].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][17].setUV(0.0, 1.0);
	_data[position][17].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f)));

	_data[position][18].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position][18].setUV(1.0, 1.0);
	_data[position][18].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, -1.0f)));

	_data[position][19].setPosition(-1.0f, -1.0f, 1.0f);
	_data[position][19].setUV(1.0, 0.0);
	_data[position][19].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, -1.0f)));

	_data[position][20].setPosition(1.0f, -1.0f, 1.0f);
	_data[position][20].setUV(0.0, 0.0);
	_data[position][20].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, -1.0f)));

	_data[position][21].setPosition(1.0f, 1.0f, 1.0f);
	_data[position][21].setUV(1.0, 1.0);
	_data[position][21].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));

	_data[position][22].setPosition(1.0f, -1.0f, -1.0f);
	_data[position][22].setUV(0.0, 0.0);
	_data[position][22].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, 1.0f)));

	_data[position][23].setPosition(1.0f, 1.0f, -1.0f);
	_data[position][23].setUV(0.0, 1.0);
	_data[position][23].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, 1.0f)));

	_data[position][24].setPosition(1.0f, -1.0f, -1.0f);
	_data[position][24].setUV(0.0, 0.0);
	_data[position][24].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, 1.0f)));

	_data[position][25].setPosition(1.0f, 1.0f, 1.0f);
	_data[position][25].setUV(1.0, 1.0);
	_data[position][25].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));

	_data[position][26].setPosition(1.0f, -1.0f, 1.0f);
	_data[position][26].setUV(1.0, 0.0);
	_data[position][26].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, -1.0f)));

	_data[position][27].setPosition(1.0f, 1.0f, 1.0f);
	_data[position][27].setUV(1.0, 1.0);
	_data[position][27].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));

	_data[position][28].setPosition(1.0f, 1.0f, -1.0f);
	_data[position][28].setUV(1.0, 0.0);
	_data[position][28].setNormalVector(glm::normalize(glm::vec3(-1.0f,- 1.0f, 1.0f)));

	_data[position][29].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position][29].setUV(0.0, 0.0);
	_data[position][29].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, 1.0f)));

	_data[position][30].setPosition(1.0f, 1.0f, 1.0f);
	_data[position][30].setUV(1.0, 1.0);
	_data[position][30].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));

	_data[position][31].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position][31].setUV(0.0, 0.0);
	_data[position][31].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, 1.0f)));

	_data[position][32].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position][32].setUV(0.0, 1.0);
	_data[position][32].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, -1.0f)));

	_data[position][33].setPosition(1.0f, 1.0f, 1.0f);
	_data[position][33].setUV(0.0, 1.0);
	_data[position][33].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));

	_data[position][34].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position][34].setUV(1.0, 1.0);
	_data[position][34].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, -1.0f)));

	_data[position][35].setPosition(1.0f, -1.0f, 1.0f);
	_data[position][35].setUV(0.0, 0.0);
	_data[position][35].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, -1.0f)));

	for (int i = 0; i < 36; i++){
		_data[position][i].setColor(123, 123, 123, 255);
	}
	_gameElements[position]._textureFile = "./resources/textures/galaxy2.jpg";
	_gameElements[position]._textureID = 2;
}

/**
* Creates the cube data
* @position is the row position in the array
*/
void Geometry::CreateCube(int position){
	_gameElements[position]._textureFile = "./resources/textures/floor.jpg";
	_gameElements[position]._textureID = 1;
	_data[position][0].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][0].setUV(1.0, 0.0);
	_data[position][0].setNormalVector(glm::normalize(glm::vec3(-1, -1, -1)));

	_data[position ][ 1].setPosition(-1.0f, -1.0f, 1.0f);
	_data[position][1].setUV(0.0, 0.0);
	_data[position][1].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, 1.0f)));

	_data[position ][ 2].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position][2].setUV(0.0, 1.0);
	_data[position][2].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, 1.0f)));

	_data[position ][ 3].setPosition(1.0f, 1.0f, -1.0f);
	_data[position][3].setUV(1.0, 1.0);
	_data[position][3].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, -1.0f)));

	_data[position ][ 4].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][4].setUV(0.0, 0.0);
	_data[position][4].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));

	_data[position ][ 5].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position][5].setUV(0.0, 1.0);
	_data[position][5].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, -1.0f)));

	_data[position ][ 6].setPosition(1.0f, -1.0f, 1.0f);
	_data[position][6].setUV(1.0, 0.0);
	_data[position][6].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, 1.0f)));

	_data[position ][ 7].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][7].setUV(0.0, 1.0);
	_data[position][7].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));

	_data[position ][ 8].setPosition(1.0f, -1.0f, -1.0f);
	_data[position][8].setUV(1.0, 1.0);
	_data[position][8].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, -1.0f)));

	_data[position ][ 9].setPosition(1.0f, 1.0f, -1.0f);
	_data[position][9].setUV(1.0, 1.0);
	_data[position][9].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, -1.0f)));

	_data[position ][ 10].setPosition(1.0f, -1.0f, -1.0f);
	_data[position][10].setUV(1.0, 0.0);
	_data[position][10].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, -1.0f)));

	_data[position ][ 11].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][11].setUV(0.0, 0.0);
	_data[position][11].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));

	_data[position ][ 12].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][12].setUV(1.0, 0.0);
	_data[position][12].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));

	_data[position ][ 13].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position][13].setUV(0.0, 1.0);
	_data[position][13].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, 1.0f)));

	_data[position ][ 14].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position][14].setUV(1.0, 1.0);
	_data[position][14].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, -1.0f)));

	_data[position ][ 15].setPosition(1.0f, -1.0f, 1.0f);
	_data[position][15].setUV(1.0, 0.0);
	_data[position][15].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, 1.0f)));

	_data[position ][ 16].setPosition(-1.0f, -1.0f, 1.0f);
	_data[position][16].setUV(0.0, 0.0);
	_data[position][16].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, 1.0f)));

	_data[position ][ 17].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][17].setUV(0.0, 1.0);
	_data[position][17].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));

	_data[position ][ 18].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position][18].setUV(1.0, 1.0);
	_data[position][18].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, 1.0f)));

	_data[position ][ 19].setPosition(-1.0f, -1.0f, 1.0f);
	_data[position][19].setUV(1.0, 0.0);
	_data[position][19].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, 1.0f)));

	_data[position ][ 20].setPosition(1.0f, -1.0f, 1.0f);
	_data[position][20].setUV(0.0, 0.0);
	_data[position][20].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, 1.0f)));

	_data[position ][ 21].setPosition(1.0f, 1.0f, 1.0f);
	_data[position][21].setUV(1.0, 1.0);
	_data[position][21].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f)));

	_data[position ][ 22].setPosition(1.0f, -1.0f, -1.0f);
	_data[position][22].setUV(0.0, 0.0);
	_data[position][22].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, -1.0f)));

	_data[position ][ 23].setPosition(1.0f, 1.0f, -1.0f);
	_data[position][23].setUV(0.0, 1.0);
	_data[position][23].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, -1.0f)));

	_data[position ][ 24].setPosition(1.0f, -1.0f, -1.0f);
	_data[position][24].setUV(0.0, 0.0);
	_data[position][24].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, -1.0f)));

	_data[position ][ 25].setPosition(1.0f, 1.0f, 1.0f);
	_data[position][25].setUV(1.0, 1.0);
	_data[position][25].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f)));

	_data[position ][ 26].setPosition(1.0f, -1.0f, 1.0f);
	_data[position][26].setUV(1.0, 0.0);
	_data[position][26].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, 1.0f)));

	_data[position ][ 27].setPosition(1.0f, 1.0f, 1.0f);
	_data[position][27].setUV(1.0, 1.0);
	_data[position][27].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f)));

	_data[position ][ 28].setPosition(1.0f, 1.0f, -1.0f);
	_data[position][28].setUV(1.0, 0.0);
	_data[position][28].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, -1.0f)));

	_data[position ][ 29].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position][29].setUV(0.0, 0.0);
	_data[position][29].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, -1.0f)));

	_data[position ][ 30].setPosition(1.0f, 1.0f, 1.0f);
	_data[position][30].setUV(1.0, 1.0);
	_data[position][30].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f)));

	_data[position ][ 31].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position][31].setUV(0.0, 0.0);
	_data[position][31].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, -1.0f)));

	_data[position ][ 32].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position][32].setUV(0.0, 1.0);
	_data[position][32].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, 1.0f)));

	_data[position ][ 33].setPosition(1.0f, 1.0f, 1.0f);
	_data[position][33].setUV(0.0, 1.0);
	_data[position][33].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f)));

	_data[position ][ 34].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position][34].setUV(1.0, 1.0);
	_data[position][34].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, 1.0f)));

	_data[position ][ 35].setPosition(1.0f, -1.0f, 1.0f);
	_data[position][35].setUV(0.0, 0.0);
	_data[position][35].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, 1.0f)));


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
			_AABB[i].center += glm::vec3(-0.5, 0, 0);
	}
	else if (j == 1){
		
			_gameElements[i].translate += glm::vec3(0.5, 0, 0);
			_AABB[i].center += glm::vec3(0.5, 0, 0);
	}
	else if (j == 2){
		
			_gameElements[i].translate += glm::vec3(0, 0.5, 0);
			_AABB[i].center += glm::vec3(0, 0.5, 0);
	}
	else if (j == 3){
		
			_gameElements[i].translate += glm::vec3(0, -0.5, 0);
			_AABB[i].center += glm::vec3(0, -0.5, 0);
	}
}

void Geometry::MovePlayer(){
	_gameElements[0].translate += glm::vec3(0.2, 0, 0);
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

void Geometry::moveAll(){
	//care!
	for (int i = 1; i < 7; i++){
		_gameElements[i].translate += glm::vec3(-0.02, 0, 0);
		_AABB[i].center += glm::vec3(-0.02, 0, 0);
	}
	if (_numberOfPrimitives> 8){
		for (int i = 7; i < _numberOfPrimitives; i++){
			_gameElements[i].translate -= glm::vec3(-0.06, 0, 0);
			_AABB[i].center += glm::vec3(-0.06, 0, 0);
		}
	}
}

bool Geometry::OverlapAABB(int one, int two){
	if (abs(_AABB[one].center.x - _AABB[two].center.x) > abs(_AABB[one].extent.x - _AABB[two].extent.x)
		|| abs(_AABB[one].center.y - _AABB[two].center.y) > abs(_AABB[one].extent.y - _AABB[two].extent.y)
		|| abs(_AABB[one].center.z - _AABB[two].center.z) > abs(_AABB[one].extent.z - _AABB[two].extent.z)
		){
		return false;
	}
	else return true;
}

void Geometry::DestroyEnemy(int i){
	_gameElements[i].translate += glm::vec3(0.0, 50.0, 0.0);
	_AABB[i].center += glm::vec3(0.0, 50.0, 0.0);
}

glm::vec3 Geometry::returnPlayerPos(){
	return _gameElements[0].translate;
}

GLuint Geometry::returntextureID(int i){
	return _gameElements[i]._textureID;
}

void Geometry::createBullet(){
	Vertex ** temp;
	temp = new Vertex*[_numberOfPrimitives+1];
	for (int i = 0; i < _numberOfPrimitives+1; i++){
		temp[i] = new Vertex[36 * 3];
	}
	for (int i = 0; i < _numberOfPrimitives; i++){
		temp[i] = _data[i];
	}
	CreateBulletCube(temp, _numberOfPrimitives + 1);

	_data = new Vertex*[_numberOfPrimitives + 1];
	for (int i = 0; i < _numberOfPrimitives + 1; i++){
		_data[i] = new Vertex[36 * 3];
	}
	for (int i = 0; i < _numberOfPrimitives+1; i++){
		_data[i] = temp[i];
	}

	GameElement myElement;
	_gameElements.push_back(myElement);
	
	_gameElements[_numberOfPrimitives].translate = _gameElements[0].translate;
	_gameElements[_numberOfPrimitives].scale = glm::vec3(0.1, 0.1, 0.1);
	_gameElements[_numberOfPrimitives].rotate = glm::vec3(0.0, 0.0, 0.0);
	_gameElements[_numberOfPrimitives].angle = 0;
	_gameElements[_numberOfPrimitives]._textureFile = "./resources/textures/floor.jpg";
	_gameElements[_numberOfPrimitives]._textureRepetion = false;
	_gameElements[_numberOfPrimitives]._materialType = 0;
	AABB myAABB;
	_AABB.push_back(myAABB);
	_AABB[_numberOfPrimitives].center = _gameElements[_numberOfPrimitives].translate;
	_AABB[_numberOfPrimitives].extent = glm::vec3(0.1 * 2, 0.1 * 2, 0.1 * 2);
	_numberOfPrimitives++;

}


void Geometry::CreateBulletCube(Vertex **_data, int position){
	_data[position][0].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][0].setUV(0.0, 0.0);
	_data[position][0].setNormalVector(glm::normalize(glm::vec3(-1, -1, -1)));

	_data[position][1].setPosition(-1.0f, -1.0f, 1.0f);
	_data[position][1].setUV(0.0, 1.0);
	_data[position][1].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, 1.0f)));

	_data[position][2].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position][2].setUV(1.0, 0.0);
	_data[position][2].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, 1.0f)));

	_data[position][3].setPosition(1.0f, 1.0f, -1.0f);
	_data[position][3].setUV(1.0, 1.0);
	_data[position][3].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, -1.0f)));

	_data[position][4].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][4].setUV(1.0, 1.0);
	_data[position][4].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));

	_data[position][5].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position][5].setUV(0.0, 1.0);
	_data[position][5].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, -1.0f)));

	_data[position][6].setPosition(1.0f, -1.0f, 1.0f);
	_data[position][6].setUV(1.0, 1.0);
	_data[position][6].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, 1.0f)));

	_data[position][7].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][7].setUV(0.0, 0.0);
	_data[position][7].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));

	_data[position][8].setPosition(1.0f, -1.0f, -1.0f);
	_data[position][8].setUV(1.0, 0.0);
	_data[position][8].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, -1.0f)));

	_data[position][9].setPosition(1.0f, 1.0f, -1.0f);
	_data[position][9].setUV(1.0, 1.0);
	_data[position][9].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, -1.0f)));

	_data[position][10].setPosition(1.0f, -1.0f, -1.0f);
	_data[position][10].setUV(1.0, 0.0);
	_data[position][10].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, -1.0f)));

	_data[position][11].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][11].setUV(0.0, 0.0);
	_data[position][11].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));

	_data[position][12].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][12].setUV(0.0, 0.0);
	_data[position][12].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));

	_data[position][13].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position][13].setUV(1.0, 0.0);
	_data[position][13].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, 1.0f)));

	_data[position][14].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position][14].setUV(0.0, 1.0);
	_data[position][14].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, -1.0f)));

	_data[position][15].setPosition(1.0f, -1.0f, 1.0f);
	_data[position][15].setUV(0.0, 0.0);
	_data[position][15].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, 1.0f)));

	_data[position][16].setPosition(-1.0f, -1.0f, 1.0f);
	_data[position][16].setUV(1.0, 0.0);
	_data[position][16].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, 1.0f)));

	_data[position][17].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position][17].setUV(0.0, 0.0);
	_data[position][17].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));

	_data[position][18].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position][18].setUV(0.0, 0.0);
	_data[position][18].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, 1.0f)));

	_data[position][19].setPosition(-1.0f, -1.0f, 1.0f);
	_data[position][19].setUV(1.0, 0.0);
	_data[position][19].setNormalVector(glm::normalize(glm::vec3(-1.0f, -1.0f, 1.0f)));

	_data[position][20].setPosition(1.0f, -1.0f, 1.0f);
	_data[position][20].setUV(1.0, 1.0);
	_data[position][20].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, 1.0f)));

	_data[position][21].setPosition(1.0f, 1.0f, 1.0f);
	_data[position][21].setUV(0.0, 0.0);
	_data[position][21].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f)));

	_data[position][22].setPosition(1.0f, -1.0f, -1.0f);
	_data[position][22].setUV(0.0, 1.0);
	_data[position][22].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, -1.0f)));

	_data[position][23].setPosition(1.0f, 1.0f, -1.0f);
	_data[position][23].setUV(1.0, 1.0);
	_data[position][23].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, -1.0f)));

	_data[position][24].setPosition(1.0f, -1.0f, -1.0f);
	_data[position][24].setUV(0.0, 1.0);
	_data[position][24].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, -1.0f)));

	_data[position][25].setPosition(1.0f, 1.0f, 1.0f);
	_data[position][25].setUV(0.0, 0.0);
	_data[position][25].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f)));

	_data[position][26].setPosition(1.0f, -1.0f, 1.0f);
	_data[position][26].setUV(1.0, 1.0);
	_data[position][26].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, 1.0f)));

	_data[position][27].setPosition(1.0f, 1.0f, 1.0f);
	_data[position][27].setUV(1.0, 1.0);
	_data[position][27].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f)));

	_data[position][28].setPosition(1.0f, 1.0f, -1.0f);
	_data[position][28].setUV(1.0, 1.0);
	_data[position][28].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, -1.0f)));

	_data[position][29].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position][29].setUV(0.0, 1.0);
	_data[position][29].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, -1.0f)));

	_data[position][30].setPosition(1.0f, 1.0f, 1.0f);
	_data[position][30].setUV(1.0, 1.0);
	_data[position][30].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f)));

	_data[position][31].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position][31].setUV(0.0, 1.0);
	_data[position][31].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, -1.0f)));

	_data[position][32].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position][32].setUV(0.0, 0.0);
	_data[position][32].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, 1.0f)));

	_data[position][33].setPosition(1.0f, 1.0f, 1.0f);
	_data[position][33].setUV(0.0, 1.0);
	_data[position][33].setNormalVector(glm::normalize(glm::vec3(1.0f, 1.0f, 1.0f)));

	_data[position][34].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position][34].setUV(1.0, 0.0);
	_data[position][34].setNormalVector(glm::normalize(glm::vec3(-1.0f, 1.0f, 1.0f)));

	_data[position][35].setPosition(1.0f, -1.0f, 1.0f);
	_data[position][35].setUV(0.0, 0.0);
	_data[position][35].setNormalVector(glm::normalize(glm::vec3(1.0f, -1.0f, 1.0f)));

		for (int i = 0; i < 36; i++){
			_data[position][i].setColor(50, 20, 255, 255);
		}

}