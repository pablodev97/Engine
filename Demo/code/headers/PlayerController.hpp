// File: PlayerController.hpp
// Author: Pablo Jimeno Domínguez
#pragma once

#include "Observer.hpp"
#include "Component.hpp"
#include "Audio.hpp"

using namespace Engine;

/**
 @brief Clase controladora del jugador
*/
class PlayerController : public Observer, public Component
{
private:

	Audio audio;
	int id_audio;

	/**
	 @brief Velocidad del movimiento
	*/
	float speed;

public:

	/**
	 @brief Crea el componente y recibe una referencia de la entidad jugador
	*/
	PlayerController(shared_ptr<Entity> entity);

	/**
	 @brief Manejador de los mensajes 
	*/
	void handle(Message& m);

	bool initialize();

	bool parse_property(const string& name, const string& value);
};