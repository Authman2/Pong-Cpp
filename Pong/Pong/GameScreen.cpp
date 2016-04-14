//
//  GameScreen.cpp
//  Pong
//
//  Created by Adeola Uthman on 4/12/16.
//  Copyright © 2016 Adeola Uthman. All rights reserved.
//

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Objects.cpp"
#include "main.cpp"

#import <iostream>
#import <fstream>

using namespace sf;
using namespace std;





/* The Pong game screen. */
class PongGame {

private:
    Event event;
    
public:
    //Game objects
    Paddle paddle1, paddle2;
    Ball ball;
    
    //Sprites
    Sprite paddle1Spr;
    Sprite paddle2Spr;
    Sprite ballSpr;
    
    //List of objects
    vector<Sprite> gameobj = vector<Sprite>();
    
    
    PongGame() {
        paddle1.X = 10;
        paddle1.Y = 20;
        paddle1.Width = 20;
        paddle1.Height = 50;
        
        paddle2.X = 750;
        paddle2.Y = 20;
        paddle2.Width = 20;
        paddle2.Height = 50;
        
        ball.centerX = 30;
        ball.centerY = 30;
        ball.radius = 10;
        
        gameobj.push_back(paddle1Spr);
        gameobj.push_back(paddle2Spr);
        gameobj.push_back(ballSpr);

    }
    
    
    void AddEventHandler(Event e) {
        event = e;
    }
    
    //Move the ball in random directions
    void ballMovement() {
        
    }
    
    void initalize() {
        
    }
    
    void update() {
        
        //Move the ball
        ballMovement();
        
        //Player 1
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::Up) {
            cout << "Moving up\n";
            
            //Move up
            if(paddle1.Y > 0) {
                paddle1.Y--;
            }
        }
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::Down) {
            cout << "Moving down\n";
            
            //Move down
            if(paddle1.Y < 600) {
                paddle1.Y++;
            }
        }
        
        
        //Player 2
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::W) {
            cout << "Moving up\n";
            
            //Move up
            if(paddle2.Y > 0) {
                paddle2.Y--;
            }
        }
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::S) {
            cout << "Moving down\n";
            
            //Move up
            if(paddle2.Y > 0) {
                paddle2.Y--;
            }
        }
    }
    
    void draw() {
        Texture pad1, pad2, ballt;
        
        if(!pad1.loadFromFile(resourcePath() + "WhitePixel.png")) { return EXIT_FAILURE; }
        if(!pad2.loadFromFile(resourcePath() + "WhitePixel.png")) { return EXIT_FAILURE; }
        if(!ballt.loadFromFile(resourcePath() + "WhitePixel.png")) { return EXIT_FAILURE; }
        
        //Set the textures for each sprite
        paddle1Spr.setTexture(pad1);
        paddle2Spr.setTexture(pad2);
        ballSpr.setTexture(ballt);
        
        //Set the rectangle area
        paddle1Spr.setTextureRect(IntRect(paddle1.X, paddle1.Y, paddle1.Width, paddle1.Height));
        paddle2Spr.setTextureRect(IntRect(paddle2.X, paddle2.Y, paddle2.Width, paddle2.Height));
        ballSpr.setTextureRect(IntRect(ball.centerX, ball.centerY, ball.radius, ball.radius));
        
        window.draw(paddle1Spr);
    }

    
    
};