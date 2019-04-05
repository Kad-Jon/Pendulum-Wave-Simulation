#include "pendulumsystem.h"

PendulumSystem::PendulumSystem(){
    fnumber = 0;
}

PendulumSystem::PendulumSystem(int number,bool button,double mangle,double gravity,double mlength,double damping){
fnumber = number;
     double f = sqrt((gravity)/(mlength))/(2*PI);


        if (button==true&& number>0){

            for(int i = 0; i < number; i++){
                double L = (gravity)/(4*PI*PI*(f+i*0.005)*(f+i*0.005));
                DampedPendulum*J = new DampedPendulum((PI*mangle)/180,L,gravity,damping);
                fPendulum.push_back(J);
            }

        } else if (button == false  && number > 0){

            for(int i = 0; i < number; i++){
                double L = (gravity)/(4*PI*PI*(f+i*0.005)*(f+i*0.005));
                UndampedPendulum* J = new UndampedPendulum((PI*mangle)/180,L,gravity);
                fPendulum.push_back(J);
        }
}
       fScale = 2*mlength*cos(mangle)*0.01;
} //generates the desired pendulums and fills the vector with it

void PendulumSystem::Simulate(){
    for(int i = 0; i < fnumber;i++)
    fPendulum[i] ->Simulate();

} //Accesses the simulation of whichever class fills the vector for each object

Pendulum PendulumSystem::GetPendulum(int i){
    return *fPendulum[i];
} //returns pendulum

PendulumSystem::~PendulumSystem(){
    for(int i = 0; i < fnumber; i++){
        delete fPendulum[fnumber - i];
        fPendulum.pop_back();
    }
} //Destructor that deletes the entire vector
