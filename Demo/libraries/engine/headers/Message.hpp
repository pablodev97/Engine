// File: Message.hpp
// Author: Pablo Jimeno Domínguez

#pragma once
#include "TypeDefinition.hpp"
#include "Variant.hpp"

namespace Engine
{
    struct Message
    {

        string id;

        map< string, Variant > parameters;

        Message(const string& id) : id(id)
        {
        }

        void add_parameter(const string& name, const Variant& value)
        {
            parameters[name] = value;
        }

        const string get_id()
        {
            return id;
        }
    };

}
