#include "PlayerController.hpp"
#include "Entity.hpp"
#include "Scene.hpp"


PlayerController::PlayerController(shared_ptr<Entity> entity)
	: Component(entity)
{
	parent->get_scene()->get_dispatcher()->add("Up", *this);
	parent->get_scene()->get_dispatcher()->add("Down", *this);
	parent->get_scene()->get_dispatcher()->add("Left", *this);
	parent->get_scene()->get_dispatcher()->add("Right", *this);
	speed = 0.1f;

	audio = Audio();
	//id_audio = audio.load_sound("..\\..\\assets\\sounds\\shot");
}

void PlayerController::handle(Message& m)
{
	if (m.get_id() == "Up") 
	{
		parent->get_transform()->translate(0, speed, 0);
	}
	else if (m.get_id() == "Down")
	{
		parent->get_transform()->translate(0, -speed, 0);
	}
	else if (m.get_id() == "Left")
	{
		parent->get_transform()->translate(-speed, 0, 0);
	}
	else if (m.get_id() == "Right")
	{
		parent->get_transform()->translate(speed, 0, 0);
	}

	
}

bool PlayerController::initialize()
{
	return false;
}

bool PlayerController::parse_property(const string& name, const string& value)
{
	return false;
}
