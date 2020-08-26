#pragma once

#include "Scene.hpp"

using namespace Engine;

class EngineDemo
{
	Scene * scene;

	EngineDemo()
	{
		scene = new Scene("..\\..\\assets\\scene.xml");
	}

	void run()
	{
		scene->execute();
	}
};