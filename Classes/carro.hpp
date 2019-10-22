#include <iostream>
#include <cstring>

using namespace std;

class Carro{
public:
    int doors;
    string color;
    string plate;
    double speed;
    

    void setDoors(int doors);
    void setColor(string color);
    void setPlate(string plate);
    void setSpeed(double speed);
    void accel(int value); //value equals to percentage to be increased;
    void brake(int value); //value equals to percentage to be decreased;

    int getDoors();
    string getColor();
    string getPlate();
    double getSpeed();
};


