// File: Dispatcher.hpp
// Author: Pablo Jimeno Domínguez
#pragma once

#include "Message.hpp"
#include "Observer.hpp"
#include "TypeDefinition.hpp"

namespace Engine
{
	class Dispatcher
	{
	private:

		map<string, list<Observer*>> observers;

	public:

		static Dispatcher& instance()
		{
			static Dispatcher dispatcher;
			return dispatcher;
		}

	public:

		void add(const string& id, Observer& observer)
		{
			observers[id].push_back(&observer);
		}

		void remove(const string& id, Observer& observer)
		{
			observers.erase(id);
		}

		void send(const Message& message)
		{
			if (observers.count(message.id) > 0)
			{
				for (auto& listener : observers[message.id])
				{
					listener->handle(message);
				}
			}
		}
	};
}