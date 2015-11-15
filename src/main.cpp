#include <iostream>
#include <iomanip>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/ContextSettings.hpp>


#include "Generic/ResourceManager/ResourceManager.h"
#include "Generic/Utility/point.hpp"


using namespace std;
using nsRS::ResourceManager;
using namespace nsUtil;

namespace
{

    template <typename iter_t>
    void printer (iter_t b,iter_t e)
    {

        for (iter_t i = b;i!=e;++i)
        {
            for (auto j = i->begin();j!= i->end();++j)
                cout << setw(10) << *j;
            cout << endl;
        }
        cout << endl;
    }

    sf::Vector2f p2sfp (const stdpoint & point)
    {
        return sf::Vector2f(point[0],point[1]);
    }


}
int main ()
{

//    ResourceManager *RSmanager = ResourceManager::Instance ();
    cout << "test" << endl;
    stdpoint zero {0.f,0.f,0.f};
    nsUtil::stdpoint p{0.f,2.f};
    stdpoint tester  {100.f,200.f};

    auto &&m = p.build_translation_matrix ();
    tester.apply_homogenous_coordinates_multiplication (m);

    sf::ContextSettings settings(0,0,16);
    /**/
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window",sf::Style::Default,settings);
    sf::ConvexShape rect(4);

    stdpoint A{200,200}, B{300,200}, D{200,500}, C{300,500};

    rect.setPoint(0,p2sfp (A));
    rect.setPoint(1,p2sfp (B));
    rect.setPoint(2,p2sfp (C));
    rect.setPoint(3,p2sfp (D));
    rect.setFillColor (sf::Color::Red);

//    auto translation = (stdpoint {0.f,10.f}).build_translation_matrix ();
    auto rotation    = (stdpoint {1.f,0.f}).build_rotation_matrix (0.01f);

    printer(rotation.begin(),rotation.end());


    window.setFramerateLimit (30);
    while (window.isOpen())
    {
        auto transform = rotation;
        // Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear the whole window before rendering a new frame
        window.clear(sf::Color::White);
        // Draw some graphical entities

        stdpoint center = (A + B + C + D)/4;
        stdpoint reverse = zero - center;


        auto decal1 = center.build_translation_matrix ();
        auto decal2 = reverse.build_translation_matrix ();

        A.apply_homogenous_coordinates_multiplication (decal2);
        B.apply_homogenous_coordinates_multiplication (decal2);
        C.apply_homogenous_coordinates_multiplication (decal2);
        D.apply_homogenous_coordinates_multiplication (decal2);

        A.apply_homogenous_coordinates_multiplication (transform);
        B.apply_homogenous_coordinates_multiplication (transform);
        C.apply_homogenous_coordinates_multiplication (transform);
        D.apply_homogenous_coordinates_multiplication (transform);

        A.apply_homogenous_coordinates_multiplication (decal1);
        B.apply_homogenous_coordinates_multiplication (decal1);
        C.apply_homogenous_coordinates_multiplication (decal1);
        D.apply_homogenous_coordinates_multiplication (decal1);


        rect.setPoint(0,p2sfp (A));
        rect.setPoint(1,p2sfp (B));
        rect.setPoint(2,p2sfp (C));
        rect.setPoint(3,p2sfp (D));

        window.draw(rect);

        // End the current frame and display its contents on screen
        window.display();
    }

    /**/

    return 0;
}