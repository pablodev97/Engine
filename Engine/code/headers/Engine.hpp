#ifndef ENGINE_HEADER
#define ENGINE_HEADER

#include <SDL.h>
#include <cstdlib>

namespace Engine
{
    /**
     @brief Funci�n que inicializa SDL
    */
    bool initialize(int subsystem)
    {
        // Se hace que al salir de la funci�n main() se invoque autom�ticamente
        // a la funci�n finalize() una vez:

        static bool finalize_is_not_set = true;

        if (finalize_is_not_set)
        {
            finalize_is_not_set = false;

            std::atexit(SDL_Quit);
        }

        // Se inicializa el subsistema si no estaba inicializado:

        if (!SDL_WasInit(subsystem))
        {
            return SDL_Init(subsystem) == 0;
        }

        return true;
    }
}

#endif // !ENGINE_HEADER
