#include "planet.h"
#include <iostream>

using namespace std;

Planet::Planet()
{
    cout << "\nPlanet CTOR got called\n";
}

Planet::Planet(float xPos, float yPos, float xVel, float yVel, float mass,
               int radius, sf::Color col)
{
    cout << "\nPlanet CTOR with arg got called\n";
    _pos.x = xPos;
    _pos.y = yPos;
    _vel.x = xVel;
    _vel.y = yVel;
    _mass = mass;
    _radius = radius;
    _col = col;
    planet.setRadius(_radius);
    planet.setFillColor(_col);
    planet.setPosition(sf::Vector2f(_pos.x, _pos.y));
    planet.setOrigin(sf::Vector2f(_radius, _radius));
}

void Planet::Step()
{
    _pos.x += _vel.x;
    _pos.y += _vel.y;
    _acc.x = 0;
    _acc.y = 0;
    planet.setPosition(sf::Vector2f(_pos.x, _pos.y));
}

void Planet::Draw(sf::RenderWindow &window)
{
    window.draw(planet);
}

sf::Vector2f Planet::Force(const Planet &other) const
{
    //gravity force between two objects
    //both objects from planet calss
    //return a myVector object containting fx and fy
    sf::Vector2f temp;
    double d = sqrt(pow(_pos.x - other._pos.x, 2)
                    + pow(_pos.y - other._pos.y, 2));
    //    cout << "F function: _pos: " << _pos._x << ", " << _pos._y << endl;
    //    cout << "F function: other._pos: " << other._pos._x << ", " << other._pos._y << endl;
    //    cout << "D: " << d << endl;
    if(d == 0)
    {
        temp.x = 0;
        temp.y = 0;
        return temp;
    }
    double force_temp = (/*G */  _mass * other._mass)/pow(d,2);
    //    double force_temp = Force(other);
    temp.x = force_temp * (_pos.x - other._pos.x) * -1
            / d;
    temp.y = force_temp * (_pos.y - other._pos.y) * -1
            / d;
    //    cout << "F func: " << temp << endl;
    return temp;
}

Planet Planet::Speed()
{
    //calculates Vx and Vy
    //change the value of _spd._x and _spd._y of the object
    _vel.x = (_vel.x + (_acc.x)) /* * t */;
    _vel.y = (_vel.y + (_acc.y)) /* * t */;
    return *this;
    //    cout << "speed func: _x: " << _spd._x << endl;
    //    cout << "speed func: _y: " << _spd._y << endl;
}

Planet Planet::Acceleration(sf::Vector2f force)
{
    //Acceleration Ax and Ay
    //change the value of _acc._x and _acc._y of the object
    _acc.x = force.x/_mass;
    _acc.y = force.y/_mass;
    //    cout << "Acc function: _acc: " << _acc << endl;
    return *this;
}

void Planet::Collision(Planet &other)
{

}
