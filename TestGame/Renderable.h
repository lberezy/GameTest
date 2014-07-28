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