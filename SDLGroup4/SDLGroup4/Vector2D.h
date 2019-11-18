#pragma once

namespace Engine {
	class Vector2D
	{
	public:
		Vector2D(float x, float y) { X = x; Y = y; }
		Vector2D() { X = 0; Y = 0; }
		float X = 0.0f;
		float Y = 0.0f;

		friend Vector2D operator-(Vector2D leftSide, const Vector2D& rightSide)
		{
			leftSide.X -= rightSide.X;
			leftSide.Y -= rightSide.Y;
			return leftSide;			
		}	

		friend Vector2D operator+(Vector2D leftSide, const Vector2D& rightSide)
		{
			leftSide.X += rightSide.X;
			leftSide.Y += rightSide.Y;
			return leftSide;
		}
		
	};
}