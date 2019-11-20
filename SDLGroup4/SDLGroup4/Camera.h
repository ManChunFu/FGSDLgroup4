#pragma once
#include "Vector2D.h"
namespace Engine 
{
	class Camera 
	{
	public:
		Camera() {};
		virtual ~Camera(){}
		static Camera* ActiveCamera;
		Engine::Vector2D Position;
	};
}