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
    
    bool gameStarted, gameEnded;
    
    sf::Clock AITimer;
    const sf::Time AITime = sf::seconds(0.1f);
    float ballAngle = 0.f;
    sf::Clock clock;
    
    
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
        //Start the game
        if(Keyboard::isKeyPressed(Keyboard::Key::Space)) {
            if(!gameStarted) {
                gameStarted = true;
                // Reset the ball angle
                do
                {
                    // Make sure the ball initial angle is not too much vertical
                    ballAngle = (std::rand() % 360) * 2 * 3.1415926 / 360;
                }
                while (std::abs(std::cos(ballAngle)) < 0.7f);
            }
        }
        
        if(gameStarted) {
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
    
    }
    
    void ballLogic() {
        
        if(gameStarted) {
            ball.move();
            // Check collisions between the ball and the screen
            if (ball.centerX - ball.radius < 0.f)
            {
                gameStarted = false;
            }
            if (ball.centerX + ball.radius > 800)
            {
                gameStarted = false;
            }
            if (ball.centerY - ball.radius < 0.f)
            {
                ballAngle = -ballAngle;
                ball.setPosition(ball.centerX, ball.radius + 0.1f);
            }
            if (ball.centerY + ball.radius > 600)
            {
                ballAngle = -ballAngle;
                ball.setPosition(ball.centerX, 600 - ball.radius - 0.1f);
                ball.move();
            }
            
            // Check the collisions between the ball and the paddles
            // Left Paddle
            if (ball.centerX - ball.radius < paddle1.getOrigin().x + paddle1.width / 2 &&
                ball.centerX - ball.radius > paddle1.getOrigin().x &&
                ball.centerY + ball.radius >= paddle1.getOrigin().y - paddle1.width / 2 &&
                ball.centerY - ball.radius <= paddle1.getOrigin().y + paddle1.width / 2)
            {
                if (ball.centerY > paddle2.getOrigin().y)
                    ballAngle = 3.1415926 - ballAngle + (std::rand() % 20) * 3.1415926 / 180;
                else
                    ballAngle = 3.1415926 - ballAngle - (std::rand() % 20) * 3.1415926 / 180;
                
                ball.setPosition(paddle1.getOrigin().x + ball.radius + paddle1.width / 2 + 0.1f, ball.centerY);
            }
            
            // Right Paddle
            if (ball.centerX - ball.radius > paddle2.getOrigin().x + paddle2.width / 2 &&
                ball.centerX - ball.radius < paddle2.getOrigin().x &&
                ball.centerY + ball.radius >= paddle2.getOrigin().y - paddle2.width / 2 &&
                ball.centerY - ball.radius <= paddle2.getOrigin().y + paddle2.width / 2)
            {
                if (ball.centerY > paddle2.getOrigin().y)
                    ballAngle = 3.1415926 - ballAngle + (std::rand() % 20) * 3.1415926 / 180;
                else
                    ballAngle = 3.1415926 - ballAngle - (std::rand() % 20) * 3.1415926 / 180;
                
                ball.setPosition(paddle2.getOrigin().x - ball.radius - paddle2.width / 2 - 0.1f, ball.centerY);
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
        
        ball.setDirection(random() % 360);
        ball.setSpeed(2);
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