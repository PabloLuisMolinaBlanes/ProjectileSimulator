#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "phys_engine.hpp"
#include <math.h>
#include <stdio.h>

using sf::Event;
using sf::RenderWindow;
using sf::VideoMode;
using sf::RectangleShape;
using sf::Clock;
using sf::Color;

struct Point {
    float x;
    float y;
};

sf::RectangleShape initShape(int pos_x, int pos_y) {
    sf::RectangleShape shape(sf::Vector2f(20.0f, 20.0f));
    shape.setPosition(sf::Vector2f(pos_x,pos_y));
    return shape;
}

class Projectile {
    public:
        float actual_x;
        float actual_y;
        float x;
        float y;
        float t = 0;
        sf::RectangleShape shape;
        void move(float screen_x, float screen_y, float dx, float dy) {
            actual_x += dx;
            actual_y += dy;
            if (actual_x > screen_x) {
                x = screen_x-20;
            } else if (actual_x < 0) {
                x = 20;
            } else {
                x = actual_x;
            }
            if (actual_y > screen_y) {
                y = screen_y-20;
            } else if (actual_y < 0) {
                y = 20;
            } else {
                y = actual_y;
            }
            shape.setPosition(sf::Vector2f(x, y));
        }
};

Projectile initProjectile(int projectile_x, int projectile_y) {
    Projectile projectile;
    projectile.x = projectile_x;
    projectile.y = projectile_y;
    projectile.actual_x = projectile.x;
    projectile.actual_y = projectile.y;
    projectile.shape = initShape(projectile.x, projectile.y);
    return projectile;
}
int stateCounter = 1;
#ifndef __TEST__
int main() {
    sf::Clock clock;
    int ms_waittime = 17;
    Projectile projectile;
    State * state = (State *) malloc(sizeof(State));
    state->initial_position_x = 0;
    state->initial_velocity_x = 50;
    state->acceleration_x = 0;
    state->initial_position_y = 0;
    state->initial_velocity_y = 40;
    state->acceleration_y = -9.8;
    float timeStep = 0.1;
    float finalTime = 10;
    State * resultStates = (State *) simulateProjectile(*state, timeStep, finalTime);
    int totalCount = floor(finalTime/timeStep);
    if (totalCount <= 1) {
        printf("Error, no trajectory to show here; closing\n");
        exit(-1);
    }
    projectile = initProjectile(0.0f, 580.0f);
    RenderWindow window(VideoMode({600, 600}), "SFMLWindow");
    while (window.isOpen()) {
        while (clock.getElapsedTime().asMilliseconds() < ms_waittime) {
            while (const std::optional event = window.pollEvent()) {
                if (event->is<Event::Closed>()) {        
                    window.close();
                }
            }
        }
        window.clear(Color::Black);
        if (stateCounter < totalCount) {
            projectile.move(600,600,(resultStates[stateCounter].initial_position_x-resultStates[stateCounter-1].initial_position_x), (-(resultStates[stateCounter].initial_position_y-resultStates[stateCounter-1].initial_position_y)));
            stateCounter++;
        }
        window.draw(projectile.shape);
        window.display();
        clock.restart();
    }
}
#endif