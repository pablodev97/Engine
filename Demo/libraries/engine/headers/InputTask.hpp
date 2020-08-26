// File: InputTask.hpp
// Author: Pablo Jimeno Domínguez
#pragma once
#ifndef INPUT_TASK_HEADER
#define INPUT_TASK_HEADER

#include "Task.hpp"
#include "Keyboard.hpp"

namespace Engine
{	
	class InputTask : public Task
	{
		Keyboard keyboard;

	public:

		InputTask(Scene * scene, int priority = 1)
			: Task(priority, scene)
		{
		}

		virtual bool initialize() override;

		virtual bool finalize() override;

		virtual bool do_step(float time) override;
	};

}

#endif // !INPUT_TASK_HEADER

