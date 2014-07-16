//
//  Renderable.h
//  TestGame
//
//  Created by Lucas Berezy on 16/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <SFML/Graphics.hpp>


namespace game {
    class Renderable {
    
    public:
        virtual void update(float delta) {};
        virtual void render(sf::RenderTarget &target) {};
    };
    
};

#endif