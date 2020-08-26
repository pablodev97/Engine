// File: Audio.hpp
// Author: Pablo Jimeno Domínguez

#pragma once

#include "TypeDefinition.hpp"
#include <SDL.h>
#include <SDL_mixer.h>

namespace Engine
{
	class Audio
	{

	public:
	
		struct AudioInfo
		{
			Mix_Music* music;
			Mix_Chunk* sound;

			AudioInfo()
			{
				music = nullptr;
				sound = nullptr;
			}

			AudioInfo(Mix_Music* _music)
			{
				music = _music;
			};

			AudioInfo(Mix_Chunk* _sound)
			{
				sound = _sound;
			};
		};

	private:

		map<Id, AudioInfo* > music;
		map<Id, AudioInfo* > sounds;

	public:

		/*
		* Contructor del audio
		*/
		Audio()
		{
			if (SDL_Init(MIX_INIT_OGG | MIX_INIT_MOD) < 0)
			{
				SDL_Log("No se ha podido inicializar SDL2.");
			}
			else {
				if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
				{
					SDL_Log("No se ha podido inicializar el subsistema de audio.");
				}
			}	
		};

		/*
		* Destruye todos los archivos de musica que hemos cargado con anterioridad
		*/
		~Audio() {

			for (auto outer = music.begin(); outer != music.end(); ++outer)
			{
				Mix_FreeMusic(outer->second->music);
			}

			for (auto outer = sounds.begin(); outer != sounds.end(); ++outer)
			{
				Mix_FreeChunk(outer->second->sound);
			}

			Mix_CloseAudio();
		};

		/*
		* Carga una musica y devuelve su Id
		* Busca la ruta desde la carpeta de creacion del proyecto
		*/
		Id load_music(const char* path) {

			Mix_Music* new_music;

			if (new_music = Mix_LoadMUS(path))
			{
				Id id;

				if (music.empty())
				{
					id = 0;
				}
				else
					id = (--music.end())->first + 1;

				music[id] = new AudioInfo(new_music);;

				return id;
			}

			return -1;
		}

		/*
		* Carga una sonido y devuelve su Id
		* Busca la ruta desde la carpeta de creacion del proyecto
		*/
		int load_sound(string path) {

			Mix_Chunk* new_sound;

			if (new_sound = Mix_LoadWAV(path.c_str()))
			{
				Id id;

				if (sounds.empty())
				{
					id = 0;
				}
				else
					id = (--sounds.end())->first + 1;

				sounds[id] = new AudioInfo(new_sound);
				return id;
			}

			return -1;

		}

		/*
		* Comienza una musica
		* Devuelve el canal donde se está ejecutando
		*/
		int start_music(Id id)
		{
			return Mix_FadeInMusic(music[id]->music, -1, 4000);
		}


		/*
		* Comienza un sonido
		* Devuelve el canal donde se está ejecutando
		*/
		int make_sound(Id id)
		{
			return Mix_PlayChannel(-1, sounds[id]->sound, 0);
		}

		/*
		* Para toda la musica
		*/
		void stop_all_music()
		{
			Mix_HaltMusic();
		}

		/*
		* Para una musica segun el id
		*/
		void stop_music_id(Id id)
		{
			Mix_HaltChannel(-1);
		}

		/*
		*  Para todos los sonidos
		*/
		void stop_all_sounds() {

			Mix_HaltChannel(-1);
		}

		/*
		*  Para un sonido en concreto
		*/
		void stop_chanel_id(Id id) {

			Mix_HaltChannel(-1);
		}

	};
}
/*
 * Maneja el audio del motor
 */



