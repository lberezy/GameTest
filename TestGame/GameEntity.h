//
//  GameEntity.h
//  TestGame
//
//  Created by Lucas Berezy on 15/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <SFML/Graphics.hpp>


namespace game {
    class GameEntity {
        
        static unsigned int ID_NUM;
        virtual void update(float delta) {};
    public:
        GameEntity();
        ~GameEntity();
    };
};

#endif