#define GRAVITY 9.8

struct initialState {
    float initial_position_x;
    float initial_position_y;
};

/*Simulates the trajectory of a single projectile in 2 dimensions*/
float simulateProjectile(struct initialState initial, float timeStep);