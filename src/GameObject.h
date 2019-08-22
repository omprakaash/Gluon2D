//
// Created by Om Prakaash on 2019-07-22.
//

#ifndef GLUON2D_GAMEOBJECT_H
#define GLUON2D_GAMEOBJECT_H


#include <vector>
#include <unordered_map>
#include "Components/Component.h"
#include "Systems/InputSystem.h"

namespace Gluon2D {

class Component;
class GameObject {
private:

    int m_id;
    const char* m_tag;
    std::vector<Component*> m_components;
    std::unordered_map<const std::type_info*, Component*> m_componentMap;

public:

    GameObject(){}

    GameObject(const char* tag);

    template <typename T, typename... TArgs >
    void addComponent(TArgs&&... args){
        T* component = new T(this, std::forward<TArgs>(args)...);
        m_components.push_back(component);
        m_componentMap[&typeid(T)] = component;
    }

    void setTag(const char* tag);

    template<typename T>
    T* getComponent(){
        return static_cast<T*>(m_componentMap[&typeid(T)]);
    }

};

}
#endif //GLUON2D_GAMEOBJECT_H
