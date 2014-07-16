//
//  Animation.h
//  TestGame
//
//  Created by Lucas Berezy on 16/07/2014.
//  Copyright (c) 2014 Lucas Berezy. All rights reserved.
//

#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include "Renderable.h"

namespace game {
    class Animation : public sf::Sprite, public game::Renderable {
    public:
        Animation(sf::Image& image, int frames, int framerate);
        ~Animation();
        
        void update(float frametime);
        void render(sf::RenderTarget& target);
        void play();
        void pause();
        bool isPlaying();
        int getCurrentFrame();
        void setCurrentFrame(int frame);
        int getWidth();
        int getHeight();
        int getFramerate();
        void setFramerate(int framerate);
        
    private:
        int framerate;
        int frames;
        float currentFrame;
        bool playing;
        int frameWidth, frameHeight;
        
        void updateRect();
    };
};

#endif