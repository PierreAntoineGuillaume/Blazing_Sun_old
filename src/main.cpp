#include <iostream>

#include <SFML/Window.hpp>

#include "Generic/ResourceManager/ResourceManager.h"
#include "Generic/Utility/point.hpp"

#include <stack>


using namespace std;
using nsRS::ResourceManager;


namespace
{

}
int main ()
{
    nsUtil::geometric_point<int,2> a {{1},{3}};
    cout << "test : " << endl;
    cout << a[1] << endl;

    std::stack<std::vector<nsUtil::stdpoint>> stack;
    std::vector<nsUtil::stdpoint> test;

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