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

    class Scene
    {
        typedef map< string, shared_ptr< Entity > > Entity_Map;

        shared_ptr<Entity_Map> entities;

        shared_ptr<Kernel> kernel;

        shared_ptr<Window> window;

        shared_ptr<Dispatcher> dispatcher;

        shared_ptr<InputTask> input;

    public:

        Scene(const std::string& scene_path);

        ~Scene();

    public:

        shared_ptr<Kernel> get_kernel();

        shared_ptr<Window> get_window();
        
        shared_ptr<Dispatcher> get_dispatcher();

        void load_scene(const string& scene_path);

        void init_kernel();

        void execute();

    };

}
