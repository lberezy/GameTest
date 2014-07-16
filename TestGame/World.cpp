//
//  World.cpp
//  TestGame
//
//  Created by Lucas Berezy on 16/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#include <stdio.h>
#include <string>

#include "World.h"


game::World::World(std::string map_resource) {
    this->map = new tmx::MapLoader(resourcePath());
    map->Load(map_resource);
}

void game::World::render(sf::RenderTarget &target) {
    for (int i = 0; i < (map->GetLayers()).size(); i++) {
        map->Draw(target, i);
    }
}

void game::World::addEntity(game::GameEntity *entity) {
    entities.insert(std::pair<int, game::GameEntity*>(entity->getID(), entity));
}