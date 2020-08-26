// File: CameraComponent.hpp
// Author: Pablo Jimeno Dom�nguez

#ifndef CAMERA_COMPONENT_HEADER
#define CAMERA_COMPONENT_HEADER

#include <Camera.hpp>
#include "Component.hpp"

namespace Engine
{
	/**
	 @brief Clase que encapsula el componente de la c�mara usando la camara del toolkit
	*/
	class CameraComponent : public Component
	{
		/**
		 @brief Camara
	 	*/
		std::shared_ptr<glt::Camera> camera;

	public:

		/**
		 @brief Contructor que crea el componente y c�mara por defecto
		*/
		CameraComponent(shared_ptr<Entity> parent);

		/**
		 @brief Aplica el transform y se a�ade al render task
		*/
		bool initialize() override;

		/**
		 @brief Setea los valores del XML
		*/
		bool parse_property(const string& name, const string& value) override;
	};
}		

#endif // !CAMERA_COMPONENT_HEADER

