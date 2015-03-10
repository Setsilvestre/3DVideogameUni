#pragma once
#include <glm/glm.hpp>			//OpenGL Mathematics 
#include <glm/gtc/matrix_transform.hpp>

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
	glm::mat4 returnViewMatrix();
	void updateCameraPosition(float x, float y, float z);
	void updateCameraFront(float x, float y, float z);
};

