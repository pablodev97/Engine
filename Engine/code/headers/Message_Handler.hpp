// This is free code released into the public domain.
// Drafted by Ángel on April 2017.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

// File: Message_Handler.hpp
// Author: Pablo Jimeno Domínguez

#pragma once

#include "Message.hpp"

namespace Engine
{
    /**
     @brief
    */
    class Message_Handler
    {

        struct Listener
        {
            virtual void handle_message(const Message& message) = 0;
        };

        map< string, list< Listener* > > listeners;

    public:

        void register_listener(const string& message_id, Listener& listener)
        {
            listeners[message_id].push_back(&listener);
        }

        void unregister_listener(const string& message_id, Listener& listener)
        {
            // ...
        }

        // Enviar a todos los listeners.
        void multicast(const Message& message)
        {
            if (listeners.count(message.id) > 0)
            {
                for (auto listener : listeners[message.id])
                {
                    listener->handle_message(message);
                }
            }
        }


    };
}