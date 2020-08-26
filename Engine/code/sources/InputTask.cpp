#include <SDL.h>
#include "InputTask.hpp"
#include "Scene.hpp"
#include "Kernel.hpp"
#include "Message.hpp"
#include "Keyboard.hpp"

namespace Engine
{
	bool InputTask::initialize()
	{
		return true;
	}

	bool InputTask::finalize()
	{
		return true;
	}

	bool InputTask::do_step(float time)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event) > 0)
		{
			if (event.type == SDL_QUIT)
			{
				scene->get_kernel()->stop();
			}
			else if (event.type == SDL_KEYDOWN)
			{

				if (keyboard.translate_sdl_key(event.key.keysym.sym) == Keyboard::Key::W)
				{
					Message message("Up");
					message.add_parameter("Up", keyboard.translate_sdl_key(event.key.keysym.sym));
					scene->get_dispatcher()->send(message);
				}
				else if (keyboard.translate_sdl_key(event.key.keysym.sym) == Keyboard::Key::S)
				{
					Message message("Down");
					message.add_parameter("Down", keyboard.translate_sdl_key(event.key.keysym.sym));
					scene->get_dispatcher()->send(message);
				}
				else if (keyboard.translate_sdl_key(event.key.keysym.sym) == Keyboard::Key::A)
				{
					Message message("Left");
					message.add_parameter("Left", keyboard.translate_sdl_key(event.key.keysym.sym));
					scene->get_dispatcher()->send(message);
				}
				else if (keyboard.translate_sdl_key(event.key.keysym.sym) == Keyboard::Key::D)
				{
					Message message("Right");
					message.add_parameter("Right", keyboard.translate_sdl_key(event.key.keysym.sym));
					scene->get_dispatcher()->send(message);
				}
				
			}
			
		}

		return true;
	}
}