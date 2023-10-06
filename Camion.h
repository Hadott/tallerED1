#pragma once
#include <iostream>
using namespace std;
class Camion{
    private:
       string id;
        int peso;
    
    public:
        Camion(string,int);
        //int getPeso();
        //string getID();
    
};
Camion::Camion(string id,int peso){
    this->id = id;
    this->peso=peso;
}
//int Camion::getPeso(){
  //  return this->peso;
//}
//string Camion::getID(){
  //  return this->id;
//}