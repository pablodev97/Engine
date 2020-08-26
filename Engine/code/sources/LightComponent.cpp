#include "LightComponent.hpp"
#include "Component.hpp"
#include "TransformComponent.hpp"
#include "RenderTask.hpp"
#include "Entity.hpp"
#include <Light.hpp>
#include <Render_Node.hpp>

namespace Engine
{
	LightComponent::LightComponent(shared_ptr<Entity> parent)
		: Component(parent), light(new glt::Light)
	{
	}

	bool LightComponent::initialize()
	{
		TransformComponent* transform = dynamic_cast<TransformComponent*>(parent->get_component("transform").get());
		transform->set_transform(light);
		RenderTask::instance->get_renderer()->add(parent->get_id(), light);

		return true;
	}

	bool LightComponent::parse_property(const string& name, const string& value)
	{

		return true;
	}
}