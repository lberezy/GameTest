//
//  GameEntity.cpp
//  TestGame
//
//  Created by Lucas Berezy on 16/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#include <stdio.h>
#include "GameEntity.h"

game::GameEntity::GameEntity() {
    //id = ID_COUNTER++;
}

game::GameEntity::~GameEntity() {
}

unsigned int game::GameEntity::getID() {
    return this->id;
}