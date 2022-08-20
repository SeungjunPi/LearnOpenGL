#include "Camera.h"




Camera::Camera() :
	mPitch(0.0f),
	mYaw(-89.0f),
	mFov(45.0f),
	mCameraPos(glm::vec3(0.0f, 0.0f, 3.0f)),
	mCameraFront(glm::vec3(0.0f, 0.0f, -1.0f)),
	mCameraUp(glm::vec3(0.0f, 1.0f, 0.0f)),
	mCameraSpeed(2.5f)
{

}

Camera::~Camera()
{

}

void Camera::setCameraPos()
{
	
}


void Camera::moveForwardCameraPosition(float deltaTime)
{
	mCameraPos += deltaTime * mCameraSpeed * mCameraFront;
}

void Camera::moveBackwardCameraPosition(float deltaTime)
{
	mCameraPos -= deltaTime * mCameraSpeed * mCameraFront;
}

void Camera::moveLeftCameraPosition(float deltaTime)
{
	mCameraPos -= deltaTime * mCameraSpeed * glm::normalize(glm::cross(mCameraFront, mCameraUp));
}

void Camera::moveRightCameraPosition(float deltaTime)
{
	mCameraPos += deltaTime * mCameraSpeed * glm::normalize(glm::cross(mCameraFront, mCameraUp));
}

void Camera::stayGround()
{
	mCameraPos.y = 0.0f;
}

void Camera::setCameraFront()
{

}

void Camera::setCameraUp()
{

}

glm::vec3 Camera::getCameraPos()
{

}

glm::vec3 Camera::getCameraFront()
{

}

glm::vec3 Camera::getCameraUp()
{

}

float Camera::getPitch()
{

}

float Camera::getYaw()
{

}

float Camera::getFOV()
{


}

void Camera::increaseFov(double xOffset, double yOffset)
{
	if (mFov >= 1.0f && mFov <= 45.0f)
		mFov -= yOffset;
	if (mFov <= 1.0f)
		mFov = 1.0f;
	if (mFov >= 45.0f)
		mFov = 45.0f;
}

void Camera::renewCameraFront(float xOffset, float yOffset)
{
	mYaw += xOffset;
	mPitch += yOffset;
	if (mPitch > 89.0f)
	{
		mPitch = 89.0f;
	}

	if (mPitch < -89.0f)
	{
		mPitch = -89.0f;
	}

	glm::vec3 front;
	front.x = cos(glm::radians(mPitch)) * cos(glm::radians(mYaw));
	front.y = sin(glm::radians(mPitch));
	front.z = cos(glm::radians(mPitch)) * sin(glm::radians(mYaw));
	mCameraFront = glm::normalize(front);
}


glm::mat4 Camera::getViewMatrix()
{
	return glm::lookAt(mCameraPos, mCameraFront + mCameraPos, mCameraUp);
}

glm::mat4 Camera::getProjectionMatrix()
{
	return glm::perspective(glm::radians(mFov), (float)ScreenWidth / (float)ScreenHeight, 0.1f, 100.0f);
}





