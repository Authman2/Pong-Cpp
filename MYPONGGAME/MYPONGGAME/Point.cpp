//
//  Point.cpp
//  MYPONGGAME
//
//  Created by Adeola Uthman on 4/15/16.
//  Copyright © 2016 Adeola Uthman. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <cmath>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

using namespace std;
using namespace sf;

class Point {
    
public:
    /**
     * Instance variables -- describe the position of the point.
     * Instance variables keep track of the state of the object.
     *
     * Scope: entire class, but not outside the class.
     * Lifetime: lasts as long as the object.
     */
    double x, y;
    /**
     * Constructor: sets intial values of the instance variables.
     * Only called once -- when the object is first created.
     */
     Point(double px, double py) {
        x = px;
        y = py;
    }
    /**
     * Default constructor: if there are no input parameters, we initiali
     * ze the coordinates to (0, 0).
     */
     Point() {
        x = 0.0;
        y = 0.0;
    }
    // The following methods are accessors -- return info about the objec
    //t, but do not modify the instance variables.
    /**
     * Returns the x coordinate.
     */
     double getX() {
        return x;
    }
    /**
     * Returns the y coordinate.
     */
     double getY() {
        return y;
    }
    /**
     * Returns the slope between this point and another point.
     */
     double slope(Point other) {
        return (y - other.getY())/(x - other.getX());
    }
    /**
     * Returns the dot product of this point and another point -- like th
     * e dot product of two vectors.
     */
     double dotProduct(Point other) {
        return x*other.getX() + y*other.getY();
    }
    /**
     * Returns the angle of the point in radians.
     * Angle is between the vector to the point, and the +x axis, as usua
     * l in trig.
     * Angle values are: [0, 2pi) -- including 0, not including 2pi.
     */
     double getTheta() {
        if(x == 0) {
            if(y > 0) { // +y axis
                return 3.14/2;
            }
            else if(y < 0) { // -y axis
                return -3.14/2;
            }
            else { // Origin
                return 0.0;
            }
        }
        else {
            double angle = atan(y/x);
            if(x > 0 && y >= 0) {
                // Quadrant 1
                return angle;
            }
            else if(x < 0) { // Quadrants 2 and 3
                return angle + 3.14;
            }
            else { // Quadrant 4
                return angle + 2*3.14;
            }
        }
    }
    // The following methods are modifiers -- these modify the state of t
    //he object, or in other words
    // modify the values of the instance variables.
    // They may or may not return info about the object (most don't)
    /**
     * Sets the x coordinate to a new value.
     */
     void setX(double newX) {
        x = newX;
    }
    /**
     * Sets the y coordinate to a new value.
     */
     void setY(double newY) {
        y = newY;
    }
    /**
     * Adds another point to the current point -- like adding vectors.
     */
     void translate(Point other) {
        x += other.getX();
        y += other.getY();
    }
    /**
     * Scales the point by factor s.
     */
     void scale(double s) {
        x *= s;
        y *= s;
    }
    /**
     * Rotates the point by angle, in radians.
     * Positive: counterclockwise
     * Negative: clockwise.
     *
     * This uses the formula for rotation of a point by an angle theta:
     *
     * x -> xcos(theta) - ysin(theta)
     * y -> xsin(theta) + xcos(theta)
     */
     void rotate(double angle) {
        double oldX = x; // Notice we need to store the old value, before changing x, so that y is calculated correctly.
        double oldY = y; // For symmetry, I store the old value of y also, although this is not strictly necessary.
        x = oldX*cos(angle) - oldY*sin(angle);
        y = oldX*sin(angle) + oldY*cos(angle);
    }
};

