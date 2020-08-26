#include "Window.hpp"
#include <SDL.h>
#include <OpenGL.hpp>
#include "Engine.hpp"

namespace Engine
{
	Window::Window(const std::string& title, int width, int height)
		: width(width), height(height)
	{
		window = nullptr;
		gl_context = nullptr;

		if (initialize(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

			window = SDL_CreateWindow
			(
				title.c_str(),
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				width,
				height,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
			);

			assert(window != nullptr);

			gl_context = SDL_GL_CreateContext(window);

			assert(gl_context != nullptr);

			if (gl_context && glt::initialize_opengl_extensions())
			{

			}
		}


	}

	Window::~Window()
	{
		SDL_GL_DeleteContext(gl_context);
		SDL_DestroyWindow(window);
	}

	void Window::set_windowed()
	{
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
		set_size(width, height);
	}

	int Window::get_width()
	{
		return width;
	}

	int Window::get_height()
	{
		return height;
	}

	void Window::set_position(int new_left_x, int new_top_y)
	{
		SDL_SetWindowPosition(window, new_left_x, new_top_y);
	}

	void Window::set_size(int new_width, int new_height)
	{
		SDL_SetWindowSize(window, new_width, new_height);
	}

	void Window::set_title(const char* title)
	{
		SDL_SetWindowTitle(window, title);
	}

	void Window::clear() const
	{
		if (gl_context)
		{
			glClearColor(0.4f, 0.4f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
	}

	void Window::swap_buffers() const
	{
		if (gl_context) SDL_GL_SwapWindow(window);
	}
}