
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
#include "GameScreen.cpp"

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"


using namespace sf;
using namespace std;


int main(int, char const**)
{
    // Create the main window
    RenderWindow window( VideoMode(800, 600), "Pong");

    
    
    //Create the game object
    PongGame game = PongGame();
    
    //Draw the first frame of the game
    game.draw();
   
    
    // Start the game loop
    while (window.isOpen())  {
        
        // Main Event Handler
        Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        
        //Add the event handler to the game, then update and draw it.
        game.AddEventHandler(event);
        game.update();
        game.draw();
        

        // Clear screen
        window.clear();

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
