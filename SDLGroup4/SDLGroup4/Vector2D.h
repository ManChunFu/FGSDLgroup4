#pragma once
namespace Engine {
	class Vector2D
	{
	public:
		Vector2D(float x, float y) { X = x; Y = y; }
		Vector2D() { X = 0; Y = 0; }
		float X;
		float Y;

		Vector2D operator+ (const Vector2D& other) const;
		Vector2D operator- (const Vector2D& other) const;
		Vector2D operator* (const Vector2D& other) const;
		Vector2D operator* (float scalar) const;
		Vector2D operator+= (const Vector2D& other);
		Vector2D operator-= (const Vector2D& other);
		
	};
}