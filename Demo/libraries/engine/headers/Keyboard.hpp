// File: Keyboard.hpp
// Author: Pablo Jimeno Domínguez
#pragma once

#ifndef KEYBOARD_HEADER
#define KEYBOARD_HEADER

namespace Engine
{
	class Keyboard
	{
		enum Key
		{
			A, B, C, D,
			E, F, G, H,
			I, J, K, L,
			M, N, O, P,
			Q, R, S, T,
			U, V, W, X,
			Y, Z,

			SPACE,

			K1, K2, K3,
			K4, K5, K6, 
			K7, K8, K9,
			K0
		};

		static Key translate_sdl_key(int sdl_key);
	};
}

#endif // !KEYBOARD_HEADER


