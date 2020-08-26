// This is free code released into the public domain.
// Drafted by Ángel on April 2017.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

// File: Entity.hpp
// Author: Pablo Jimeno Domínguez

#pragma once
#include "TypeDefinition.hpp"
#include "Component.hpp"
#include "TransformComponent.hpp"

namespace Engine
{
    class Scene;

    class Entity
    {
        Entity * parent;

        string id;

        Scene * scene;

        map< string, shared_ptr< Component > > components;

        shared_ptr<TransformComponent> transform;

    public:

        Entity(string id, Scene * scene, Entity * parent);

        bool initialize();

        bool add_component(const string& type, shared_ptr< Component >& component);

        string get_id();

        shared_ptr<Component> get_component(const string& id);

        map< string, shared_ptr< Component > > get_components();

        shared_ptr<TransformComponent> get_transform();

        Entity * get_parent();

        Scene * get_scene();

    };
}

