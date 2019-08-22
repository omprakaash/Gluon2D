//
// Created by Om Prakaash on 2019-07-29.
//

#include <iostream>
#include "TransformComponent.h"
#include "../Game.h"


namespace Gluon2D {

TransformComponent::TransformComponent(GameObject* parent, int x, int y, int width, int height):
        m_width(width), m_height(height), Component(parent) {
    m_pos = Vector(x, y);
}

TransformComponent::TransformComponent(GameObject* parent, int x, int y, int width, int height, int rot):
Component(parent), m_width(width), m_height(height) {
    m_pos = Vector(x,y);
}

Vector TransformComponent::getPos() {
    return m_pos;
}

int TransformComponent::getXPos() {
    return m_pos.X;
}

int TransformComponent::getYPos() {
    return m_pos.Y;
}

int TransformComponent::getWidth() {
    return m_width;
}

int TransformComponent::getHeight() {
    return m_height;
}

void TransformComponent::rotate(float angle){
    m_rot += angle;
}

void TransformComponent::translate(int x, int y) {
    m_pos.translate(x, y);
}

void TransformComponent::translateX(int x) {
    translate(x,0);
}

void TransformComponent::translateY(int y){
    translate(0,y);
}

float TransformComponent::getAngle() {
    return m_rot;
}

}