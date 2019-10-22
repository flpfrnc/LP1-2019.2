#include "carro.hpp"

void Carro::setDoors(int doors){
    
    this->doors = doors;
}

void Carro::setColor(string color){

    this->color = color;
}

void Carro::setPlate(string plate){

    this->plate = plate;
}

void Carro::setSpeed(double speed){

    this->speed = speed;
}

int Carro::getDoors(){
   
    return this->doors;
}

string Carro::getColor(){
   
    return this->color;
}

string Carro::getPlate(){
   
    return this->plate;
}

double Carro::getSpeed(){

    return this->speed;
}

void Carro::accel(int value){
    this->speed += speed * value/100;
}
void Carro::brake(int value){
    this->speed -= speed * value/100;
}