#pragma once
#include "Software.h"
#include <iostream>
using namespace std;
class Juego:public Software
{
private:
    string genero;
public:
    Juego(string,string,int,list<Usuario*>,float,string);
    ~Juego();
};

Juego::Juego(string nombre,string dev,int clasificacion,list<Usuario*> usuarios,float precio,string genero):Software(nombre,dev,clasificacion,usuarios,precio)
{
    this->genero=genero;
}

Juego::~Juego()
{
    delete this;
}
