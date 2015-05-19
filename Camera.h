#pragma once
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>			//OpenGL Mathematics 
#include <glm/gtc/matrix_transform.hpp>

#include "Geometry.h"
class Camera
{
	float _aspectRatio;
	glm::mat4 _projectionMatrix;
	glm::mat4 _viewMatrix;
	float _FOV;
	float _far;
	float _near;
	float _projectionWidth;
	float _projectionHeight;
	glm::vec3 _cameraPos;
	glm::vec3 _cameraFront;
	glm::vec3 _cameraUp;
public:
	Camera();
	~Camera();
	void create(int screenWidth, int screenHeight, bool type, float _near, float _far, float _projectionWidth, float _projectionHeight);
	glm::mat4 returnProjectionMatrix();
	void lookAt();
	//Returns the matrixView
	glm::mat4 returnViewMatrix();
	//Update the camera position
	void updateCameraPosition(float x, float y, float z);
	//Update the CameraFront
	void updateCameraFront(float x, float y, float z);
	//Puts the camera like an FPS
	void cameraSwapFPS(glm::vec3 u);
	void defaultCamera();
	void setCameraPos(vec3 u);
};

