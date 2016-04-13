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
#include "Objects.cpp"

#import <iostream>
#import <fstream>

using namespace sf;
using namespace std;





/* The Pong game screen. */
class PongGame {

private:
    Event event;
    
    
public:
    Paddle paddle1, paddle2;
    Ball ball;
    
    PongGame() {
        paddle1 = Paddle(10,20,20,50);
        paddle2 = Paddle(750,20,20,50);
        ball = Ball(30,30,10);
    }
    
    
    void AddEventHandler(Event e) {
        event = e;
    }
    
    //Move the ball in random directions
    void ballMovement() {
        
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
        Texture pad1, pad2, ball;
        
        if(!pad1.loadFromFile("WhitePixel.png")) {
            return EXIT_FAILURE;
        }
        if(!pad2.loadFromFile("WhitePixel.png")) {
            return EXIT_FAILURE;
        }
        if(!ball.loadFromFile("WhitePixel.png")) {
            return EXIT_FAILURE;
        }
        
        Sprite paddle1Spr(pad1);
        Sprite paddle2Spr(pad2);
        Sprite ballSpr(ball);
    }

    
    
};