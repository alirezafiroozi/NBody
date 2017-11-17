#include <iostream>
#include "animate.h"
#include <SFML/Graphics.hpp>
#include "system.h"
#include "planet.h"

using namespace std;

void test();

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
//    Animate animate;
//    animate.Run();
    test();
    return 0;
}

void test()
{
    sf::Vector2f pos1, pos2;
    sf::Vector2f vel1, vel2;
    sf::Vector2f acc1, acc2;
    sf::Color col1(100,100,100);


    pos1.x = 300;
    pos1.y = 300;
    pos2.x = 500;
    pos2.y = 500;
    vel1.x = 5;
    vel1.y = 5;
    vel2.x = -3;
    vel2.y = 0;
    acc1.x = 0;
    acc1.y = 0;
    acc2.x = 0;
    acc2.y = 0;

    Planet planet1(pos1.x, pos1.y, vel1.x, vel1.y, 50, 20, col1);
    Planet planet2(pos2.x, pos2.y, vel2.x, vel2.y, 50, 30, col1);

//    System::planetVector.push_back(planet1);
//    System::planetVector.push_back(planet2);
    vector<Planet> p;
    p.push_back(planet1);
    p.push_back(planet2);

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Default);
    window.setFramerateLimit(20);

    sf::Event event;

    while(window.isOpen())
    {

        while(window.pollEvent(event))
        {
            window.clear(sf::Color::Blue);
            vector<Planet>::iterator it;
            it = p.begin();
            sf::Vector2f temp(0, 0);

            for(int i = 0; i < p.size(); i++)
            {
                for(int n = 0; n < p.size(); n++)
                {

                    temp = temp + it[i].Force(it[n]);
                }
                it[i].Acceleration(temp);
                it[i].Speed();
                it[i].Step();
                it[i].Draw(window);
//                p[i].Acc(temp);
//                p[i].Speed();
//                p[i].Move();
//                p[i].Draw(window);



            }
            window.display();
        }
    }

}
