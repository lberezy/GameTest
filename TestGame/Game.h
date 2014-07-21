//
//  Game.h
//  TestGame
//
//  Created by Lucas Berezy on 20/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "World.h"


    class Game {
    public:
        Game();
        void run();
    private:
        void processEvents();
        void update(sf::Time delta);
        void render();
        
        void handlePlayerInput(sf::Keyboard::Key, bool isPressed);

        
    private:
        sf::RenderWindow mWindow;
        
        bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
        const sf::Time TimePerTick = sf::seconds(1.0 / 60.0f);
        
        
    };

#endif

