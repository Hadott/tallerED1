#pragma once
#include <iostream>
#include "Usuario.h"
using namespace std;
class Normal: public Usuario{
    private:
        int edad;
        string correo;
    public:
        Normal(string,string,int,string);
        int getEdad();
        string getCorreo();

};
Normal::Normal(string nombre,string contrasena, int edad,string correo ) : Usuario(nombre,contrasena){
    this->edad = edad;
    this->correo = correo;
}
int Normal::getEdad()   {
    return this->edad;
}
string Normal::getCorreo(){
    return this->correo;
}

