// File: Observer.hpp
// Author: Pablo Jimeno Dom�nguez
#pragma once
#include "Message.hpp"

namespace Engine
{
	class Observer
	{
	public:

		virtual void handle(const Message& m) = 0;
	};
}