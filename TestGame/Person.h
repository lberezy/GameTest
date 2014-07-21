
//
//  Player.h
//  TestGame
//
//  Created by Lucas Berezy on 13/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#ifndef PERSON_H
#define PERSON_H

#include "GameEntity.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>


class Person : public Entity
{
public:
    enum Type
    {
        Player,
        Raptor,
    };
    
    
public:
    Person(Type type, const TextureHolder& textures);
    
    
private:
    virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    
    
private:
    Type				mType;
    sf::Sprite			mSprite;
};
#endif

