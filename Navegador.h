#pragma once
#include "Software.h"
#include <iostream>
#include <list>
using namespace std;
class Navegador:public Software{
    private:
        list<string> historial;
    public:
        Navegador(string,string,int,list<Usuario*>,float,list<string>);
        list<string> getHistorial();
        ~Navegador();
};
Navegador::Navegador(string nombre,string dev,int clasificacion,list<Usuario*> usuarios,float precio,list<string> historial):Software(nombre,dev,clasificacion,usuarios,precio)
{  
 this->historial=historial;
   
}
list<string> Navegador::getHistorial(){
    return this->historial;
}
Navegador::~Navegador(){
    delete this;
}
    
