#pragma once

#ifndef TRANSFORM_COMPONENT_HEADER
#define TRANSFORM_COMPONENT_HEADER

#include "Component.hpp"
#include "glm.hpp"

namespace Engine
{
	class TransformComponent : public Component
	{
		glm::mat4 transformation;

		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

	public:

		TransformComponent(shared_ptr<Entity> entity);

		TransformComponent(glm::mat4 & transformation);

		~TransformComponent();

		glm::mat4 get_transformation();

		glm::vec3 get_position();

		virtual bool initialize() override;

		virtual bool parse_property(const string& name, const string& value) override;
	};
}

#endif // !TRANSFORM_COMPONENT_HEADER
