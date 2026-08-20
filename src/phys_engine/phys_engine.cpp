#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "phys_engine.hpp"
#include "physics_functions.hpp"
/*
    a_t = a_t
    v_t = v_(t-1)+a_{t-1}
    x_t = x_{t-1}+v_t+(1/2)*a_t
*/
State * simulateProjectile(State initialState, float timeStep, float finalTime) {
    State * results = (State *) malloc(sizeof(State)*floor(finalTime/timeStep));
    State * currentState = &initialState;
    int resultCounter = 0;
    for (float timeCount = 0.0; timeCount < finalTime; timeCount = timeCount+timeStep) {
        currentState->initial_position_x = getFinalPositionWithAcceleration(currentState->initial_position_x,currentState->initial_velocity_x,timeStep,currentState->acceleration_x);
        currentState->initial_position_y = getFinalPositionWithAcceleration(currentState->initial_position_y,currentState->initial_velocity_y,timeStep,currentState->acceleration_y);
        currentState->initial_velocity_x = getFinalVelocity(currentState->initial_velocity_x, currentState->acceleration_x, timeStep);
        currentState->initial_velocity_y = getFinalVelocity(currentState->initial_velocity_y, currentState->acceleration_y, timeStep);
        results[resultCounter] = *currentState;
        resultCounter++;
    }
    return results;
}