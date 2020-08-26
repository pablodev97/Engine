#include "TransformComponent.hpp"
#include "Entity.hpp"
#include <sstream>

namespace Engine
{
	TransformComponent::TransformComponent(shared_ptr<Entity> entity)
		: Component(entity), transformation(nullptr)
	{
		position.x = 0;
		position.y = 0;
		position.z = 0;

		rotation.x = 0;
		rotation.y = 0;
		rotation.z = 0;

		scale = 0;
	}

	TransformComponent::TransformComponent(shared_ptr<glt::Node> transformation)
		: transformation(transformation)
	{		
		
	}

	TransformComponent::~TransformComponent()
	{
	}

	void TransformComponent::set_transform(std::shared_ptr<glt::Node> node) {
		transformation = node;
		transformation->translate(position);
		transformation->rotate_around_x(rotation[0]);
		transformation->rotate_around_y(rotation[1]);
		transformation->rotate_around_z(rotation[2]);
		transformation->scale(scale);
	}

	shared_ptr<glt::Node> TransformComponent::get_transformation()
	{
		return	transformation;
	}

	glm::vec3 TransformComponent::get_position()
	{
		return position;
	}

	void TransformComponent::translate(float translation_x, float translation_y, float translation_z)
	{
		transformation->translate(glt::Vector3(translation_x, translation_y, translation_z));
	}

	void TransformComponent::rotate(float rotation_x, float rotation_y, float rotation_z)
	{
		transformation->rotate_around_x(rotation_x);
		transformation->rotate_around_y(rotation_y);
		transformation->rotate_around_z(rotation_z);
	}

	void TransformComponent::scale_object(float scale)
	{
		transformation->scale(scale);
	}

	bool TransformComponent::initialize()
	{		
		return true;
	}

	bool TransformComponent::parse_property(const string& name, const string& value)
	{
		std::stringstream test(value);
		std::string segment;
		std::vector<std::string> seglist;

		while (std::getline(test, segment, ','))
		{
			seglist.push_back(segment);
		}

		if (name == "position")
		{
			position.x = stof(seglist[0]);
			position.y = stof(seglist[1]);
			position.z = stof(seglist[2]);
		}
		else if (name == "rotation")
		{
			rotation.x = stof(seglist[0]);
			rotation.y = stof(seglist[1]);
			rotation.z = stof(seglist[2]);

		}
		else if (name == "scale")
		{
			scale = stof(seglist[0]);			
		}

		return true;
	}

}
