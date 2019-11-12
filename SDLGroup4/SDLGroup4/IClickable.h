#pragma once
#include "GameElement.h"
#include <functional>
namespace Engine {
	class IClickable : public GameElement
	{
	public:
		std::function<void()> OnClick;
	};
}