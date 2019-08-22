//
// Created by Om Prakaash on 2019-07-22.
//

#include <string>
#include <iostream>
#include "GameObject.h"
#include "Components/RenderComponent.h"



Gluon2D::GameObject::GameObject(const char *tag): m_tag(tag) {

}



void Gluon2D::GameObject::setTag(const char *tag) {
    m_tag = tag;
}

