#include <iostream>
#include <cmath>
#include "pendulum.h"

//Definition of the default and custom  constructor

Pendulum::Pendulum():
    fangle(PI/4),flength(10),fmaxangle(PI/4){}

Pendulum::Pendulum(double anglemax, double lengthmax,double gravity):
    fangle((anglemax*PI)/180),flength(lengthmax),fmaxangle((anglemax*PI)/180),fgravity(gravity){}

//Definitions of methods, note Simulation remains undefine

double Pendulum::CartconvertY(){
    return flength*cos(fangle);
}

double Pendulum::CartconvertX(){
    return flength*sin(fangle);
}

void Pendulum::SetAngle(double Angle){
    fangle = Angle;
}

void Pendulum::SetLength(double Length){
    flength = Length;
}

void Pendulum::SetMaxangle(double mangle){
    fmaxangle = mangle;
}

void Pendulum::SetGravity(double gravity){
    fgravity = gravity;
}

void Pendulum::incrementtime(){
    ftime += 0.01;
}
