// File: Audio.hpp
// Author: Pablo Jimeno Domínguez

#ifndef AUDIO_HEADER
#define AUDIO_HEADER


#include "TypeDefinition.hpp"
#include <SDL.h>
#include <SDL_mixer.h>

namespace Engine
{
	/**
	 @brief Clase que encapsula el funcionamiento del audio
	*/
	class Audio
	{

	public:
	
		/**
		 @brief Struct que contiene la info del audio
		*/
		struct AudioInfo
		{
			/**
			 @brief Musica
			*/
			Mix_Music* music;
			/**
			 @brief Sonido
			*/
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

		/**
		 @brief Map con la música
		*/
		map<Id, AudioInfo* > music;
		/**
		 @brief Map con los sonidos
		*/
		map<Id, AudioInfo* > sounds;

	public:

		/**
		 @brief Contructor del audio
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

		/**
		 @brief Destruye los audios cargados
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

		/**
		 @brief Carga la música y devuelve su id
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

		/**
		 @brief Carga un sonido y devuelve su id
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

		/**
		 @brief Comienza la música con el id que se obtiene por parámetro
		*/
		int start_music(Id id)
		{
			return Mix_FadeInMusic(music[id]->music, -1, 4000);
		}


		/**
		 @brief Comienza el sonido con el id que se obtiene por parámetro
		*/
		int make_sound(Id id)
		{
			return Mix_PlayChannel(-1, sounds[id]->sound, 0);
		}

		/**
		 @brief Para toda la música
		*/
		void stop_all_music()
		{
			Mix_HaltMusic();
		}

		/**
		 @brief Para todos los sonidos
		*/
		void stop_all_sounds() {

			Mix_HaltChannel(-1);
		}

	};
}

#endif //!AUDIO_HEADER