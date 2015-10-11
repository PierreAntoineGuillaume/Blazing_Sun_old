#include <iostream>

#include <SFML/Window.hpp>

#include "Generic/ResourceManager/ResourceManager.h"
#include "Generic/Utility/vector3.h"

#include <stack>

using namespace std;
using nsRS::ResourceManager;


namespace
{

}
int main ()
{
    std::stack<std::vector<nsUtil::vector3>> stack;
    std::vector<nsUtil::vector3> test;


    cout << sizeof(stack) << endl;
    cout << "Hello, World!" << endl;

    ResourceManager *RSmanager = ResourceManager::Instance ();


    sf::Window window(sf::VideoMode(800, 600), "My window");


    // on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
    while (window.isOpen())
    {
        // on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
        sf::Event event;
        while (window.pollEvent(event))
        {
            // �v�nement "fermeture demand�e" : on ferme la fen�tre
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }


    return 0;
}