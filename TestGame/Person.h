#ifndef PERSON_H
#define PERSON_H


#include <SFML/Graphics/Sprite.hpp>

#include "GameEntity.h"
#include "ResourceIdentifiers.h"

class Person : public SceneNode {
    
public:
    enum Type
    {
        Player,
        Raptor
    };
    
    
public:
    Person(Type type, const TextureHolder& textures);
    
    
private:
    virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    
    
private:
    Type				mType;
    sf::Sprite			mSprite;
};
#endif

