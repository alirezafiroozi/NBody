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
//    int size = planetVector.size();
    for(int i = 0; i < planetVector.size(); i++)
    {
        if(!it[i].isalive())
        {
//            cout << "\nDRAW:: alive: " << it[i].isalive();
            planetVector.erase(it + i);
            it = planetVector.begin();
            break;
        }
        for(int n = 0; n < planetVector.size(); n++)
        {
            if(n != i)
            {
                it[i].Acceleration(it[i].Force(it[n]));

                it[i].Collision(it[n]);
            }
        }
        it[i].Speed();
        it[i].Step();
        it[i].Draw(window);
    }
}

void System::Insert(Planet planet)
{
//    Planet p(planet);
    planetVector.push_back(planet);
}
