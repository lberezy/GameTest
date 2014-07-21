//
//  GameEntity.h
//  TestGame
//
//  Created by Lucas Berezy on 15/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "SceneNode.h"


class Entity : public SceneNode
{
public:
    void				setVelocity(sf::Vector2f velocity);
    void				setVelocity(float vx, float vy);
    sf::Vector2f		getVelocity() const;
    
    
private:
    virtual void		updateCurrent(sf::Time dt);
    
    
private:
    sf::Vector2f		mVelocity;
};

#endif