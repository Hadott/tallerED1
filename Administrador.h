#pragma once
#include <iostream>
#include "Usuario.h"
using namespace std;
class Administrador: public Usuario{
    private:
        int edad;
        string correo;
        bool log;
    public:
        Administrador(string,string,int,string,bool);
        int getEdad();
        string getCorreo();
        bool getLog();
        ~Administrador();

};
Administrador::Administrador(string nombre,string contrasena, int edad,string correo, bool log ) : Usuario(nombre,contrasena){
    this->edad = edad;
    this->correo = correo;
    this->log= log;
}
int Administrador::getEdad()   {
    return this->edad;
}
string Administrador::getCorreo(){
    return this->correo;
}
bool Administrador::getLog(){
    return this->log;
}
Administrador::~Administrador()
{
    delete this;
}
