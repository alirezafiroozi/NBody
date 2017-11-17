#ifndef ANIMATE_H
#define ANIMATE_H
#include <SFML/Graphics.hpp>
#include "system.h"


class Animate
{
public:
    Animate();
    void Run();
    void ProcessEvents();
    void Update();
    void Render();
    void Draw();

private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;
    System system;
    Planet planet;
    int _commant;
    bool mouseIn;
};

std::string mouse_pos_string(sf::RenderWindow& window);

#endif // ANIMATE_H
