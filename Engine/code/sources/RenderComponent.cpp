#include "RenderComponent.hpp"
#include "Component.hpp"
#include "TransformComponent.hpp"
#include "RenderTask.hpp"
#include "Entity.hpp"
#include "Scene.hpp"
#include <Render_Node.hpp>

namespace Engine
{
	RenderComponent::RenderComponent(shared_ptr<Entity> parent)
		: Component(parent), name("")
	{
	}

	RenderComponent::RenderComponent(shared_ptr<Entity> parent, const string & path)
		: Component(parent), model(new glt::Model_Obj(path)), name("")
	{
	}

	shared_ptr<glt::Model_Obj> RenderComponent::get_model()
	{
		return model;
	}

	string RenderComponent::get_name()
	{
		return name;
	}

	bool RenderComponent::initialize()
	{
		TransformComponent* transform = dynamic_cast<TransformComponent*>(parent->get_component("transform").get());
		transform->set_transform(model);
		RenderTask::instance->get_renderer()->add(parent->get_id(), model);

		return true;
	}

	bool RenderComponent::parse_property(const string & name, const string & value)
	{
		if (value.empty())
		{
			return false;
		}

		this->name = value;

		string path = "..\\..\\assets\\models\\" + value;
		
		glt::Model_Obj * aux = new glt::Model_Obj(path);
		model.reset(aux);

		return true;
	}

}