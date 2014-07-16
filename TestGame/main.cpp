
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
    
    game::World map("test.tmx");
    
    sf::View view(sf::Vector2f(350, 300), sf::Vector2f(300, 200));
    
    window.setView(view);
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(10, 10)),
        sf::Vertex(sf::Vector2f(0, 0))
    };
    
    
    sf::Clock clock;
    // Start the game loop
    while (window.isOpen())
    {
        
        float delta = clock.restart().asSeconds();
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
                view.move(100, 100);
                view.zoom(0.5f);
                printf("test");
            }
            
            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
            
            
            if (event.type == sf::Event::MouseMoved) {
                line[1] = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
            }
        }
        
        // update all entities
        for(game::GameEntity e : entityList) {
            e.update(delta);
        }

        // Clear screen
        window.clear();
        map.render(window);
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
