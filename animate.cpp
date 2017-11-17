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

    //creates view perspective
    view = sf::View(window.getDefaultView());
    window.setView(view);

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
        ProcessEvents();
        Update();
        Render(); //clear/draw/display
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
            mousePoint.getPosition();
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
            case sf::Keyboard::A:
                view.zoom(0.5);
                window.setView(view);break;
            case sf::Keyboard::S:
                view.zoom(2.0);
                window.setView(view);break;
            }
            break;
        case sf::Event::MouseButtonPressed:{
            //actual mouse coords based on resolution
            sf::Vector2i mouse_coord = sf::Mouse::getPosition();
            cout << "MP.X:" << mousePoint.getPosition().x << ", "
                 << "MP.Y:" << mousePoint.getPosition().y << endl;

            //real world coords based on perspective (after zoom)
            sf::Vector2f world_coord = window.mapPixelToCoords(mouse_coord);
            cout << "WC.X:" << world_coord.x << ", "
                 << "WC.Y:" << world_coord.y << endl;

            while(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(sf::Event::MouseButtonReleased){
                    //this will calculate the new position of the cursor
                    //will use this to calculate where the new
                    sf::Vector2i new_coords = sf::Mouse::getPosition();
                    cout << "DEBUG::newcoords:" << new_coords.x << "," << new_coords.y << endl;
                }
            }
        }

            //then create a new particle based on size
            //planet.new(timer);
            break;
        }
    }
}

void Animate::Update()
{
//    _command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);
    }
}

void Animate::Render()
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
