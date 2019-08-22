//
// Created by Om Prakaash on 2019-08-05.
//

#include "PhysicsSystem.h"
#include "../Components/TransformComponent.h"
#include "../Components/RenderComponent.h"
#include "../Components/PhysicsComponent.h"

namespace Gluon2D{

    std::vector<GameObject*> PhysicsSystem::m_phyObjects;

    void PhysicsSystem::addObject(Gluon2D::GameObject *gameObject) {
        m_phyObjects.push_back(gameObject);
    }

    void PhysicsSystem::update(){

        for(GameObject* object1 : m_phyObjects){
            for(GameObject* object2 : m_phyObjects){
                if(object1 != object2){

                    TransformComponent* transform1 =
                            static_cast<TransformComponent*>(object1->getComponent<TransformComponent>());
                    TransformComponent* transform2 =
                            static_cast<TransformComponent*>(object2->getComponent<TransformComponent>());

                    Body body1 = {transform1->getXPos(), transform1->getYPos(), transform1->getWidth(), transform1->getHeight() };
                    Body body2 = {transform2->getXPos(), transform2->getYPos(), transform2->getWidth(), transform2->getHeight()};

                    if( body1.x < body2.x + body2.width &&
                        body1.x + body1.width > body2.x &&
                        body1.y < body2.y + body2.height &&
                        body1.y + body1.width > body2.y){

                        static_cast<PhysicsComponent*>(object1->getComponent<PhysicsComponent>())->onCollision(object2);
                        static_cast<PhysicsComponent*>(object2->getComponent<PhysicsComponent>())->onCollision(object1);

                    }


                }
            }
        }

    }

}