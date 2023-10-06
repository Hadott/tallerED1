#pragma once
#include "Software.h"
#include <iostream>
using namespace std;
class Seguridad:public Software{
    private:
    string tipoMaleware;
    public:
    Seguridad(string,string,int,list<Usuario*>,float,string);
    string getTipoMalewareM();
    ~Seguridad();

};
Seguridad::Seguridad(string nombre,string dev,int clasificacion,list<Usuario*> usuarios,float precio,string tipoMaleware):Software(nombre,dev,clasificacion,usuarios,precio)
{
    this->tipoMaleware=tipoMaleware;
}
string Seguridad::getTipoMalewareM(){
    return this->tipoMaleware;
}
Seguridad::~Seguridad(){
    delete this;
}