//
//  World.h
//  TestGame
//
//  Created by Lucas Berezy on 16/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#ifndef WORLD_H
#define WORLD_H

#include <tmx/MapLoader.h>

#include "Renderable.h"
#include "ResourcePath.hpp"
#include "GameEntity.h"
#include <string>




namespace game {

    typedef std::map<int, game::GameEntity*> EntityMap;

    
    class World : public game::Renderable {
        tmx::MapLoader *map;
        EntityMap entities;
    public:
        World(std::string map_file);
        void render(sf::RenderTarget &target);
        void addEntity(game::GameEntity*);
    };
    
    
};

#endif