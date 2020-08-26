// File: Entity.hpp
// Author: Pablo Jimeno Domínguez

#pragma once
#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include "TypeDefinition.hpp"
#include "Component.hpp"
#include "TransformComponent.hpp"

namespace Engine
{
    class Scene;

    /**
     @brief Clase que encapsula una entidad de la escena
    */
    class Entity
    {
        /**
         @brief Entidad padre de esta entidad
        */
        Entity * parent;

        /**
         @brief Id de la entidad
        */
        string id;

        /**
         @brief Escena donde se encuentra la entidad
        */
        Scene * scene;

        /**
         @brief Map de los componentes de la entidad
        */
        map< string, shared_ptr< Component > > components;

        /**
         @brief Transform de la entidad
        */
        shared_ptr<TransformComponent> transform;

    public:

        /**
         @brief Constructor de la entidad
        */
        Entity(string id, Scene * scene, Entity * parent = nullptr);

        /**
         @brief Inicializa todos los componentes
        */
        bool initialize();

        /**
         @brief Añade un nuevo componente
        */
        bool add_component(const string& type, shared_ptr< Component > component);

        /**
         @brief Devuelve el id de la entidad
        */
        string get_id();

        /**
         @brief Devuelve el componente con el id del parámetro
        */
        shared_ptr<Component> get_component(const string& id);

        /**
         @brief Devuelve los componentes de la entidad
        */
        map< string, shared_ptr< Component > > get_components();

        /**
         @brief Devuelve el transform de la entidad
        */
        shared_ptr<TransformComponent> get_transform();

        /**
         @brief Devuelve la entidad padre 
        */
        Entity * get_parent();

        /**
         @brief Devuelve la escena a la que pertenece la entidad
        */
        Scene * get_scene();

        /**
         @brief Comprueba si tiene un tipo de componente
        */
        bool has_component(const string type);

    };
}

#endif // !ENTITY_HEADER