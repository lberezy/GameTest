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


game::PhysicalEntity::PhysicalEntity(game::Animation *sprite, double x, double y) {
    this->position = sf::Vector2f(x, y);
    this->sprite = sprite;
}

void game::PhysicalEntity::draw(sf::RenderWindow &window) {
    window.draw(*this->sprite);
}

sf::Vector2f game::PhysicalEntity::getPosition() {
    return this->position;
}

void game::PhysicalEntity::update() {

}
