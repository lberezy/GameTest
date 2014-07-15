//
//  PhysicalEntity.h
//  TestGame
//
//  Created by Lucas Berezy on 15/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#ifndef PHYSICALENTITY_H
#define PHYSICALENTITY_H

#include "GameEntity.h"

namespace game {
    class PhysicalEntity : public GameEntity {
        BOOL solid;
        
    };
};
#endif