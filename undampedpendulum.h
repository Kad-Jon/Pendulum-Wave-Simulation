#ifndef UNDAMPEDPENDULUM_H
#define UNDAMPEDPENDULUM_H

#include "pendulum.h"

//Derived Class from Pendulum

class UndampedPendulum: public virtual Pendulum{ //virtual inheritence
public:
    UndampedPendulum();
    UndampedPendulum(double,double,double);

    virtual ~UndampedPendulum(){}

    void Simulate(); //non virtual Simulate declaration with unique definition in the cpp

};

//There are no new data members to speak of

#endif // UNDAMPEDPENDULUM_H
