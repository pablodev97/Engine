// This is free code released into the public domain.
// Drafted by Ángel on March 2017.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

// File: Window.hpp
// Author: Pablo Jimeno Domínguez

// © Copyright (C) 2019  Pablo Jimeno Domínguez

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#pragma once

#include "Task.hpp"
#include <iostream>
#include <string>
#include <cassert>

namespace Engine
{
	class Window
	{
	private:

		SDL_Window * window;
		SDL_GLContext gl_context;

		int width;
		int height;

	public:

		Window(const std::string& title, int width, int height);

		~Window();

		void set_windowed();

		void set_position(int new_left_x, int new_top_y);

		void set_size(int new_width, int new_height);

		void set_title(const char* title);

	};

}
