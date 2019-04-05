#include "undampedpendulum.h"

UndampedPendulum::UndampedPendulum(double angle,double length,double gravity){
    SetMaxangle(angle);
    SetAngle(angle);
    SetLength(length);
    SetGravity(gravity);
}//As private data members aren't directly accessable to derived classes, SetMethods were used to pass the arguments of the constructor through

void UndampedPendulum::Simulate(){
    double angle;
    angle = GetMaxAngle()*cos(sqrt(GetGravity()/GetLength())*GetTime());
    SetAngle(angle);
    incrementtime();
} /*The Simulate function sets the angle to what it should be at a certain time At the end of the simulation step tim is
    incremented so that when simulate runs again (when QTimer calls it) the angle should progress as desired with respect to time*/


