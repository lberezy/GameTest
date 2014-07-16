
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <tmx/MapLoader.h>

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include "GameEntity.h"
#include "World.h"

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"




int main(int, char const**)
{
    
    std::vector<game::GameEntity> entityList;
    // Create the main window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    
    sf::Window();
    sf::RenderWindow window(sf::VideoMode(800, 600), "TEST", sf::Style::Default, settings);

    
    // load map
    
    game::World map("Untitled.tmx");
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    text.setColor(sf::Color::White);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    music.play();
    sf::CircleShape circle(50);
    circle.setPointCount(4);
    
    
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(10, 10)),
        sf::Vertex(sf::Vector2f(0, 0))
    };
    
    
    sf::Clock clock;
    // Start the game loop
    while (window.isOpen())
    {
        
        sf::Time delta = clock.restart();
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                text.move(1,1);
            }
            
            if (event.type == sf::Event::MouseMoved) {
                //sf::Vector2i mouse_pos =  sf::Mouse::getPosition();
                line[1] = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
                //line[1] = sf::Vertex(sf::Vector2f(mouse_pos.x, mouse_pos.y));
            }
        }
        
        // update all entities
        for(game::GameEntity e : entityList) {
            e.update(delta);
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        //window.draw(sprite);

        // Draw the string
        window.draw(text);
        //window.draw(map);
        map.render(window);
        window.draw(circle);
        window.draw(line, 2, sf::Lines);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
