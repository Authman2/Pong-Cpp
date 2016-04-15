//
//  GameScreen.cpp
//  MYPONGGAME
//
//  Created by Adeola Uthman on 4/14/16.
//  Copyright © 2016 Adeola Uthman. All rights reserved.
//

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Objects.cpp"
#include <iostream>


using namespace sf;
using namespace std;


class GameScreen {
    
private:
    Event event;
    
    void KeyInput() {
        /* PLAYER 2 */
        //Up arrow key
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::Up) {
            if(paddle2.Y > 0) {
                paddle2.Y--;
            }
            
        }
        //Down arrow key
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::Down) {
            float height = paddle2Spr.getScale().y*paddle2.Height;
            if(paddle2.Y+height+height < 600) {
                paddle2.Y++;
            }
        }
        
        
        /* PLAYER 1 */
        //Up arrow key
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::W) {
            if(paddle1.Y > 0) {
                paddle1.Y--;
            }
        }
        //Down arrow key
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::S) {
            float height = paddle1Spr.getScale().y*paddle1.Height;
            if(paddle1.Y+height+height < 600) {
                paddle1.Y++;
            }
        }
    }
    
    
public:
    
    //Actual game objects
    Paddle paddle1, paddle2;
    Ball ball;
    
    //Create sprites for everything
    Sprite paddle1Spr;
    Sprite paddle2Spr;
    Sprite ballSpr;
    
    //Load the texture
    Texture whitepixel;
    
    //List of game sprites
    vector<Sprite> entities = vector<Sprite>();
    
    
    GameScreen() {
        paddle1.X = 40;
        paddle1.Y = 40;
        paddle1.Width = 2;
        paddle1.Height = 5;
        
        paddle2.X = 750;
        paddle2.Y = 40;
        paddle2.Width = 2;
        paddle2.Height = 5;
        
        ball.centerX = 400;
        ball.centerY = 300;
        ball.radius = 40;
    }
    
    
    /* Used for adding the key event handler to the game */
    void addEventHandler(Event e) {
        event = e;
    }
    
    
    
    
    /* Used for initializing necessary elements of the game. */
    void initialize() {
        //Load the texture
        if(!whitepixel.loadFromFile(resourcePath() + "WhitePixel.png")) { return EXIT_FAILURE; }
        
        //Set the textures
        paddle1Spr.setTexture(whitepixel);
        paddle2Spr.setTexture(whitepixel);
        ballSpr.setTexture(whitepixel);
    }
    
    /* Used for updating the game every frame. */
    void update() {
        
        //Look for key input
        KeyInput();
        
        //Set the sprites' positions
        paddle1Spr.setPosition(Vector2f(paddle1.X, paddle1.Y));
        paddle2Spr.setPosition(Vector2f(paddle2.X, paddle2.Y));
        ballSpr.setPosition(Vector2f(ball.centerX, ball.centerY));
        
        //Scale the images
        paddle1Spr.setScale(paddle1.Width, paddle1.Height);
        paddle2Spr.setScale(paddle2.Width, paddle2.Height);
        
        
        //Remove whatever is already there
        entities.erase(entities.begin(), entities.end());
        
        //Add all of the sprites to the entities list
        entities.push_back(paddle1Spr);
        entities.push_back(paddle2Spr);
        entities.push_back(ballSpr);
        
    }
    
};