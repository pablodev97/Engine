#pragma once
#include "TypeDefinition.hpp"

#include "Timer.hpp"
#include "Task.hpp"

class Task;
class Scene;
class Entity;

namespace Engine
{
    class Kernel
    {
        std::multiset< shared_ptr<Task> > tasks;

        bool exit;

    public:

        Kernel();

        ~Kernel();

        void add_task(shared_ptr<Task> task);

        void remove_task(shared_ptr<Task> task);

        void execute();

        void stop();

    };
}
