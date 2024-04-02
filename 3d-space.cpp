// Author: Zuhayer Tashin
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Lab 8A
// Write a new program invert.cpp that inverts all colors, so white shades become black, and black become white:
// Since black = 0, and white = 255, you should do the following transformation for each pixel color:

#include <iostream>
#include <math.h>
using namespace std;

// Class representing a 3D coordinate
class Coord3D {
public:
    double x; // x-coordinate
    double y; // y-coordinate
    double z; // z-coordinate
};

// Function to calculate the length of a 3D vector represented by a Coord3D object
double length(Coord3D *p);

// Function to determine which of two points is farther from the origin
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);

// Function to move a point in 3D space based on its velocity over a given time
void move(Coord3D *ppos, Coord3D *pvel, double dt);

// Function to allocate memory for a Coord3D object and initialize its coordinates
Coord3D* createCoord3D(double x, double y, double z);

// Function to deallocate memory for a Coord3D object
void deleteCoord3D(Coord3D *p);

int main() {
    // Variables to store user input for position and velocity
    double x, y, z;

    // Get user input for position
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);

    // Get user input for velocity
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    // Move the point based on its velocity over 10 seconds
    move(ppos, pvel, 10.0);

    // Output the new coordinates after the move
    cout << "Coordinates after 10 seconds: "
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    // Free memory for the Coord3D objects
    deleteCoord3D(ppos);
    deleteCoord3D(pvel);
}

// Function to allocate memory for a Coord3D object and initialize its coordinates
Coord3D* createCoord3D(double x, double y, double z){
    Coord3D *p = new Coord3D;
    p->x = x;
    p->y = y;
    p->z = z;
    return p;
}

// Function to deallocate memory for a Coord3D object
void deleteCoord3D(Coord3D *p){
    delete p;
}

// Function to move a point in 3D space based on its velocity over a given time
void move(Coord3D *ppos, Coord3D *pvel, double dt){
    ppos->x += pvel->x * dt;
    ppos->y += pvel->y * dt;
    ppos->z += pvel->z * dt;
}

// Function to determine which of two points is farther from the origin
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    // Calculate the lengths of the vectors from the origin to each point
    double length1 = length(p1);
    double length2 = length(p2);

    // Return a pointer to the point that is farther from the origin
    if (length1 > length2) {
        return p1;
    } else {
        return p2;
    }
}

// Function to calculate the length of a 3D vector represented by a Coord3D pointer
double length(Coord3D *p) {
    // Calculate the length using the Euclidean distance formula
    return sqrt(p->x * p->x + p->y * p->y + p->z * p->z);
}