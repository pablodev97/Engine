// File: Message.hpp
// Author: Pablo Jimeno Domínguez

#pragma once
#ifndef MESSAGE_HEADER
#define MESSAGE_HEADER

#include "TypeDefinition.hpp"
#include "Variant.hpp"

namespace Engine
{
    /**
     @brief Clase mensaje del sistema de mensajería
    */
    class Message
    {
        /**
         @brief Id del mensaje
        */
        string id;

        /**
         @brief Map con los parámetros del mensaje
        */
        map< string, Variant > parameters;

    public:

        /**
         @brief Constructor del mensaje
        */
        Message(const string& id) : id(id)
        {
        }

        /**
         @brief Añade un parámetro al mensaje
        */
        void add_parameter(const string& name, const Variant& value)
        {
            parameters[name] = value;
        }

        /**
         @brief Devuelve el id del mensaje
        */
        const string get_id()
        {
            return id;
        }
    };

}

#endif // !MESSAGE_HEADER