#pragma once
namespace Engine {
	class Vector2D
	{
	public:
		Vector2D(float x, float y) { X = x; Y = y; }
		Vector2D() { X = 0; Y = 0; }
		~Vector2D();
		float X;
		float Y;
	};
}