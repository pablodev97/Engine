#include "Scene.hpp"
#include "Kernel.hpp"
#include "InputTask.hpp"
#include "RenderTask.hpp"
#include "RenderComponent.hpp"
#include "CameraComponent.hpp"
#include "LightComponent.hpp"
#include "rapidxml.hpp"

#include <fstream>
#include <iostream>
#include <vector>
#include "..\headers\Scene.hpp"

namespace Engine
{
    Scene::Scene(const std::string& scene_path)
        : dispatcher(new Dispatcher)
    {
        kernel = shared_ptr<Kernel>(new Kernel());

        entities = shared_ptr<Entity_Map>(new Entity_Map());

        init_kernel();

        load_scene(scene_path);

    }

    Scene::~Scene()
    {
    }

    shared_ptr<Kernel> Scene::get_kernel()
    {
        return kernel;
    }

    shared_ptr<Window> Scene::get_window()
    {
        return window;
    }

    shared_ptr<Dispatcher> Scene::get_dispatcher()
    {
        return dispatcher;
    }

    void Scene::load_scene(const string& scene_path)
    {
        rapidxml::xml_document<> doc;

        using std::ifstream;
        ifstream xmlFile(scene_path);
        std::vector<char> buffer((std::istreambuf_iterator<char>(xmlFile)), std::istreambuf_iterator<char>());
        buffer.push_back('\0');
        doc.parse<0>(&buffer[0]);

        rapidxml::xml_node<>* root_node = doc.first_node();

        if (root_node)
        {
            window = shared_ptr<Window>(new Window(
                root_node->first_attribute("WindowName")->value(),
                stoi(root_node->first_attribute("windowWidth")->value()),
                stoi(root_node->first_attribute("windowHeith")->value())
            ));
        

            for (rapidxml::xml_node<>* entity_node = root_node->first_node(); entity_node; entity_node = entity_node->next_sibling())
            {
                shared_ptr<Entity> entity = shared_ptr<Entity>(new Entity(entity_node->first_attribute("name")->value(), this));

                for (rapidxml::xml_node<>* component_node = entity_node->first_node(); component_node; component_node = component_node->next_sibling()) 
                {
                    string typeComponent = component_node->first_attribute("type")->value();
                    shared_ptr<Component> currentComponent;

                    if (typeComponent == "transform")
                        currentComponent = shared_ptr<TransformComponent>(new TransformComponent(entity));
                    else if (typeComponent == "render")
                        currentComponent = shared_ptr<RenderComponent>(new RenderComponent(entity));
                    else if (typeComponent == "camera")
                        currentComponent = shared_ptr<CameraComponent>(new CameraComponent(entity));
                    else if (typeComponent == "light")
                        currentComponent = shared_ptr<LightComponent>(new LightComponent(entity));

                    // Añadimos todos los componentes que vayamos creando en el motor

                    for (rapidxml::xml_node<>* propertyComponent = component_node->first_node(); propertyComponent; propertyComponent = propertyComponent->next_sibling()) //Son las propiedades de los componentes
                    {
                        currentComponent->parse_property(propertyComponent->name(), propertyComponent->value());
                    }

                    entity->add_component(typeComponent, currentComponent);

                }

                (*entities)[entity->get_id()] = entity;
               
            }
        }  

        for (auto ent : *entities)
        {
            auto components = (*ent.second).get_components();
            for (auto comp : components)
            {
                    comp.second->initialize();
            }
        }
    }


    shared_ptr<Task> Scene::get_task(const string& name)
    {
        if (name == "Render") return render;
        if (name == "Input") return input;

        return nullptr;
    }

    shared_ptr<Entity> Scene::get_entity(const string& name)
    {
        return (*entities)[name];
    }

    void Scene::init_kernel()
    {
        input = make_shared<InputTask>(this); 
        render = make_shared<RenderTask>(this);

        kernel->add_task(input);
        kernel->add_task(render);
    }
    
    void Scene::execute()
    {
        kernel->execute();
    }
}