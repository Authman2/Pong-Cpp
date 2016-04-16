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
    
    /* Used in a similar fashion to the way you would use it in java. */
    void repaint() {
        //Remove whatever is already there
        entities.erase(entities.begin(), entities.end());
        
        //Add all of the sprites to the entities list
        entities.push_back(paddle1Spr);
        entities.push_back(paddle2Spr);
        entities.push_back(ballSpr);
    }
    
    void KeyInput() {
            
        /* PLAYER 2 */
        //Up arrow key
        if(Keyboard::isKeyPressed(Keyboard::Key::Up)) {
            if(paddle2.getOrigin().y > 0) {
                paddle2.move(0, -1);
            }
            
        }
        //Down arrow key
        if(Keyboard::isKeyPressed(Keyboard::Key::Down)) {
            float height = paddle2Spr.getScale().y*paddle2.height;
            if(paddle2.getOrigin().y+height+height < 600) {
                paddle2.move(0, 1);
            }
        }
        
        
        /* PLAYER 1 */
        //Up arrow key
        if(Keyboard::isKeyPressed(Keyboard::Key::W)) {
            if(paddle1.getOrigin().y > 0) {
                paddle1.move(0, -1);
            }
        }
        //Down arrow key
        if(Keyboard::isKeyPressed(Keyboard::Key::S)) {
            float height = paddle1Spr.getScale().y*paddle1.height;
            if(paddle1.getOrigin().y+height+height < 600) {
                paddle1.move(0, 1);
            }
        }
        
    }
    
    void ballLogic() {
        ball.move();
        
        //If the ball hits the paddles
        if(paddle2.hits(ball)) {
            ball.setDirection(ball.getDirection() - ((ball.getDirection() - 270) * 2));
            ball.move();
        }
        if(paddle1.hits(ball)) {
            ball.setDirection(ball.getDirection() - ((ball.getDirection() - 270) * 2));
            ball.move();
        }
        
        //Top boundary
        if(ball.getY() <= 0) {
            ball.setDirection((360 - ball.getDirection()));
        }
        //Bottom Boundary
        if(ball.getY() >= 600) {
            ball.setDirection((360 - (ball.getDirection()*ball.getDirection()) ));
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
        paddle1.setPosition(Point(35,40));
        paddle1.width = 2;
        paddle1.height = 5;
        
        paddle2.setPosition(Point(745,40));
        paddle2.width = 2;
        paddle2.height = 5;
        
        ball.centerX = 400;
        ball.centerY = 300;
        ball.radius = 1.5;
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
        
        //Update the movement of the ball
        ballLogic();
        
        //Set the sprites' positions
        paddle1Spr.setPosition(Vector2f(paddle1.getOrigin().x, paddle1.getOrigin().y));
        paddle2Spr.setPosition(Vector2f(paddle2.getOrigin().x, paddle2.getOrigin().y));
        ballSpr.setPosition(Vector2f(ball.centerX, ball.centerY));
        
        //Scale the images
        paddle1Spr.setScale(paddle1.width, paddle1.height);
        paddle2Spr.setScale(paddle2.width, paddle2.height);
        ballSpr.setScale(ball.radius, ball.radius);
        
        repaint();
    }
    
};