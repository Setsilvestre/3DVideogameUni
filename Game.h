#pragma once


//Third-party libraries
#include <GL/glew.h>			//The OpenGL Extension Wrangler
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>			//OpenGL Mathematics 
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <time.h>
#include "Window.h"
#include "GLSLProgram.h"
#include "FPSLimiter.h"
#include "OpenGLBuffers.h"
#include "Vertex.h"
#include "Geometry.h"
#include "Camera.h"
#include "TextureManager.h"
#include "MaterialManager.h"

#define ORIGINAL_COLOR 0
#define TEXTURE_COLOR 1
#define COMBINED_COLOR 2
#define DRAW_MODE 3

#define MAX_VERTICES 36

//Game has three possible states: INIT (Preparing environment), PLAY (Playing) or EXIT (Exit from the game)
enum class GameState{INIT, PLAY, EXIT};

//This class manages the game execution
class Game {
	public:						
		Game(std::string windowTitle, int screenWidth, int screenHeight, bool enableLimiterFPS, int maxFPS, bool printFPS);	//Constructor
		~Game();					//Destructor
		void run();					//Game execution
		double timer = 0;			//Time flow
		double start = 0;
	private:
			//Attributes	
		int _drawMode;					//Define how the color is computed
		std::string _windowTitle;		//Window Title
		int _screenWidth;				//Screen width in pixels				
		int _screenHeight;				//Screen height in pixels				
		GameState _gameState;			//It describes the game state				
		Window _window;					//Manage the OpenGL context
		GLSLProgram _colorProgram;		//Manage the shaders
		FPSLimiter _fpsLimiter;			//Manage the synchronization between frame rate and refresh rate
		OpenGLBuffers _openGLBuffers;	//Manage the openGL buffers
		Geometry _myGeometry;			//Manage the Figures
		Camera _camera;					//Manage the camera
		TextureManager _textureManager;	//Manage all the data related to the different textures used in the game
		MaterialManager _materialManager; //Manager of the materials
		int lightENable=0;
			//Internal methods
		void initSystems();
		void loadShaders();		
		void createPrimitivesToRender();
		void gameLoop();
		void processInput();
		void updateGameObjects();
		void drawGame();	
		void loadGameTextures();
		
};

