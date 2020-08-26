// File: Dispatcher.hpp
// Author: Pablo Jimeno Domínguez
#pragma once
#ifndef DISPATCHER_HEADER
#define DISPATCHER_HEADER

#include "Message.hpp"
#include "Observer.hpp"
#include "TypeDefinition.hpp"

namespace Engine
{
	/**
	 @brief Clase manejadora de los mensajes
	*/
	class Dispatcher
	{
	private:

		/**
		 @brief Observadores suscritos
		*/
		map<string, list<Observer*>> observers;

	public:

		/**
		 @brief Instancia de la clase
		*/
		static Dispatcher& instance()
		{
			static Dispatcher dispatcher;
			return dispatcher;
		}

	public:

		/**
		 @brief Añade un observador nuevo
		*/
		void add(const string& id, Observer& observer)
		{
			observers[id].push_back(&observer);
		}

		/**
		 @brief Elimina un observador
		*/
		void remove(const string& id, Observer& observer)
		{
			observers.erase(id);
		}

		/**
		 @brief Manda un mensaje a los observadores suscritos al id del mensaje
		*/
		void send(Message& message)
		{
			if (observers.count(message.get_id()) > 0)
			{
				for (auto& listener : observers[message.get_id()])
				{
					listener->handle(message);
				}
			}
		}
	};
}
#endif // !DISPATCHER_HEADER