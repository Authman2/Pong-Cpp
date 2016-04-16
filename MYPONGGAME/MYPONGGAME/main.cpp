
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

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "GameScreen.cpp"
#include <iostream>

using namespace sf;
using namespace std;


int main(int, char const**)
{
    // Create the main window
    RenderWindow window;
    window.create(VideoMode(800, 600), "Pong");

    
    
    //Create and initialize the actual game screen
    GameScreen gamescreen = GameScreen();
    gamescreen.initialize();
    
    
    // Start the game loop
    while (window.isOpen()) {
        
        // Process events
        Event p1;
        while (window.pollEvent(p1)) {
            // Close window: exit
            if (p1.type == Event::Closed) {
                window.close();
            }
            
        }
        

        // Clear screen
        window.clear();

        
        
        /*
         
         Here I am trying to use that standard game loop with initialize, update, and draw. If I ever try to make a real game in C++ I know that I will need to know how to use these methods and create objects outside of this class.
         
         */
        gamescreen.update();        
        
        //Draw each entity (sprite)
        for(Sprite ent : gamescreen.entities) {
            window.draw(ent);
        }
        
        
        
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
