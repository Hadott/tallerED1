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
    virtual void determinarTipo();
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
void Software::determinarTipo (){ 
    cout<<"El software es de tipo "<<endl;
}


Software::~Software()
{
    delete this;
    
}
