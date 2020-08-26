// This is free code released into the public domain.
// Drafted by Ángel on March 2017.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

// File: Window.hpp
// Author: Pablo Jimeno Domínguez

#pragma once

#include "Task.hpp"
#include "TypeDefinition.hpp"

namespace Engine
{
	/**
	 @brief Clase que encapsula una ventana de SDL
	*/
	class Window
	{
	private:

		/**
		 @brief Ventana de SDL
		*/
		SDL_Window * window;
		/**
		 @brief Contexto de SDL
		*/
		SDL_GLContext gl_context;

		/**
		 @brief Ancho de la ventana
		*/
		int width;
		/**
		 @brief Altura de la ventana
		*/
		int height;

	public:

		/**
		 @brief Constructor de la ventana
		*/
		Window(const std::string& title, int width, int height);

		/**
		 @brief Destructor
		*/
		~Window();

		/**
		 @brief Devuelve el ancho
		*/
		int get_width();

		/**
		 @brief Devuelve la altura
		*/
		int get_height();

		// Encapsulación de métodos de SDL
		
		void set_windowed();

		void set_position(int new_left_x, int new_top_y);

		void set_size(int new_width, int new_height);

		void set_title(const char* title);

		void clear() const;

		void swap_buffers() const;

	};

}
