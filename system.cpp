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
    vector<Planet>::iterator it = planetVector.begin();
    int size = planetVector.size();
    for(int i = 0; i < size; i++)
    {
        for(int n = 0; n < size; n++)
        {
            it[n].Acceleration(it[n].Force(it[i]));
            it[n].Speed();
            it[n].Step();
            it[n].Draw(window);
        }
//        it[i].Draw(window);

    }
}

void System::Insert(Planet planet)
{
//    Planet p(planet);
    planetVector.push_back(planet);
}
