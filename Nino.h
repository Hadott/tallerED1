#pragma once
#include <iostream>
#include "Usuario.h"
using namespace std;
class Nino: public Usuario{
    private:
        int edad;

    public:
        Nino(string,string,int);
        int getEdad();
        ~Nino();

};
Nino::Nino(string nombre,string contrasena, int edad) : Usuario(nombre,contrasena){
    this->edad = edad;

}
int Nino::getEdad()   {
    return this->edad;
}
Nino ::~Nino(){
    delete this;
}

