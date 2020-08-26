#include "Entity.hpp"
#include "Component.hpp"
#include "..\headers\Entity.hpp"

namespace Engine
{
    Entity::Entity(string id, Scene * scene, Entity * parent)
        : id(id), scene(scene), parent(parent)
    {
        components = map<string, shared_ptr<Component>>();
    }

    bool Entity::initialize()
    {
        bool result = true;

        for (auto component : components)
        {
            if (component.second->initialize() == false)
            {
                result = false;
            }
        }

        return result;
    }

    bool Entity::add_component(const string& type, shared_ptr< Component > component)
    {
        if (components.count(type) != 0)
        {
            return false;
        }
        else
        {
            if (type == "transform")
            {
                transform = dynamic_pointer_cast<TransformComponent>(component);
            }

            components[type] = component;
            return true;
        }
    }

    string Entity::get_id()
    {
        return id;
    }

    map<string, shared_ptr<Component>> Entity::get_components()
    {
        return components;
    }

    shared_ptr<TransformComponent> Entity::get_transform()
    {
        return transform;
    }

    shared_ptr<Component> Entity::get_component(const string& id)
    {
        if (components[id] != nullptr)
        {
            return components[id];
        }

        return shared_ptr<Component>();
    }

    Entity* Entity::get_parent()
    {
        return parent;
    }
    Scene* Entity::get_scene()
    {
        return scene;
    }

    bool Entity::has_component(const string type)
    {
        return components.find(type) != components.end();
    }
}