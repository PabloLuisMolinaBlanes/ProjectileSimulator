float getFinalPositionConstantVelocity(float initial_position, float velocity, float time) {
    return initial_position + velocity*time;
}

float getFinalPositionWithAcceleration(float initial_position, float velocity, float time, float acceleration) {
    return getFinalPositionConstantVelocity(initial_position, velocity, time) + 0.5*acceleration*(time*time);
}

float getFinalVelocity(float initial_velocity, float acceleration, float time) {
    return initial_velocity+acceleration*time;
}