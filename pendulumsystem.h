#ifndef PENDULUMSYSTEM_H
#define PENDULUMSYSTEM_H

#include "undampedpendulum.h"
#include "dampedpendulum.h"
#include <vector>

//A class used to produce and collect a vector of Pendula of either type

class PendulumSystem:public virtual Pendulum{
public:
    PendulumSystem();
    PendulumSystem(int, bool,double,double,double,double);
    virtual ~PendulumSystem();

    void Simulate(); //Once again Simulate is declared

    double GetNumber() const {return fnumber;}
    Pendulum GetPendulum(int);
    double GetScale(){return fScale;}

private:

    int fnumber; //tracking size of the vector
    std::vector <Pendulum*> fPendulum; //a vector filled with pointers of type Pendulum, has polymorphic properties
    double fScale; //to determine size of the screen

};

#endif // PENDULUMSYSTEM_H
