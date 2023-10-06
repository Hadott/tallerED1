#pragma once
#include <iostream>
#include <list>
#include "Usuario.h"

using namespace std;

class Software
{
private:
    string nombre;
    string dev;
    int clasificacion;
    list<Usuario*>usuarios;
    float precio;
    
public:
    Software(string,string,int,list<Usuario*>,float);
    string getNombre();
    string getDev();
    int getClasificacion();
    list<Usuario*> getUsuarios();
    ~Software();
};

Software::Software(string nombre,string dev,int clasificacion,list<Usuario*> usuarios,float precio)
{
    this->nombre=nombre;
    this->dev=dev;
    this->clasificacion=clasificacion;
    this->usuarios=usuarios;
    this->precio=precio;
    
}
string Software::getNombre(){
    return nombre;
}
list<Usuario*> Software::getUsuarios(){
    return usuarios;
}


Software::~Software()
{
    delete this;
    
}
