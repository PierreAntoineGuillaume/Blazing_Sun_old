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
    nsUtil::stdpoint p{0.f,2.f,0};
    stdpoint tester  {100.f,200.f};

    auto &&m = p.build_translation_matrix ();
    tester.apply_homogenous_coordinates_multiplication (m);

    sf::ContextSettings settings(0,0,16);
    /**/
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window",sf::Style::Default,settings);
    sf::ConvexShape rect1(4);
    sf::ConvexShape rect2(4);
    sf::ConvexShape rect3(4);
    sf::ConvexShape rect4(4);
    sf::ConvexShape rect5(4);
    sf::ConvexShape rect6(4);


    stdpoint A{200,200,000}, B{300,200,000}, D{200,500,000}, C{300,500,000};
    stdpoint E{200,200,100}, F{300,200,100}, H{200,500,100}, G{300,500,100};

    rect1.setPoint(0,p2sfp (A));
    rect1.setPoint(1,p2sfp (B));
    rect1.setPoint(2,p2sfp (C));
    rect1.setPoint(3,p2sfp (D));
    rect1.setFillColor (sf::Color::Red);

    rect2.setPoint(0,p2sfp (A));
    rect2.setPoint(1,p2sfp (B));
    rect2.setPoint(2,p2sfp (F));
    rect2.setPoint(3,p2sfp (E));
    rect2.setFillColor (sf::Color::Red);

    rect3.setPoint(0,p2sfp (C));
    rect3.setPoint(1,p2sfp (D));
    rect3.setPoint(2,p2sfp (H));
    rect3.setPoint(3,p2sfp (G));
    rect3.setFillColor (sf::Color::Red);

    rect4.setPoint(0,p2sfp (A));
    rect4.setPoint(1,p2sfp (C));
    rect4.setPoint(2,p2sfp (G));
    rect4.setPoint(3,p2sfp (E));
    rect4.setFillColor (sf::Color::Red);

    rect5.setPoint(0,p2sfp (E));
    rect5.setPoint(1,p2sfp (F));
    rect5.setPoint(2,p2sfp (H));
    rect5.setPoint(3,p2sfp (G));
    rect5.setFillColor (sf::Color::Red);

    rect6.setPoint(0,p2sfp (B));
    rect6.setPoint(1,p2sfp (D));
    rect6.setPoint(2,p2sfp (H));
    rect6.setPoint(3,p2sfp (F));
    rect6.setFillColor (sf::Color::Red);


    auto rotation1    = (stdpoint {0,0,1}).build_rotation_matrix (0.01f);
    auto rotation2    = (stdpoint {0,1,0}).build_rotation_matrix (0.01f);
    auto rotation3    = (stdpoint {1,0,0}).build_rotation_matrix (0.01f);


    window.setFramerateLimit (30);

    while (window.isOpen())
    {
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
        E.apply_homogenous_coordinates_multiplication (decal2);
        F.apply_homogenous_coordinates_multiplication (decal2);
        G.apply_homogenous_coordinates_multiplication (decal2);
        H.apply_homogenous_coordinates_multiplication (decal2);

        A.apply_homogenous_coordinates_multiplication (rotation1);
        B.apply_homogenous_coordinates_multiplication (rotation1);
        C.apply_homogenous_coordinates_multiplication (rotation1);
        D.apply_homogenous_coordinates_multiplication (rotation1);
        E.apply_homogenous_coordinates_multiplication (rotation1);
        F.apply_homogenous_coordinates_multiplication (rotation1);
        G.apply_homogenous_coordinates_multiplication (rotation1);
        H.apply_homogenous_coordinates_multiplication (rotation1);

        A.apply_homogenous_coordinates_multiplication (rotation2);
        B.apply_homogenous_coordinates_multiplication (rotation2);
        C.apply_homogenous_coordinates_multiplication (rotation2);
        D.apply_homogenous_coordinates_multiplication (rotation2);
        E.apply_homogenous_coordinates_multiplication (rotation2);
        F.apply_homogenous_coordinates_multiplication (rotation2);
        G.apply_homogenous_coordinates_multiplication (rotation2);
        H.apply_homogenous_coordinates_multiplication (rotation2);

        A.apply_homogenous_coordinates_multiplication (rotation3);
        B.apply_homogenous_coordinates_multiplication (rotation3);
        C.apply_homogenous_coordinates_multiplication (rotation3);
        D.apply_homogenous_coordinates_multiplication (rotation3);
        E.apply_homogenous_coordinates_multiplication (rotation3);
        F.apply_homogenous_coordinates_multiplication (rotation3);
        G.apply_homogenous_coordinates_multiplication (rotation3);
        H.apply_homogenous_coordinates_multiplication (rotation3);

        A.apply_homogenous_coordinates_multiplication (decal1);
        B.apply_homogenous_coordinates_multiplication (decal1);
        C.apply_homogenous_coordinates_multiplication (decal1);
        D.apply_homogenous_coordinates_multiplication (decal1);
        E.apply_homogenous_coordinates_multiplication (decal1);
        F.apply_homogenous_coordinates_multiplication (decal1);
        G.apply_homogenous_coordinates_multiplication (decal1);
        H.apply_homogenous_coordinates_multiplication (decal1);


        rect1.setPoint(0,p2sfp (A));
        rect1.setPoint(1,p2sfp (B));
        rect1.setPoint(2,p2sfp (C));
        rect1.setPoint(3,p2sfp (D));

        rect2.setPoint(0,p2sfp (A));
        rect2.setPoint(1,p2sfp (B));
        rect2.setPoint(2,p2sfp (F));
        rect2.setPoint(3,p2sfp (E));

        rect3.setPoint(0,p2sfp (C));
        rect3.setPoint(1,p2sfp (D));
        rect3.setPoint(2,p2sfp (H));
        rect3.setPoint(3,p2sfp (G));

        rect4.setPoint(0,p2sfp (A));
        rect4.setPoint(1,p2sfp (C));
        rect4.setPoint(2,p2sfp (G));
        rect4.setPoint(3,p2sfp (E));

        rect5.setPoint(0,p2sfp (E));
        rect5.setPoint(1,p2sfp (F));
        rect5.setPoint(2,p2sfp (G));
        rect5.setPoint(3,p2sfp (H));

        rect6.setPoint(0,p2sfp (B));
        rect6.setPoint(1,p2sfp (D));
        rect6.setPoint(2,p2sfp (H));
        rect6.setPoint(3,p2sfp (F));

        window.draw(rect1);
        window.draw(rect2);
        window.draw(rect3);
        window.draw(rect4);
        window.draw(rect5);
        window.draw(rect6);



        // End the current frame and display its contents on screen
        window.display();
    }

    /**/

    return 0;
}