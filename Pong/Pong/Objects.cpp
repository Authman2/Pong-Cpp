//
//  Objects.cpp
//  Pong
//
//  Created by Adeola Uthman on 4/12/16.
//  Copyright © 2016 Adeola Uthman. All rights reserved.
//

#include <stdio.h>
#include <cmath>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#import <iostream>
#import <fstream>

/*
 
 The Paddle
 
 */
class Paddle {
    
public:
    //Positions on screen
    int X, Y;
    
    //Width and Height
    int Width, Height;
    
    Paddle() {
        
    }
    
    Paddle(int x, int y, int w, int h) {
        X = x;
        Y = y;
        Width = w;
        Height = h;
    }
    
};






/*
 
 The Ball
 
 */
class Ball {
    
public:
     int centerX, centerY, radius;
     int speed, direction;
    
    Ball() {
        
    }
        
     Ball(int x, int y, int r) {
        centerX = x;
        centerY = y;
        radius = r;
     }
    
     int getX() {
        return centerX;
     }
     int getY() {
        return centerY;
     }
     int getRadius() {
        return radius;
     }
    
     bool containsPoint(int x, int y) {
        int xSquared = (x - centerX) * (x - centerX);
        int ySquared = (y - centerY) * (y - centerY);
        int radiusSquared = radius * radius;
        return xSquared + ySquared - radiusSquared <= 0;
     }
    
     void setPosition(int x, int y){
        centerX = x;
        centerY = y;
     }
    
     void setSpeed(int s) {
        speed = s;
    }
    
     void move(int xAmount, int yAmount) {
        centerX = centerX + xAmount;
        centerY = centerY + yAmount;
    }
    
     void move() {
        move((int)(speed * cos(direction)), (int)(speed * sin(direction)));
    }
    
     void setDirection(int degrees) {
        direction = degrees % 360;
    }
    
    void turn(int degrees) {
        direction = (direction + degrees) % 360;
    }
    
    int getDirection() {
        return direction;
    }
};


