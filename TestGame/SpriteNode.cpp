//
//  SpriteNode.cpp
//  TestGame
//
//  Created by Lucas Berezy on 21/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#include "SpriteNode.h"

#include <SFML/Graphics/RenderTarget.hpp>


SpriteNode::SpriteNode(const sf::Texture& texture)
: mSprite(texture)
{
}

SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect)
: mSprite(texture, textureRect)
{
}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}
