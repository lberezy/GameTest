//
//  GameEntity.cpp
//  TestGame
//
//  Created by Lucas Berezy on 15/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "PhysicalEntity.h"
#include "ResourcePath.hpp"


game::PhysicalEntity::PhysicalEntity(std::string sprite_file, double x, double y) {
    this->position = sf::Vector2f(x, y);
    this->texture.loadFromFile(resourcePath() + sprite_file);
    this->sprite.setTexture(this->texture);
}

void game::PhysicalEntity::draw(sf::RenderWindow &window) {
    window.draw(this->sprite);
    
}