#pragma once

namespace Engine
{
	class GameElement
	{
	public:
		GameElement() { width = 0; height = 0; xCoordinate = 0; yCoordinate = 0; }
		GameElement(int width, int height, float xCoordinate, float yCoordinate) :
					width(width), height(height), xCoordinate(xCoordinate), yCoordinate(yCoordinate){}

		int width, height;
		float xCoordinate, yCoordinate;
		bool Active = true;
		virtual void UpdatePosition(float xCoordinate, float yCoordinate) {};

		virtual void Render() {};
	};
}
