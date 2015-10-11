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


    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (window.isOpen())
    {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }


    return 0;
}