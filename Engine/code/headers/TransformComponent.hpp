#pragma once

#ifndef TRANSFORM_COMPONENT_HEADER
#define TRANSFORM_COMPONENT_HEADER

#include <glm/glm.hpp>
#include <Node.hpp>
#include "Component.hpp"

namespace Engine
{
	/**
	 @brief Clase que encapsula el componente transform usando Node del toolkit
	*/
	class TransformComponent : public Component
	{
		/**
		 @brief Transform
		*/
		shared_ptr<glt::Node> transformation;

		/**
		 @brief Posición
		*/
		glm::vec3 position;
		/**
		 @brief Rotación
		*/
		glm::vec3 rotation;	
		/**
		 @brief Escala
		*/
		float scale;

	public:

		/**
		 @brief Crea el componente
		*/
		TransformComponent(shared_ptr<Entity> entity);

		/**
		 @brief Crea el componente con un transform inicial
		*/
		TransformComponent(shared_ptr<glt::Node> transformation);

		/**
		 @brief Destructor
		*/
		~TransformComponent();

		/**
		 @brief Setea el componente
		*/
		void set_transform(std::shared_ptr<glt::Node> node);

		/**
		 @brief Devuelve el transform
		*/
		shared_ptr<glt::Node> get_transformation();

		/**
		 @brief Devuelve la posición
		*/
		glm::vec3 get_position();

	public:

		/**
		 @brief Desplaza el transform
		*/
		void translate(float translation_x, float translation_y, float translation_z);

		/**
		 @brief Rota el transform
		*/
		void rotate(float rotation_x, float rotation_y, float rotation_z);

		/**
		 @brief Escala
		*/
		void scale_object(float scale);


		virtual bool initialize() override;

		/**
		 @brief Setea los valores del XML
		*/
		virtual bool parse_property(const string& name, const string& value) override;
	};
}

#endif // !TRANSFORM_COMPONENT_HEADER
