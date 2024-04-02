// Author: Zuhayer Tashin
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Lab 8A
// Write a new program invert.cpp that inverts all colors, so white shades become black, and black become white:
// Since black = 0, and white = 255, you should do the following transformation for each pixel color:

#include <iostream>
using namespace std;

// Class representing a 3D coordinate
class Coord3D 
{
    public:
        double x; // x-coordinate
        double y; // y-coordinate
        double z; // z-coordinate
};

// Class representing a particle with position and velocity
class Particle : public Coord3D
{
    public:
        double vx, vy, vz; // velocity components
};

// Function to dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z, 
                         double vx, double vy, double vz);

// Function to set the velocity of a particle
void setVelocity(Particle *p, double vx, double vy, double vz);

// Function to get the current position of a particle
Coord3D getPosition(Particle *p);

// Function to update a particle's position after elapsed time dt
void move(Particle *p, double dt);

// Function to delete all memory allocated for a particle
void deleteParticle(Particle *p);

int main() 
{
    // Create a new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // Update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // Move the particle
        move(p, dt);
        time += dt;

        // Report its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // Remove the particle, deallocating its memory
    deleteParticle(p);
}

// Function definitions

// Function to create a new particle and initialize its coordinates and velocity
Particle* createParticle(double x, double y, double z, 
                        double vx, double vy, double vz)
{
    Particle *p = new Particle;
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    return p;
}

// Function to set the velocity of a particle
void setVelocity(Particle *p, double vx, double vy, double vz)
{
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
}

// Function to get the current position of a particle
Coord3D getPosition(Particle *p)
{
    Coord3D pos;
    pos.x = p->x;
    pos.y = p->y;
    pos.z = p->z;
    return pos;
}

// Function to update a particle's position based on its velocity over a given time
void move(Particle *p, double dt)
{
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

// Function to delete a particle and deallocate its memory
void deleteParticle(Particle *p)
{
    delete p;
}
