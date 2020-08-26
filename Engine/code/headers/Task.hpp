// File: Task.hpp
// Author: Pablo Jimeno Domínguez

#ifndef TASK_HEADER
#define TASK_HEADER

#include "TypeDefinition.hpp"

namespace Engine 
{
    class Scene;

    /**
     @brief Clase base de las tareas
    */
    class Task
    {

    protected:

        /**
         @brief Prioridad de la tarea
        */
        int priority;

        /**
         @brief Escena que contiene la tarea
        */
        Scene * scene;

    public:

        /**
         @brief Constructor de la tarea
        */
        Task(int priority, Scene * scene);

        /**
         @brief Destructor
        */
        virtual ~Task();

        /**
         @brief Setea la prioridad
        */
        void set_priority(int priority);
        
        /**
         @brief Devuelve la prioridad
        */
        int get_priority() const;

        /**
         @brief Setea la escena
        */
        void set_scene(Scene* scene);

        /**
         @brief Devuelve la escena
        */
        Scene * get_scene();

    public:

        /**
         @brief Inicializa los valores de la tarea
        */
        virtual bool initialize() = 0;
        /**
         @brief Finaliza la tarea
        */  
        virtual bool finalize() = 0;
        /**
         @brief Ejecuta la tarea
        */
        virtual bool do_step(float time) = 0;

    public:

        bool operator < (const Task& other);

    };

}

#endif // !TASK_HEADER