#ifndef DAMPEDPENDULUM_H
#define DAMPEDPENDULUM_H

#include "pendulum.h"

//Damped Pendulum Class, only has one extra data member

class DampedPendulum:public virtual Pendulum {
public:
    DampedPendulum();
    DampedPendulum(double,double,double,double);

    virtual ~DampedPendulum(){}

    void Simulate(); //Own Simulate declaration with a unique definition in the cpp

    double GetDamping () const {return fdamping;}

    void SetDamping (double);

    //relevent set and get methods


private:
    double fdamping; //member to determine degree of damping
};

#endif // DAMPEDPENDULUM_H

