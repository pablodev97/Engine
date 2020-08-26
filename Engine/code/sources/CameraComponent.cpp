#include "Component.hpp"
#include "CameraComponent.hpp"
#include "TransformComponent.hpp"
#include "RenderTask.hpp"
#include "Entity.hpp"
#include <Camera.hpp>
#include <Render_Node.hpp>

namespace Engine
{
	CameraComponent::CameraComponent(shared_ptr<Entity> parent)
		: Component(parent), camera(new glt::Camera(20.f, 1.f, 50.f, 1.f))
	{
	}

	bool CameraComponent::initialize()
	{
		TransformComponent* transform = dynamic_cast<TransformComponent*>(parent->get_component("transform").get());
		transform->set_transform(camera);
		RenderTask::instance->get_renderer()->add(parent->get_id(), camera);
		RenderTask::instance->get_renderer()->set_active_camera(parent->get_id());

		return true;
	}

	bool CameraComponent::parse_property(const string& name, const string& value)
	{
		if (name == "fov")
			camera->set_fov(stof(value));
		else if (name == "near")
			camera->set_near(stof(value));
		else if (name == "far")
			camera->set_far(stof(value));
		else if (name == "aspect_ratio")
			camera->set_aspect_ratio(stof(value));

		return true;
	}
}