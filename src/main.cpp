#include <iostream>

#include <SFML/Window.hpp>

#include "Generic/ResourceManager/ResourceManager.h"

using namespace std;
using nsRS::ResourceManager;

int main ()
{
    cout << "Hello, World!" << endl;

    nsInformation::FilePath a, b, c, d;

    nsInformation::InformationHolder e (GameObject());

    a.path_to_file = b.path_to_file = c.path_to_file = d.path_to_file = "../img/blabla.png";
    {
        int i {0};
        a.index = ++i;
        b.index = ++i;
        c.index = ++i;
        d.index = ++i;
    }



    e << a << b << c << d;

    ResourceManager *manager = ResourceManager::Instance ();


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