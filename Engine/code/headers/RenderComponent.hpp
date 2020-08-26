// File: RenderComponent.hpp
// Author: Pablo Jimeno Domínguez

#ifndef RENDER_COMPONENT_HEADER
#define RENDER_COMPONENT_HEADER

#include <Model_Obj.hpp>
#include <Material.hpp>

#include "Component.hpp"

namespace Engine
{
	/**
	 @brief Componente render de modelos 3D
	*/
	class RenderComponent : public Component
	{
		/**
		 @brief Modelo 
		*/
		shared_ptr<glt::Model_Obj> model = nullptr;

		/**
		 @brief Nombre del modelo
		*/
		string name = nullptr;

	public:

		/**
		 @brief Constructor del componente
		*/
		RenderComponent(shared_ptr<Entity> parent);
		
		/**
		 @brief Constructor del componente con la ruta al modelo que se quiere crear
		*/
		RenderComponent(shared_ptr<Entity> parent, const string & path);

		/**
		 @brief Devuelve el modelo
		*/
		shared_ptr<glt::Model_Obj> get_model();

		/**
		 @brief Devuelve el nombre
		*/
		string get_name();

		/**
		 @brief Aplica el transform al modelo y se añade al render
		*/
		bool initialize() override;

		/**
		 @brief Setea los valores del XML
		*/
		bool parse_property(const string& name, const string& value) override;
	};
}

#endif // !RENDER_COMPONENT_HEADER

