
//
//  File.cpp
//  TestGame
//
//  Created by Lucas Berezy on 20/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Game.h"

#include <SFML/Window/Event.hpp>

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);


Game::Game()
: mWindow(sf::VideoMode(640, 480), "World", sf::Style::Close)
, mWorld(mWindow)
, mFont()
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
{
    //mWindow.setVerticalSyncEnabled(true);
    mFont.loadFromFile("Media/Sansation.ttf");
    mStatisticsText.setFont(mFont);
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(10);
    
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
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
    /*if (mIsMovingUp) {
        movement.y -= 1;
    } else if (mIsMovingDown) {
        movement.y += 1;
    } else if (mIsMovingLeft) {
        movement.x -= 1;
    } else if (mIsMovingRight) {
        movement.x += 1;
    }*/
    
    mWorld.update(delta);

}

void Game::updateStatistics(sf::Time elapsedTime)
{
    mStatisticsUpdateTime += elapsedTime;
    mStatisticsNumFrames += 1;
    
    if (mStatisticsUpdateTime >= sf::seconds(1.0f))
    {
        mStatisticsText.setString(
                                  //"Frames / Second = " + std::string::toString toString(mStatisticsNumFrames) + "\n" +
                                  //"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us"
                                  "Test string"
                                  );
        
        mStatisticsUpdateTime -= sf::seconds(1.0f);
        mStatisticsNumFrames = 0;
    }
}

void Game::render()
{
    mWindow.clear();
    mWorld.draw();
    
    mWindow.setView(mWindow.getDefaultView());
    mWindow.draw(mStatisticsText);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    /*if (key == sf::Keyboard::W)  {
        mIsMovingUp = isPressed;
    } else if (key == sf::Keyboard::S) {
        mIsMovingDown = isPressed;
    } else if (key == sf::Keyboard::A) {
        mIsMovingLeft = isPressed;
    } else if (key == sf::Keyboard::D) {
        mIsMovingRight = isPressed;
    } */
}

