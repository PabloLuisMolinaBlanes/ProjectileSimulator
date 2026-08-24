#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "phys_engine.hpp"
#include <stdio.h>

using sf::Event;
using sf::RenderWindow;
using sf::VideoMode;


#ifndef __TEST__
int main() {
    RenderWindow window(VideoMode({600, 600}), "Test1");
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<Event::Closed>()) {        
                window.close();
            }
        }
        window.display();
    }
}
#endif