#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

extern unsigned int ScreenWidth;
extern unsigned int ScreenHeight;

class Camera
{
private:
	glm::vec3 mCameraPos;
	glm::vec3 mCameraFront;
	glm::vec3 mCameraUp;

	float mCameraSpeed;

	float mPitch;
	float mYaw;

	float mFov;

public:
	Camera();
	~Camera();

	void setCameraPos();
	void setCameraFront();
	void setCameraUp();


	void moveForwardCameraPosition(float deltaTime);
	void moveBackwardCameraPosition(float deltaTime);
	void moveLeftCameraPosition(float deltaTime);
	void moveRightCameraPosition(float deltaTime);

	void stayGround();

	glm::vec3 getCameraPos();
	glm::vec3 getCameraFront();
	glm::vec3 getCameraUp();

	void increaseFov(double xOffeset, double yOffeset);
	void decreaseFov(double xOffeset, double yOffeset);

	float getPitch();
	float getYaw();
	float getFOV();

	void increasePitch(float xOffset, float yOffset);
	void increaseYaw(float xOffset, float yOffset);
	void renewCameraFront(float xOffset, float yOffset);

	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();
};

