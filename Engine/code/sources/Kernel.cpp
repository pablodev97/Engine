#include "Kernel.hpp"

namespace Engine
{
    Kernel::Kernel()
        : exit(false), tasks{ nullptr }
    {
    }

    Kernel::~Kernel()
    {
        tasks.clear();
    }

    void Kernel::add_task(shared_ptr<Task> task)
    {
        tasks.insert(task);
    }

    void Kernel::execute()
    {
        exit = false;

        for (shared_ptr<Task> task : tasks)
        {
            if(task)
                task->initialize();
        }

        float time = 1.f / 60.f;

        while (!exit)
        {
            for (shared_ptr<Task> task : tasks)
            {
                if (task != nullptr)
                {
                    task->do_step(time);
                }
            }
        }

        for (auto task : tasks)
        {
            if(task)
                task->finalize();
        }
    }

    void Kernel::stop()
    {
        exit = true;
    }
    
    void Kernel::remove_task(shared_ptr<Task> task)
    {
        tasks.erase(task);
    }
}