//
// Created by Om Prakaash on 2019-07-22.
//

#include <string>
#include <iostream>
#include "GameObject.h"
#include "Components/RenderComponent.h"

void Gluon2D::GameObject::update() {
    for(auto &components: m_components){
        std::cout<<components->name();
        components->update();
    }
}

void Gluon2D::GameObject::addComponent(Gluon2D::Component *component) {
    m_components.push_back(component);
    m_component_map[&typeid(*component)] = component;
    component->set_parent(this);

    // If render Component

    std::cout<< typeid(*component).name() << std::endl;

    if(std::strcmp(component->name(), "RenderComponent") == 0){
        std::cout << "Hello !!!!!" << std::endl;
        static_cast<RenderComponent*>(component)->makeParentRenderable();
    }

}

