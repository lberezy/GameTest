
//
//  File.cpp
//  TestGame
//
//  Created by Lucas Berezy on 20/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#include <stdio.h>
#include "Game.h"

Game::Game() :
    mWindow(sf::VideoMode(800, 600), "Test Game")
    //, map("test.tmx")
{
    mWindow.setVerticalSyncEnabled(true);
    
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerTick) {
            timeSinceLastUpdate -= TimePerTick;
            processEvents();
            update(TimePerTick);
        }
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    sf::Vector2<float> player_direction;
    
    while (mWindow.pollEvent(event))
    {
        switch (event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
            default:
                break;
        }
    }
    
}

void Game::update(sf::Time delta) {
    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp) {
        movement.y -= 1;
    } else if (mIsMovingDown) {
        movement.y += 1;
    } else if (mIsMovingLeft) {
        movement.x -= 1;
    } else if (mIsMovingRight) {
        movement.x += 1;
    }
    
    
}

void Game::render() {
    mWindow.clear();
    
    // window.draw();
    //map.render(mWindow);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W)  {
        mIsMovingUp = isPressed;
    } else if (key == sf::Keyboard::S) {
        mIsMovingDown = isPressed;
    } else if (key == sf::Keyboard::A) {
        mIsMovingLeft = isPressed;
    } else if (key == sf::Keyboard::D) {
        mIsMovingRight = isPressed;
    }
}

