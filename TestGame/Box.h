#ifndef BOX_H
#define BOX_H

#include "GameEntity.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>
#include <Box2D/Box2D.h>


class Box : public Entity
{
public:
    enum Type
    {
        Regular
    };
    
    
public:
    Box(Type type, const TextureHolder& textures);
    
    
private:
    virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    
    
private:
    Type				mType;
    sf::Sprite			mSprite;
    b2BodyDef BodyDef;

};
#endif