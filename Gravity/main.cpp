#include <iostream>
#include <SFML/Graphics.hpp>
#include "Particle.h"
#include "GravitySource.h"
#include "UIManager.h"
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <sstream>

UIManager UI;







int main()
{
    //Initialize Window and UI
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Simulation running...");
    window.setFramerateLimit(60);
    UI.initUI();


    //Init Objects
    GravitySource src(800, 500, 15, 30000);
    Particle particle(500, 800, 5, sf::Vector2f(0,5));
    Particle particle2(500, 200, 5, sf::Vector2f(0, 5));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //Mouse wheel event
            if (event.type == sf::Event::MouseWheelMoved)
            {
                src.setStr(event.mouseWheel.delta * 200);
                src.setSize(src.getSize() + (event.mouseWheel.delta));
            }
        }

        std::ostringstream stream;

        stream << std::setprecision(2) << std::fixed << particle.getVelocity();
        UI.setVelocityText(stream.str());
        stream.flush();
        UI.setMassText(std::to_string(static_cast<int>(src.getStr())));



        //Render
        window.clear();
        src.render(window);
        particle.render(window);
        particle.updatePhysics(src);
        particle2.render(window);
        particle2.updatePhysics(src);
        UI.renderUI(window);

        window.display();
    }

    return 0;
}

