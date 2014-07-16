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
#include <string>


namespace game {

    class World : public game::Renderable {
        tmx::MapLoader *map;
    
    public:
        World(std::string map_file);
        void render(sf::RenderTarget &target);

    };
    
    
};

#endif