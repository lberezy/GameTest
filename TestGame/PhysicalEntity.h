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

namespace game {
    class PhysicalEntity : public GameEntity, public Renderable {
    
        
    protected:
        bool solid;
        sf::Vector2f position;
        sf::Texture texture;
        sf::Sprite sprite;
        
    public:
        
        PhysicalEntity(std::string sprite_file, double x, double y);
        
        sf::Vector2f getPosition();
        virtual void update();
        virtual void draw(sf::RenderWindow &window);
    };
};
#endif