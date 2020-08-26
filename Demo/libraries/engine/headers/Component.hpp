// File: Component.hpp
// Author: Pablo Jimeno Domínguez

#pragma once
#include "TypeDefinition.hpp"

namespace Engine
{
    class Entity;

    /*
    * Es mas un modelo de datos que de otra cosa
    * Diferencian las entidades
    */
    class Component
    {
    protected:

        string id;

        shared_ptr<Entity> parent;

    public:

        Component(shared_ptr<Entity> parent = nullptr);

        virtual ~Component();

        shared_ptr<Entity> get_entity();

        virtual bool initialize() = 0;

        virtual bool parse_property( const string& name, const string& value) = 0;

        virtual void suscribe_to_task() {}

    };
}
