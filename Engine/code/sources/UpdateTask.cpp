#include "UpdateTask.hpp"

namespace Engine
{
	UpdateTask::UpdateTask(Scene* scene, int priority)
		: Task(priority, scene)
	{
	}

	bool UpdateTask::initialize()
	{
		return false;
	}

	bool UpdateTask::finalize()
	{
		return false;
	}

	bool UpdateTask::do_step(float time)
	{
		return false;
	}
}
