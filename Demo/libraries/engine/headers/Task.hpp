// This is free code released into the public domain.
// Drafted by Ángel on April 2017.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

// File: Task.hpp
// Author: Pablo Jimeno Domínguez

#pragma once
#include "TypeDefinition.hpp"


namespace Engine 
{
    class Scene;

    // Tareas consumibles o no consumibles
    // Secuancia de tareas (hereda de task y tiene una lista de tasks)
    class Task
    {

    protected:

        int priority;

        Scene * scene;

    public:

        Task(int priority, Scene * scene);

        virtual ~Task();

        void set_priority(int priority);
        
        int get_priority() const;

        void set_scene(Scene* scene);

        Scene * get_scene();

    public:

        virtual bool initialize() = 0;
        virtual bool finalize() = 0;
        virtual bool do_step(float time) = 0;

    public:

        bool operator < (const Task& other);

    };

}