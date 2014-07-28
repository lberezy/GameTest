#ifndef WORLD_H
#define WORLD_H

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include "Person.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <tmx/MapLoader.h>

#include <Box2D/Box2D.h>

#include <array>


// Forward declaration
namespace sf
{
    class RenderWindow;
}

class World : private sf::NonCopyable
{
public:
    explicit    World(sf::RenderWindow& window);
    void		update(sf::Time dt);
    void		draw();
    
    
private:
    void    loadTextures();
    void	buildScene();
    
    
private:
    enum Layer
    {
        Background,
        Air,
        LayerCount
    };
    
    
private:
    sf::RenderWindow&					mWindow;
    sf::View							mWorldView;
    TextureHolder						mTextures;
    tmx::MapLoader  mTiledMap;
    
    SceneNode							mSceneGraph;
    std::array<SceneNode*, LayerCount>	mSceneLayers;
    
    sf::FloatRect						mWorldBounds;
    sf::Vector2f						mSpawnPosition;
    float								mScrollSpeed;
    Person*							mPlayer;
    
    b2Vec2  mGravitySettings;
    b2World mPhysicsWorld;
};

#endif