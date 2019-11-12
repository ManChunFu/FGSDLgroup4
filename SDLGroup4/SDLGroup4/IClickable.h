#pragma once
#include "GameElement.h"
#include <functional>
#include "Text.h"
namespace Engine {
	class IClickable : public GameElement
	{
	public:
		std::function<void()> OnClick;
		
	};
}