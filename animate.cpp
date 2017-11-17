#include "animate.h"
#include "constants.h"
#include "system.h"
#include <iostream>

using namespace std;


Animate::Animate()
{
    cout << "============Animate CTOR got called============\n";
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Gravity Simulator");
    //creates window, get height and width from constants.h
    system = System();
    planet = Planet();
    window.setFramerateLimit(FRAME_RATE);

    //Creates mouse point
    mouseIn = true;
    mousePoint = sf::CircleShape();
    mousePoint.setRadius(1.0);
    mousePoint.setFillColor(sf::Color::Blue);

    cout << "============Animate CTOR END!============\n";

}

void Animate::Run()
{
    cout << "============Animate Main Loop Started============\n";
    while(window.isOpen())
    {
        processEvents();
        update();
        render(); //clear/draw/display
    }
    cout << "============Animate Main Loop END!============\n";
}

void Animate::ProcessEvents()
{
    sf::Event event;
    while(window.pollEvent(event)){
        switch(event.type){
        case sf::Event::Closed:
            window.close();break;
        case sf::Event::MouseEntered:
            mouseIn = true;break;
        case sf::Event::MouseLeft:
            mouseIn = false;break;
        case sf::Event::MouseMoved:
            mousepoint.getPosition();
            //            cout << mousepoint.getPosition().x << ", "
            //                 << mousepoint.getPosition().y << endl;break;
            break;
        case sf::Event::KeyPressed:
            switch(event.key.code){
            case sf::Keyboard::R:
                //planet.reset;
                break;
            case sf::Keyboard::P:
                pause = !pause;break;
            case sf::Keyboard::Escape:
                window.close();break;
            }
        case sf::Event::MouseButtonPressed:
            double timer = 0;
            while(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                //calculate the time it was held down, and increment the size of the
                //particle that is created
                // timer += 0.01;
                //                cout << "Debug:timer:" << timer << endl;

                if(timer >= CAP){
                    std::exit(1);
                }
            }//test - yet to try

            cout << mousepoint.getPosition().x << ", "
                 << mousepoint.getPosition().y << endl;break;

            //then create a new particle based on size
            //planet.new(timer);
            break;
        }
    }
}

void Animate::Update()
{
    _command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);
    }
}

void Animate::render()
{
    window.clear();
    Draw();
    window.display();
}

void Animate::Draw()
{
    system.Draw(window);

    if(mouseIn)
        window.draw(mousePoint);

}

string mouse_pos_string(sf::RenderWindow& window)
{
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}
