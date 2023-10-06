#pragma once
#include <iostream>
using namespace std;
class Usuario{
    protected:
        string nombre;
        string contrasena;
    public:
        Usuario(string,string);
        string getNombre();
        string getContrasena();
};
Usuario::Usuario(string nombre, string contrasena){
    this->nombre = nombre;
    this->contrasena = contrasena;
}
string Usuario::getNombre(){
    return nombre;
}
string Usuario::getContrasena(){
    return contrasena;
}



