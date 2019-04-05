#include "dampedpendulum.h"

//Constructor for derived class

DampedPendulum::DampedPendulum(double angle,double length,double gravity,double damping){
    SetMaxangle(angle);
    SetAngle(angle);
    SetLength(length);
    SetGravity(gravity);
    fdamping = damping;
} //As private data members aren't directly accessable to derived classes, SetMethods were used to pass the arguments of the constructor through

void DampedPendulum::Simulate(){

    double angle;
    angle = GetMaxAngle()*cos(sqrt(GetGravity()/GetLength())*GetTime())*exp(-fdamping*GetTime());
    SetAngle(angle);
    incrementtime();
} /*The simulation runs like it does in undamped pendulum but the function is multiplied by a decaying exponential whose argument is time so
decay is reasonable simulated */

void DampedPendulum::SetDamping(double damping){
    fdamping = damping;
}


