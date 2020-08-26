// File: Component.hpp
// Author: Pablo Jimeno Domínguez

#pragma once
#ifndef COMPONENT_HEADER
#define COMPONENT_HEADER

#include "TypeDefinition.hpp"

namespace Engine
{
    class Entity;

    /**
     @brief Clase base de los componentes de una entidad
    */
    class Component
    {
    protected:

        /**
         @brief Id del componente
        */
        string id;

        /**
         @brief Entidad que lo posee
        */
        shared_ptr<Entity> parent;

    public:

        /**
         @brief Constructor del componente
        */
        Component(shared_ptr<Entity> parent = nullptr);

        /**
         @brief Destructor
        */
        virtual ~Component();

        /**
         @brief Devuelve la entidad padre
        */
        shared_ptr<Entity> get_entity();

        /**
         @brief Función para inicializar los valores del componente
        */
        virtual bool initialize() = 0;

        /**
         @brief Setea los valores del XML
        */
        virtual bool parse_property(const string& name, const string& value) = 0;

    };
}
#endif // !COMPONENT_HEADER