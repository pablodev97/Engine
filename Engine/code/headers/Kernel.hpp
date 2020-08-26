#pragma once
#ifndef KERNEL_HEADER
#define KERNEL_HEADER


#include "TypeDefinition.hpp"

#include "Timer.hpp"
#include "Task.hpp"

class Task;
class Scene;
class Entity;

namespace Engine
{
    /**
     @brief Maneja las tareas 
    */
    class Kernel
    {
        /**
         @brief Set de las tareas
        */
        std::multiset< shared_ptr<Task> > tasks;

        bool exit;

    public:
        
        /**
         @brief Crea el kernel
        */
        Kernel();

        /**
         @brief Destructor
        */
        ~Kernel();

        /**
         @brief Añade una nueva tarea
        */
        void add_task(shared_ptr<Task> task);

        /**
         @brief Elimina una tarea
        */
        void remove_task(shared_ptr<Task> task);

        /**
         @brief Inicializa las tareas y despues las ejecuta en bucle hasta que se indique que salga y finalice las tareas
        */
        void execute();

        /**
         @brief Indica salir del bucle
        */
        void stop();

    };
}

#endif // !KERNEL_HEADER