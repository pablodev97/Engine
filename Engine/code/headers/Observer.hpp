// File: Observer.hpp
// Author: Pablo Jimeno Dom�nguez
#pragma once
#ifndef OBSERVER_HEADER
#define OBSERVER_HEADEr

#include "Message.hpp"

namespace Engine
{
	/**
	 @brief Clase observadora de los mensajes
	*/
	class Observer
	{
	public:

		/**
		 @brief Funci�n que maneja el mensaje
		*/
		virtual void handle(Message& m) = 0;
	};
}

#endif // !OBSERVER_HEADER