#include "World.h"
#include "ResourcePath.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


World::World(sf::RenderWindow& window)
: mWindow(window)
, mWorldView(window.getDefaultView())
, mTextures()
, mSceneGraph()
, mSceneLayers()
, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
, mScrollSpeed(-50.f)
, mPlayer(nullptr)
, mTiledMap(resourcePath() + "test.tmx")
, mGravitySettings(0.f, 9.8f)
, mPhysicsWorld(mGravitySettings)
{
    loadTextures();
    buildScene();
    
    // Prepare the view
    mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
    // Scroll the world
    mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());
    
    // Move the player sidewards (plane scouts follow the main aircraft)
    sf::Vector2f position = mPlayer->getPosition();
    sf::Vector2f velocity = mPlayer->getVelocity();
    
    // If player touches borders, flip its X velocity
    if (position.x <= mWorldBounds.left + 150.f
        || position.x >= mWorldBounds.left + mWorldBounds.width - 150.f)
    {
        velocity.x = -velocity.x;
        mPlayer->setVelocity(velocity);
    }
    
    // Apply movements
    mSceneGraph.update(dt);
}

void World::draw()
{
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
}

void World::loadTextures()
{
    mTextures.load(Textures::Player, resourcePath() + "character_01.bmp");
    mTextures.load(Textures::RegularBox, resourcePath() + "box.png");
    //mTextures.load(Textures::Raptor, "Media/Textures/Raptor.png");
    //mTextures.load(Textures::Desert, "Media/Textures/Desert.png");
}

void World::buildScene()
{
    // Initialize the different layers
    for (std::size_t i = 0; i < LayerCount; ++i)
    {
        SceneNode::Ptr layer(new SceneNode());
        mSceneLayers[i] = layer.get();
        
        mSceneGraph.attachChild(std::move(layer));
    }
    /*
    // Prepare the tiled background
    sf::Texture& texture = mTextures.get(Textures::Desert);
    sf::IntRect textureRect(mWorldBounds);
    texture.setRepeated(true);
    
    // Add the background sprite to the scene
    std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
    backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
    mSceneLayers[Background]->attachChild(std::move(backgroundSprite));
    */
    // Add player
    std::unique_ptr<Person> player(new Person(Person::Player, mTextures));
    mPlayer = player.get();
    mPlayer->setPosition(mSpawnPosition);
    mPlayer->setVelocity(40.f, mScrollSpeed);
    mSceneLayers[Air]->attachChild(std::move(player));
    
    /*
    // Add two escorting aircrafts, placed relatively to the main plane
    std::unique_ptr<Aircraft> leftEscort(new Aircraft(Aircraft::Raptor, mTextures));
    leftEscort->setPosition(-80.f, 50.f);
    mPlayerAircraft->attachChild(std::move(leftEscort));
    
    std::unique_ptr<Aircraft> rightEscort(new Aircraft(Aircraft::Raptor, mTextures));
    rightEscort->setPosition(80.f, 50.f); 
    mPlayerAircraft->attachChild(std::move(rightEscort));
    */
}
