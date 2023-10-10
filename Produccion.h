#pragma once
#include "Software.h"
#include <iostream>
using namespace std;
class Produccion:public Software
{
private:
    string tipoSolucion;
public:
    Produccion(string,string,int,list<Usuario*>,float,string);
    void determinarTipo()override;
    ~Produccion();
};

Produccion::Produccion(string nombre,string dev,int clasificacion,list<Usuario*> usuarios,float precio,string tipoSolucion):Software(nombre,dev,clasificacion,usuarios,precio)
{  
    this->tipoSolucion=tipoSolucion;

}
void Produccion::determinarTipo() {
    cout<<"El software es de tipo "<<endl;
}

    
Produccion::~Produccion()
{
    delete this;
}
