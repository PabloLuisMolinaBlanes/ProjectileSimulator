#include <gtest/gtest.h>
#include "physics_functions.hpp"

TEST(SampleParticleMovesProperly, BasicAssertions) {
    // Arrange
    float initial_position = 0.0;
    float velocity = 5.0;
    float time = 2.0;
    // Act
    bool result = getFinalPositionConstantVelocity(initial_position, velocity, time) == 10.0;
    // Assert
    EXPECT_EQ(true, result);
}