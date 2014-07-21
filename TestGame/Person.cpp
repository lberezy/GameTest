//
//  Player.cpp
//  TestGame
//
//  Created by Lucas Berezy on 12/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#include "Person.h"
#include "ResourceHolder.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

Textures::ID toTextureID(Person
::Type type)
{
    switch (type)
    {
        case Person::Player:
            return Textures::Player;
            
        case Person::Raptor:
            return Textures::Raptor;
    }
    return Textures::Player;
}

Person::Person(Type type, const TextureHolder& textures)
: mType(type)
, mSprite(textures.get(toTextureID(type)))
{
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Person::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

