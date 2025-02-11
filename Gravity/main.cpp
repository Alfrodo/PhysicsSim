#include <iostream>
#include <SFML/Graphics.hpp>
#include "Particle.h"
#include "GravitySource.h"
#include "UIManager.h"
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <sstream>
#include "Space.h"
#include <random>

UIManager UI;







int main()
{
    //Initialize Window and UI
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Simulation running...");
    window.setFramerateLimit(60);
    UI.initUI();

    //Init Space
    Space space = Space();
    //Init Objects and add to Space
    space.addGravitySource(new GravitySource(1200, 500, 15, 20000));
    space.addGravitySource(new GravitySource (400, 500, 15, 20000));
    


    //Add random spawned particles

    for (int i = 0; i < 5000; i++)
    {
        //Random Colors
        space.addParticle(new Particle (800, 200, 3, sf::Vector2f(6, 0.2 + (0.1 / 5000) * i), sf::Color(rand() % 255, rand() % 255, rand() % 255)));
        //space.addParticle(new Particle(800, 200, 3, sf::Vector2f(6, 0.2 + (0.1 / 5000) * i)));
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //Mouse wheel event
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {

                }
            }
        }

        std::ostringstream stream;





        //Gui stuff - useless rightnow
        //stream << std::setprecision(2) << std::fixed << particle.getVelocity();
        //UI.setVelocityText(stream.str());
        //stream.flush();
        //UI.setMassText(std::to_string(static_cast<int>(src.getStr())));



        //Render
        window.clear();
        space.renderAllObjects(window);
        space.updatePhysics();
        UI.renderUI(window);

        window.display();
    }

    return 0;
}

