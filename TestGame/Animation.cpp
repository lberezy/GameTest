#include <stdio.h>
#include "Animation.h"

game::Animation::Animation(sf::Texture &texture, int frames, int framerate) {
    this->setTexture(texture);
    this->frames = frames;
    this->framerate = framerate;
    
    playing = false;
    frameWidth = texture.getSize().x / frames;
    frameHeight = texture.getSize().y;
    currentFrame = 0.f;
    
    updateAnimFrame();
}

game::Animation::~Animation() {
    
}

void game::Animation::render(sf::RenderTarget& target) {
    target.draw((sf::Sprite)*this);
}

void game::Animation::update(float frametime) {
    if (playing) {
        updateAnimFrame();
        currentFrame += (float)framerate * frametime;
        while (currentFrame > frames) {
            currentFrame -= frames;
        }
    }
}

void game::Animation::updateAnimFrame() {
    this->setTextureRect(sf::IntRect(frameWidth * (int)currentFrame,
                                 0,
                                 frameWidth * (int)currentFrame + frameWidth,
                                 frameHeight));
}

int game::Animation::getWidth() {
    return frameWidth;
}

int game::Animation::getHeight() {
    return frameHeight;
}

void game::Animation::play() {
    playing = true;
}

void game::Animation::pause() {
    playing = false;
}

bool game::Animation::isPlaying() {
    return playing;
}

int game::Animation::getCurrentFrame() {
    return currentFrame;
}

void game::Animation::setCurrentFrame(int frame) {
    currentFrame = frame;
}

int game::Animation::getFramerate() {
    return framerate;
}

void game::Animation::setFramerate(int framerate) {
    if (framerate >= 0)
        this->framerate = framerate;
}