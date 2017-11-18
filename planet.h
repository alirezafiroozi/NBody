#ifndef PLANET_H
#define PLANET_H
#include <SFML/Graphics.hpp>
#include "random.h"
#include "constants.h"
#include "math.h"

class Planet
{
public:
    Planet();
    Planet(float xPos, float yPos, float xVel, float yVel, float mass,
           int radius, sf::Color col);
    void Step();
    void Draw(sf::RenderWindow& window);
    sf::Vector2f Force(const Planet& other) const;
    Planet Speed();
    Planet Acceleration(sf::Vector2f force);
    void Collision(Planet& other);
    bool isalive();



    /********** Do we need BIG3???? *****/
//    Planet(Planet& other);
//    Planet operator =(Planet& other);
//    ~Planet();


private:
    sf::CircleShape planet;
    sf::Vector2f _vel;
    sf::Vector2f _acc;
    sf::Vector2f _force;
    sf::Vector2f _pos;
    sf::Color _col;
    float _mass;
    int _radius;
    bool _alive = true;
};

#endif // PLANET_H
