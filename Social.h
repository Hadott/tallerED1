#pragma once
#include "Software.h"
#include <iostream>
#include <list>
using namespace std;
class Social:public Software{
    private:
        list<Usuario*>amigos;
    public:
        Social(string nombre,string dev,int clasificacion,list<Usuario*> usuarios,float precio,list<Usuario*>amigos);
        list<Usuario*> getUsuarios();
        ~Social();
};
Social::Social(string nombre,string dev,int clasificacion,list<Usuario*> usuarios,float precio,list<Usuario*>amigos):Software(nombre,dev,clasificacion,usuarios,precio)
{
    this->amigos=amigos;
}
list<Usuario*> Social::getUsuarios(){
    return this->amigos;
}
Social::~Social(){
    delete this;
}