#pragma once
#include "TypeDefinition.hpp"

// This is free code released into the public domain.
// Drafted by �ngel on March 2017.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

// File: Timer.hpp
// Author: Pablo Jimeno Dom�nguez

#pragma once

#include <SDL.h>
#include <cstdint>

namespace Engine 
{
    class Timer
    {

        uint32_t start_ticks;

    public:


        Timer()
        {
            start();
        }

        void start()
        {
            start_ticks = SDL_GetTicks();
        }

        float elapsed_seconds() const
        {
            return float(elapsed_milliseconds()) / 1000.f;
        }

        uint32_t elapsed_milliseconds() const
        {
            return SDL_GetTicks() - start_ticks;
        }

    };


}