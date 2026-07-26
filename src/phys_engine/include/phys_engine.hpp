#define GRAVITY 9.8

typedef struct State {
    float initial_position_x;
    float initial_velocity_x;
    float acceleration_x;
    float initial_position_y;
    float initial_velocity_y;
    float acceleration_y;
} State;

/*Simulates the trajectory of a single projectile in 2 dimensions*/
float simulateProjectile(struct State initial, float timeStep);