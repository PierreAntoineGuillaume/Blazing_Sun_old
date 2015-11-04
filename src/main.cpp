#include <iostream>

#ifdef GRENABLED
    #include <SFML/Window.hpp>
#endif //GRENABLED

#include "Generic/ResourceManager/ResourceManager.h"
#include "Generic/Utility/vector3.hpp"

#include <stack>


using namespace std;
using nsRS::ResourceManager;


namespace
{

}
int main ()
{
    std::stack<std::vector<nsUtil::vector3U>> stack;
    std::vector<nsUtil::vector3U> test;


    cout << sizeof(stack) << endl;
    cout << "Hello, World!" << endl;

    ResourceManager *RSmanager = ResourceManager::Instance ();

#ifdef GRENABLED

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
#endif //GRENABLED


    return 0;
}