// File: RenderTask.hpp
// Author: Pablo Jimeno Domínguez

#ifndef RENDER_TASK_HEADER
#define RENDER_TASK_HEADER

#include "TypeDefinition.hpp"
#include "Task.hpp"

using namespace glt;

namespace Engine
{
	class RenderComponent;

	/**
	 @brief Tarea que se encarga del render
	*/
	class RenderTask : public Task
	{
		/**
		 @brief Renderer
		*/
		shared_ptr< glt::Render_Node > renderer;

	public:

		/**
		 @brief Instacia a la clase
		*/
		static shared_ptr< RenderTask > instance;

		/**
		 @brief Constructor que crea la tarea y el renderer
		*/
		RenderTask(Scene* scene, int priority = 1);

		/**
		 @brief Devuelve el renderer
		*/
		shared_ptr<glt::Render_Node> get_renderer();

		/**
		 @brief
		*/
		bool initialize() override;

		/**
		 @brief
		*/
		bool finalize() override;

		/**
		 @brief Limpia y pinta la ventana
		*/
		bool do_step(float time) override;
	};
}

#endif // !RENDER_TASK_HEADER

