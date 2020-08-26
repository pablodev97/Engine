// File: Audio.hpp
// Author: Pablo Jimeno Domínguez

#ifndef INPUT_HEADER
#define INPUT_HEADER

#include "Task.hpp"
#include "Window.hpp"

namespace Engine
{
	class Input : public Task
	{
	public:

		Input(int priority) : Task(priority)
		{

		}

		void initialize() override
		{

		}

		void finalize() override
		{

		}

		void do_step(float time)  override
		{
			Window:
		}
	};	
}

#endif // !INPUT_HEADER


#pragma once
