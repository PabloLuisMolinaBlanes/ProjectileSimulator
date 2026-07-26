/*X_f = X_0+V*t; with X_f being the initial position of the particle, X_0 being the position of the particle at time t=0, V being a constant expressing velocity, and t being time*/
float getFinalPositionConstantVelocity(float initial_position, float velocity, float time);

/**/
float getFinalPositionWithAcceleration(float initial_position, float velocity, float time, float acceleration);

float getFinalVelocity(float initial_velocity, float acceleration, float time);