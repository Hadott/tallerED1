#pragma once
#include <iostream>
#include "Software.h"

using namespace std;

class Office:public Software
{
private:
    int cantArchivos;
public:
    Office(string,string,int,list<Usuario*>,float,int);
    int getCantArchivos();
    ~Office();
};

Office::Office(string nombre,string dev,int clasificacion,list<Usuario*> usuarios,float precio,int cantArchivos):Software(nombre,dev,clasificacion,usuarios,precio)
{
    this->cantArchivos=cantArchivos;
}
int Office::getCantArchivos(){
    return this->cantArchivos;
}
Office::~Office()
{
    delete this;
}
