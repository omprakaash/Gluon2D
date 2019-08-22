//
// Created by Om Prakaash on 2019-08-14.
//

#ifndef GLUON2D_LOGICSYSTEM_H
#define GLUON2D_LOGICSYSTEM_H

#include "System.h"

namespace Gluon2D {

class LogicSystem : System {
protected:
    static std::vector<GameObject*> m_logicObjects;

public:
    static void addObject(GameObject* object);
    void update() override;
};

}

#endif //GLUON2D_LOGICSYSTEM_H
