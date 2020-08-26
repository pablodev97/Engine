#include "Task.hpp"

namespace Engine
{
	Task::Task(int priority, Scene* scene) 
		: priority(priority), scene(scene)
	{
	}

	Task::~Task()
	{
	}

	void Task::set_priority(int priority)
	{
		this->priority = priority;
	}

	int Task::get_priority() const
	{
		return priority;
	}

	void Task::set_scene(Scene* scene)
	{
		this->scene = scene;
	}

	Scene* Task::get_scene()
	{
		return scene;
	}

	bool Task::operator < (const Task& other)
	{
		return priority < other.get_priority();
	}
}