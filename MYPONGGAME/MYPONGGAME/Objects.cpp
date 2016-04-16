//
//  Objects.cpp
//  MYPONGGAME
//
//  Created by Adeola Uthman on 4/14/16.
//  Copyright © 2016 Adeola Uthman. All rights reserved.
//

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <cmath>
#include "Point.cpp"



using namespace sf;
using namespace std;


class Entity {
    
    
};


/*
 
 The Ball
 
 */
class Ball : public Entity {
    
public:
    float centerX, centerY, radius;
    int speed, direction;
    
    Ball() {
        centerX = 0;
        centerY = 0;
        radius = 0;
        speed = 0;
        direction = 0;
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

/*
 
 The Paddle
 
 */
class Paddle : public Entity {
public:
     Point origin;
     int width, height;
     Color color;
    
    int speed, direction;
    
    
    //CONSTRUCTOR
    Paddle() {
        
    }
     Paddle(int oX, int oY, int w, int h, Color c) {
        origin = Point(oX, oY);
        width = w;
        height = h;
        color = c;
    }
    
    //GET THE VERTICIES OF THE RECTANGLE
     Point getOrigin() { return origin; }
     Point getTopRight() {
        Point P =  Point(origin.getX() + width, origin.getY());
        return P;
    }
     Point getBottomRight() {
        Point P =  Point(origin.getX() + width, origin.getY() + height);
        return P;
    }
     Point getBottomLeft() {
        Point P =  Point(origin.getX(), origin.getY() + height);
        return P;
    }
    
    //GET THE WIDTH AND HEIGHT
     int Width() {
        return width;
    }
     int Height() {
        return height;
    }
    
     void setColor(Color cx) {
        color = cx;
    }
    
     void setPosition(Point p) {
        origin = p;
    }
    
    //CHECKS IF THE POINT LIES IN THE RECTANGLE
     bool containsPoint(int x, int y) {
        bool cont;
        if(x > origin.getX() && x < (origin.getX() + width)) {
            if(y > origin.getY() && y < (origin.getY() + height)) {
                cont = true;
            } else {
                cont = false;
            }
        } else {
            cont = false;
        }
        
        return cont;
    }
    
    //MOVE THE RECTANGLE
     void move(int xAmount, int yAmount) {
        origin.setX(origin.getX() + xAmount);
        origin.setY(origin.getY() + yAmount);
    }
    
    //CHECK IF ANOTHER RECTANGLE INTERSECTS THIS ONE
     bool intersects(Paddle r) {
        bool inOrigin = false;
        bool inTopRight = false;
        bool inBottomRight = false;
        bool inBottomLeft = false;
        bool inOverall = false;
        
        if(this->containsPoint((int)r.getOrigin().getX(), (int)r.getOrigin().getY())) {
            inOrigin = true;
        }
        if(this->containsPoint((int)r.getTopRight().getX(), (int)r.getTopRight().getY())) {
            inTopRight = true;
        }
        if(this->containsPoint((int)r.getBottomRight().getX(), (int)r.getBottomRight().getY())) {
            inBottomRight = true;
        }
        if(this->containsPoint((int)r.getBottomLeft().getX(), (int)r.getBottomLeft().getY())) {
            inBottomLeft = true;
        }
        
        if(inOrigin || inTopRight || inBottomRight || inBottomLeft) {
            inOverall = true;
        } else if (!inOrigin && !inTopRight && !inBottomRight && !inBottomLeft) {
            inOverall = false;
        }
        
        return inOverall;
    }
    
     bool hits(Ball b) {
        bool hits = false;
        
        if(b.getX() >= this->getOrigin().getX() && b.getX() <= this->getTopRight().getX()) {
            if(b.getY() >= this->getOrigin().getY() && b.getY() <= this->getBottomRight().getY()) {
                hits = true;
            } else {
                hits = false;
            }
        } else {
            hits = false;
        }
        
        return hits;
    }
    
    
     void setSpeed(int s) {
        speed = s;
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