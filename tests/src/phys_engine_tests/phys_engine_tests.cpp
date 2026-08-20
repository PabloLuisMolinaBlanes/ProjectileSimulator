#include <gtest/gtest.h>
#include "math.h"
#include "phys_engine.hpp"

TEST(SampleParticleMovesProperlyII, BasicAssertions) {
    // Arrange
    State * state = (State *) malloc(sizeof(State));
    state->initial_position_x = 0;
    state->initial_velocity_x = 1.0;
    state->acceleration_x = 0;
    state->initial_position_y = 0;
    state->initial_velocity_y = 0;
    state->acceleration_y = 0;
    // Act
    float result = simulateProjectile(*state, 1.0, 5.0)[4].initial_position_x;
    // Assert
    EXPECT_EQ(5.0, result);
}

TEST(SampleParticleMovesProperlyIII, BasicAssertions) {
    // Arrange
    State * state = (State *) malloc(sizeof(State));
    state->initial_position_x = 0;
    state->initial_velocity_x = 1.0;
    state->acceleration_x = 0;
    state->initial_position_y = 0;
    state->initial_velocity_y = 0;
    state->acceleration_y = 0;
    // Act
    float result = simulateProjectile(*state, 0.2, 1.0)[4].initial_position_x;
    // Assert
    EXPECT_EQ(1.0, result);
}

TEST(SampleParticleMovesProperlyIV, BasicAssertions) {
    // Arrange
    State * state = (State *) malloc(sizeof(State));
    state->initial_position_x = 0;
    state->initial_velocity_x = 1.0;
    state->acceleration_x = 1.0;
    state->initial_position_y = 0;
    state->initial_velocity_y = 0;
    state->acceleration_y = 0;
    // Act
    float result = simulateProjectile(*state, 1.0, 5.0)[4].initial_position_x;
    // Assert
    EXPECT_EQ(17.5, result);
}