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
}

void Planet::Step()
{

}

void Planet::Draw(sf::RenderWindow &window)
{
    window.draw(planet);
}

sf::Vector2f Planet::Force(const Planet &other) const
{
    sf::Vector2f temp;
    float d = sqrt(pow(_pos.x - other._pos.x, 2) +
            pow(_pos.y - other._pos.y, 2));

    if(d == 0)
    {
        temp.x = 0;
        temp.y = 0;
        return temp;
    }



}

Planet Planet::Speed()
{

}

Planet Planet::Acceleration(sf::Vector2f force)
{

}

void Planet::Collision(Planet &other)
{

}
