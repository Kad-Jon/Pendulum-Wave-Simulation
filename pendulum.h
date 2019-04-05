#ifndef PENDULUM_H
#define PENDULUM_H

#include <math.h>

//This is my virtual base class

class Pendulum {
public:

    Pendulum ();
    Pendulum (double,double,double); //Constructors

    virtual ~Pendulum(){} //Destructor

    virtual void Simulate(){} //Here Simulate is declared as Virtual and the body as no definition
    double CartconvertY ();
    double CartconvertX (); //Functions to retrieve cartesian coordinates of pendulum

    //Get and Set Method for the private Data Members

    double GetAngle  ()const {return fangle;}
    double GetLength ()const {return flength;}
    double GetTime () const {return ftime;}
    double GetMaxAngle () const {return fmaxangle;}
    double GetGravity () const {return fgravity;}

    void SetAngle (double);
    void SetLength (double);
    void SetMaxangle (double);
    void SetGravity (double);

    void incrementtime(); //Function to increase the 'time' of the simulation

    const double PI  = 3.141592653589793238463; //High accuracy definition of Pi

private:

    double fangle, flength, ftime=0;
    double fmaxangle,fgravity;

    //Private Datamembers

};

#endif //PENDULUM_H
