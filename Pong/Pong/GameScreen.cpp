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
        paddle2 = Paddle(80,20,20,50);
        ball = Ball(30,30,10);
    }
    PongGame(Event e) {
        paddle1 = Paddle(10,20,20,50);
        paddle2 = Paddle(80,20,20,50);
        ball = Ball(30,30,10);
        event = e;
    }
    
    
    
    void initialize() {
        
        
        
    }
    
    void update() {
        
        //Player 1
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::Up) {
            cout << "Moving up\n";
        }
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::Down) {
            cout << "Moving down\n";
        }
        
        
        //Player 2
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::W) {
            cout << "Moving up\n";
        }
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::S) {
            cout << "Moving down\n";
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
        
        Sprite paddleSpr(pad1);
    }

    
    
};