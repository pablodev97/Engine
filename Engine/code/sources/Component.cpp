#include "Component.hpp"

namespace Engine
{
    Component::Component(shared_ptr<Entity> parent) : parent(parent)
    {
    }

    Component::~Component()
    {
    }

    shared_ptr<Entity> Component::get_entity()
    {
        return parent;
    }

}