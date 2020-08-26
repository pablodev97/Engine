// File: Timer.hpp
// Author: Pablo Jimeno Domínguez

#pragma once

#include "TypeDefinition.hpp"
#include <SDL.h>
#include <cstdint>

namespace Engine 
{
    /**
     @brief Clase creada para el tiempo del engine
    */
    class Timer
    {

        /**
         @brief Ticks iniciales
        */
        uint32_t start_ticks;

    public:

        /**
         @brief Constructor
        */
        Timer()
        {
            start();
        }

        /**
         @brief Establece los ticks iniciales
        */
        void start()
        {
            start_ticks = SDL_GetTicks();
        }

        /**
         @brief Obtiene los segundos transcurridos entre frames
        */
        float elapsed_seconds() const
        {
            return float(elapsed_milliseconds()) / 1000.f;
        }

        /**
         @brief Obtiene los milisegundos transcurridos entre frames
        */
        uint32_t elapsed_milliseconds() const
        {
            return SDL_GetTicks() - start_ticks;
        }

    };


}