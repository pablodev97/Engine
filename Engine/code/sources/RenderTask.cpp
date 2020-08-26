#include "..\headers\TypeDefinition.hpp"
#include "..\headers\RenderTask.hpp"
#include "RenderTask.hpp"
#include "Scene.hpp"
#include "RenderComponent.hpp"
#include <Model_Obj.hpp>
#include <Render_Node.hpp>

using namespace glt;

namespace Engine
{
	shared_ptr< RenderTask > RenderTask::instance = nullptr;

	RenderTask::RenderTask(Scene* scene, int priority)
		: Task(priority, scene)
	{
		RenderTask::instance = shared_ptr< RenderTask >(this);

		renderer.reset(new glt::Render_Node);
	}

	shared_ptr<glt::Render_Node> RenderTask::get_renderer()
	{
		return renderer;
	}

	bool RenderTask::initialize()
	{
		return true;
	}
	
	bool RenderTask::finalize()
	{
		return true;
	}
	
	bool RenderTask::do_step(float time)
	{
		scene->get_window()->clear();

		renderer->render();
		
		scene->get_window()->swap_buffers();

		return true;
	}
}