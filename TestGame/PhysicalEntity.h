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
#include "Renderable.h"
#include "Animation.h"

namespace game {
    class PhysicalEntity : public GameEntity, public Renderable {
    
        
    protected:
        bool solid;
        sf::Vector2f position;
        game::Animation *sprite;
        
    public:
        
        PhysicalEntity(game::Animation *sprite, double x, double y);
        
        sf::Vector2f getPosition();
        virtual void update();
        void draw(sf::RenderWindow &window);
    };
};
#endif