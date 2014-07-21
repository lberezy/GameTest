//
//  ResourceIdentifiers.h
//  TestGame
//
//  Created by Lucas Berezy on 21/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#ifndef RESOURCEIDENTIFIERS_H
#define RESOURCEIDENTIFIERS_H


// Forward declaration of SFML classes
namespace sf
{
    class Texture;
}

namespace Textures
{
    enum ID
    {
        Player,
        Raptor,
        Desert,
    };
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif