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

#include <Box2D/Box2D.h>

#include <tmx/MapLoader.h>

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include "Game.h"

#include "GameEntity.h"
#include "World.h"

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"




int main(int, char const**)
{
    
    

    Game game;
    game.run();
    // load map
    
    //game::World map("test.tmx");


    return EXIT_SUCCESS;
}
