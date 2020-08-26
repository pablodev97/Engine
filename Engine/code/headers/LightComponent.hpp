#ifndef LIGHT_COMPONENT_HEADER
#define LIGHT_COMPONENT_HEADER

#include "Component.hpp"
#include <Light.hpp>

namespace Engine
{
	/**
	 @brief Componente luz 
	*/
	class LightComponent : public Component
	{
		/**
		 @brief Luz del toolkit
		*/
		shared_ptr<glt::Light> light;

	public:

		/**
		 @brief Crea la luz
		*/
		LightComponent(shared_ptr<Entity> parent);

		/**
		 @brief Aplica el transform a la luz y se añade al render de la escena
		*/
		bool initialize() override;

		/**
		 @brief Establece los valores del XML
		*/
		bool parse_property(const string& name, const string& value) override;
	};
}

#endif //!LIGHT_COMPONENT_HEADER