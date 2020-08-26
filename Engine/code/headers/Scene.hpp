// This is free code released into the public domain.
// Drafted by Ángel on April 2017.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

// File: Scene.hpp
// Author: Pablo Jimeno Domínguez

#pragma once

#include "TypeDefinition.hpp"

#include "Window.hpp"
#include "Entity.hpp"
#include "Dispatcher.hpp"

namespace Engine
{
    class Kernel;
    class InputTask;
    class RenderTask;

    /**
     @brief Clase que encapsula una escena
    */
    class Scene
    {

        typedef map< string, shared_ptr< Entity > > Entity_Map;

        /**
         @brief Map de las entidades de la escena
        */
        shared_ptr<Entity_Map> entities;

        /**
         @brief Kernel que maneja las tareas
        */
        shared_ptr<Kernel> kernel;

        /**
         @brief Ventana de la escena
        */
        shared_ptr<Window> window;

        /**
         @brief Manejador de los mensajes
        */
        shared_ptr<Dispatcher> dispatcher;

        /**
         @brief Tarea que maneja el input
        */
        shared_ptr<InputTask> input;

        /**
         @brief Tarea que maneja el render
        */
        shared_ptr<RenderTask> render;

    public:

        /**
         @brief Constructor con la ruta al archivo XML donde se establecen todos los valores
        */
        Scene(const std::string& scene_path);

        /**
         @brief Destructor
        */
        ~Scene();

    public:

        /**
         @brief Devuelve el kernel de la escena
        */
        shared_ptr<Kernel> get_kernel();

        /**
         @brief Devuelve la ventana
        */
        shared_ptr<Window> get_window();
        
        /**
         @brief Devuelve el dispatcher
        */
        shared_ptr<Dispatcher> get_dispatcher();

        /**
         @brief Devuelve la tarea que coincida con el nombre recibido por parámetro
        */
        shared_ptr<Task> get_task(const string& name);
        
        /**
         @brief Devuelve la entidad que coincida con el nombre recibido por parámetro
        */
        shared_ptr<Entity> get_entity (const string& name);

        /**
         @brief Carga la escena con los valores del XML
        */
        void load_scene(const string& scene_path);

        /**
         @brief Inicializa las tareas
        */
        void init_kernel();

        /**
         @brief Ejecuta el kernel
        */
        void execute();

    };

}
