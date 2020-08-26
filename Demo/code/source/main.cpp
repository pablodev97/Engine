#include <iostream>
#include <memory>
#include "Scene.hpp"
#include "Entity.hpp"
#include "PlayerController.hpp"

#undef main // Ñapa feísima para que funcione el main de windows

using namespace Engine;

int main()
{
	Scene * scene = new Scene("..\\..\\assets\\scene.xml");

	shared_ptr<Entity> player = scene->get_entity("player");
	player->add_component("PlayerController", make_shared<PlayerController>(player));

	scene->execute();

	return 0;
}