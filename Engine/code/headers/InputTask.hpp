// File: InputTask.hpp
// Author: Pablo Jimeno Domínguez
#pragma once
#ifndef INPUT_TASK_HEADER
#define INPUT_TASK_HEADER

#include "Task.hpp"
#include "Keyboard.hpp"

namespace Engine
{	
	/**
	 @brief Tarea que maneja el input
	*/
	class InputTask : public Task
	{
		/**
		 @brief Keyboard
		*/
		Keyboard keyboard;

	public:

		/**
		 @brief Constructor con la escena a la que pertenece
		*/
		InputTask(Scene * scene, int priority = 1)
			: Task(priority, scene)
		{
		}

		/**
		 @brief
		*/
		virtual bool initialize() override;

		/**
		 @brief
		*/
		virtual bool finalize() override;

		/**
		 @brief Se comprueban los eventos SDL y se mandan a la escena
		*/
		virtual bool do_step(float time) override;
	};

}

#endif // !INPUT_TASK_HEADER

