#include "system.h"
//#include "planet.h"
#include <iostream>

using namespace std;

System::System()
{
    cout << "System CTOR got called\n";
    Planet planet;

    //NEEDS TO GET COMPLETED

    cout << "System CTOR END!\n";

}

void System::Draw(sf::RenderWindow &window)
{
    window.clear();
    vector<Planet>::iterator it = planetVector.begin();
    int size = planetVector.size();
    for(int i = 0; i < size; i++)
    {
        it[i].Draw(window);
        it[i].Step();
    }
}

void System::Insert(Planet planet)
{
//    Planet p(planet);
    planetVector.push_back(planet);
}
