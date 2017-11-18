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
        if(it[i].isalive() == false)
        {
            cout << "\nDRAW:: alive: " << it[i].isalive();
//            planetVector.erase(it + i);
//            it = planetVector.begin();
        }
        for(int n = 0; n < size; n++)
        {
            if(n == i)
                break;
<<<<<<< HEAD
=======
//            if(it[n].isalive() == false)
//            break;
>>>>>>> c3163be10b0f1de332496b1031e2218e01c4ec33
            it[n].Acceleration(it[n].Force(it[i]));
            it[n].Speed();
            it[n].Step();
            it[i].Collision(it[n]);
            it[n].Draw(window);
            it[i].Collision(it[n]);
        }

    }
}

void System::Insert(Planet planet)
{
//    Planet p(planet);
    planetVector.push_back(planet);
}
