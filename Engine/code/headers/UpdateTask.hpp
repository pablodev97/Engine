// File: UpdateTask.hpp
// Author: Pablo Jimeno Domínguez

#ifndef UPDATE_TASK_HEADER
#define UPDATE_TASK_HEADER

#include "Task.hpp"

namespace Engine
{
	class UpdateTask : public Task
	{
	public:

		UpdateTask(Scene * scene, int priority = 0);

		bool initialize() override;

		bool finalize() override;

		bool do_step(float time) override;

	};
}

#endif // !UPDATE_TASK_HEADER

