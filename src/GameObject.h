//
// Created by Om Prakaash on 2019-07-22.
//

#ifndef GLUON2D_GAMEOBJECT_H
#define GLUON2D_GAMEOBJECT_H


#include <vector>
#include <unordered_map>
#include "Components/Component.h"
#include "Input.h"

namespace Gluon2D {

class GameObject {
private:
    std::vector<Component*> m_components;
    std::unordered_map<const std::type_info*, Component*> m_component_map;

public:

    void addComponent(Component* component);
    void update();
    template<typename T>
    Component* getComponent(){
        return m_component_map[&typeid(T)];
    }
};

}
#endif //GLUON2D_GAMEOBJECT_H
