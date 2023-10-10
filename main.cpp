#include <iostream>
#include <list>
#include"Usuario.h"
#include "Administrador.h"
#include "Normal.h"
#include "Nino.h"
#include "Software.h"
#include "Juego.h"
#include "Office.h"
#include "Produccion.h"
#include "Navegador.h"
#include "Seguridad.h" 
#include "Social.h"

using namespace std;



void determinarTipo(Software* software) {
    if (Produccion* produccion = dynamic_cast<Produccion*>(software)) {
        cout << "El software es de tipo Produccion." <<endl;
    } else {
        cout << "El software no es de tipo Produccion." <<endl;
    }
}
list<Software*> llenarMisSoftwares(Usuario* tu,list<Software*> misSoftwares,list<Software*> softwares){
    /**
 * Llena la lista 'misSoftwares' con objetos de software que tienen al usuario dado como uno de sus usuarios.
 *
 * Return:La lista 'misSoftwares' actualizada con los objetos de software coincidentes.
 *
 * 
 */
    for (Software *s : softwares){
        for(Usuario *u : s->getUsuarios()){
            if (tu==u){
                misSoftwares.push_back(s);
            }
        }  
    }
    return misSoftwares;
}
list <Software*> eliminarSoft(Usuario* tu,list<Software*> misSoftwares,list<Software*> softwares){
    /*
     * Elimina el software de la lista 'misSoftwares' que elija el usuario.
     * 
     * Return:La lista 'misSoftwares' actualizada con el software eliminado.
     * 
     * 
     */
    string nombre;
    cout<<"What software do you want to delete?"<<endl;
    for (Software *s : misSoftwares){
        cout<<s->getNombre()<<endl;
    }
    cin>>nombre;
    for (list<Software*>::iterator it = misSoftwares.begin(); it != misSoftwares.end(); ) {
        if ((*it)->getNombre() == nombre) {
            it = misSoftwares.erase(it); // Eliminar el software de la lista
            break;
        } else {
            ++it;
        }
    }
    return misSoftwares;
}
list <Software*> instalarSoft(Usuario* tu,list<Software*> misSoftwares,list<Software*> softwares){
    /*
     * Agrega el software de elegido por el usuario a la lista 'misSoftwares'.
     * 
     * Return:La lista 'misSoftwares' actualizada con el software agregado.
     * 
     * 
     */
    string nombre;
    cout<<"What software do you want to install?"<<endl;
    for (Software *s : softwares){
        cout<<s->getNombre()<<endl;
    }
    cin>>nombre;
    for (Software *s : softwares){
        if (nombre==s->getNombre()){

            misSoftwares.push_back(s);
            break;
        }
    }
    return misSoftwares;
}
Usuario* login(list <Usuario*> usuarios){
    /*
    * Logea al usuario usando un booleano que dice si se ha logeado o no.
    * 
    * Return:El usuario que se ha logeado.
    *
    */

    string user,pass;
    bool log = false;
    Usuario *tu = NULL;
    while (log==false)
    {
        cout<<"Username: ";
        cin>>user;
        cout<<"Password: ";
        cin>>pass;
        for (Usuario *u : usuarios){   
            if (u->getNombre()==user && u->getContrasena()==pass){
                log=true;
                cout<<"Logged in, Welcome "<<u->getNombre()<<endl;
                tu = u;
                break;
            }

        }
    }
    cout<<tu->getNombre()<<endl;
    return tu;
}
void menuPrincipal(Usuario* tu,list<Software*> softwares,list<Software*> misSoftwares,list<Usuario*> usuarios){
    /*
     * Menu principal del programa.
     *
     */
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"Softwares: "<<endl;
    for (Software *s : misSoftwares){
        cout<<s->getNombre()<<endl;
    }
    cout<<"What do you want to do?"<<endl;
    cout<<"1. Install software"<<endl;
    cout<<"2. Delete software"<<endl;
    cout<<"3. Login"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    int op;
    cin>>op;
    /*Switch statement que controla las opciones del menu principal*/
    switch (op){
        case 1:
            misSoftwares = instalarSoft(tu,misSoftwares,softwares);
            break;
        case 2:
            misSoftwares = eliminarSoft(tu,misSoftwares,softwares);
            break;
        case 3:
            /**
             * Crea un nuevo usuario actual "tu".
             * Limpia la lista de mis softwares.
             * Llena la lista de mis softwares con los softwares del usuario "tu".
            */
            tu = login(usuarios);
            misSoftwares.clear();
            misSoftwares =llenarMisSoftwares(tu,misSoftwares,softwares);
            break;
        case 4:
            /**
             * Sale del programa.
             */
            return;
    }
    menuPrincipal(tu,softwares,misSoftwares,usuarios);
}

int main() {
    /**
     * Main
     * 
     * Crea una lista de usuarios.
     * Crea una lista de softwares.
     * Crea a los usuarios y los agregas a la lista de usuarios.
     * Crea a los softwares y los agregas a la lista de softwares.
    */
    
    list<Usuario*> usuarios;
    list<Software*> softwares;

    Usuario *a = new Administrador("A","1234",35,"a@gmail.com",true);
    usuarios.push_back(a);
    Usuario *n1 = new Nino("Cote","1234",8);
    usuarios.push_back(n1);
    Usuario *n2 = new Nino("Nani","1234",12);
    usuarios.push_back(n2);
    Usuario *n3 = new Nino("Jade","1234",2);
    usuarios.push_back(n3);
    Usuario *n4 = new Nino("Bruno","1234",7);
    usuarios.push_back(n4);
    Usuario *p1 = new Normal("Pepe","1234",25,"pepe@gmail");
    usuarios.push_back(p1);
    Usuario *p2 = new Normal("Pinto","1234",26,"pinto@gmail");
    usuarios.push_back(p2);
    Usuario *p3 = new Normal("Dani","1234",20,"dani@gmail");
    usuarios.push_back(p3);
    Usuario *p4 = new Normal("Jose","1234",30,"jose@gmail");
    usuarios.push_back(p4);
    Usuario *p5 = new Normal("Herman","1234",40,"herman@gmail");
    usuarios.push_back(p5);
    Usuario *p6 = new Normal("Martina","1234",89,"martina@gmail");
    usuarios.push_back(p6);
    Usuario *p7 = new Normal("Jess","1234",50,"jess@gmail");
    usuarios.push_back(p7);
    Usuario *p8 = new Normal("Lola","1234",70,"lola@gmail");
    usuarios.push_back(p8);
    Usuario *p9 = new Normal("Lucia","1234",80,"lucia@gmail");
    usuarios.push_back(p9);
    Usuario *p10 = new Normal("Maria","1234",43,"maria@gmail");
    usuarios.push_back(p10);
    Usuario *p11 = new Normal("Pedro","1234",25,"pedro@gmail");
    usuarios.push_back(p11);
    Usuario *p12 = new Normal("Juan","1234",65,"juan@gmail");
    usuarios.push_back(p12);
    Usuario *p13 = new Normal("Ana","1234",45,"ana@gmail");
    usuarios.push_back(p13);
    Usuario *p14 = new Normal("Pablo","1234",27,"pablo@gmail");
    usuarios.push_back(p14);
    Usuario *p15 = new Normal("Hugo","1234",76,"hugo@gmail");
    usuarios.push_back(p15);
    Software *j1= new Juego("WarcraftIII","Blizzard",16,{p10,p11} ,60.0,"RTS");
    Software *j2 = new Juego("Warcraft","Blizzard",16,{p13} ,50.0,"RTS");
    Software *j3 = new Juego("Counter Strike Global Offensive","Valve",18,{p13,p3} ,50.0,"FPS");
    Software *j4 = new Juego("Counter Strike Global Offensive 2","Valve",18,{p13} ,50.0,"FPS");
    Software *j5 = new Juego("World of Warcraft","Blizzard",16,{p2,p3,p4,p11} ,50.0,"MMORPG");
    Software *j6 = new Juego("League of Legends","Riot Games",5,{p11} ,50.0,"MOBA");
    Software *j7 = new Juego("Dota2","Valve",18,{p5} ,50.0,"MOBA");
    Software *j8 = new Juego("Black Desert","Koei Tecmo",18,{p6} ,50.0,"MMORPG");
    Software *j9 = new Juego("HeartStone","Blizzard",5,{p7,p2} ,50.0,"Cards"); 
    Software *j10 = new Juego("Gwent","CD Projekt",5,{p1,p2} ,50.0,"Cards");
    Software *j11 = new Juego("Amnesia","Frictional Games",18,{p2,p3,p5} ,50.0,"Horror");
    Software *j12 = new Juego("Project Zero","Frictional Games",18,{p9} ,50.0,"Horror");
    Software *j13 = new Juego("Super Mario World","Nintendo",5,{p7,p6} ,50.0,"Platformer");
    Software *j14 = new Juego("Sonic","Sega",5,{p2,p5,p10} ,50.0,"Platformer");
    Software *j15 = new Juego("Fifa02","Electronic Arts",5,{p10,p2} ,50.0,"Sports");
    Software *j16 = new Juego("Fifa14","Electronic Arts",5,{p10,p2} ,50.0,"Sports");
    Software *j17 = new Juego("TheElderScrolls","Bethesda",18,{p3} ,50.0,"RPG");
    Software *j18 = new Juego("TheElderScrollsOnline","Bethesda",18,{p5} ,50.0,"RPG");
    Software *j19 = new Juego("Time Commando"," Adeline Software International",18,{p2} ,50.0,"Adventure");
    Software *j20 = new Juego("Unreal Tournament"," Epic Games",18,{p5} ,50.0,"FPS");
    Software *o1 = new Office("PowerPoint","Microsoft",0,{p2,p3,p4} ,50.0,2);
    Software *o2 = new Office("Excel","Microsoft",0,{p2,p3,p4} ,30.0,2);
    Software *o3 = new Office("Word","Microsoft",0,{p2,p3,p4} ,30.0,2);
    Software *o4 = new Office("Access","Microsoft",0,{p2,p3,p4} ,30.0,2);
    Software *o5 = new Office("Project","Microsoft",0,{p2,p3,p4} ,30.0,2);
    Software *pr1 = new Produccion("Vegaspro","Vegas",18,{p2,p3,p4} ,30.0,"Video");
    Software *pr2 = new Produccion("FL Studio","FL",18,{p2,p3,p4} ,30.0,"Musica");
    Software *pr3 = new Produccion("Adobe PhotoShop","Adobe",18,{p2,p3,p4} ,30.0,"Fotos");
    Software *pr4 = new Produccion("OBS","Obs",18,{p2,p3,p4} ,30.0,"Streaming");
    Software *na1 = new Navegador("Chrome","Google",0,{p2,p3,p4} ,30.0,{"a"});
    Software *na2 = new Navegador("Opera","Opera",0,{p2,p3,p4} ,30.0,{"a","b"});
    Software *s1 = new Seguridad("Windows Defender","Microsoft",0,{p2,p3,p4} ,30.0,"Ransomwares");
    Software *s2 = new Seguridad("Kaspers","Kaspers",0,{p2,p3,p4} ,30.0,"Botnets");
    Software *s3 = new Seguridad("McAfee","McAfee",0,{p2,p3,p4} ,30.0,"Troyanos");
    Software *s4 = new Seguridad("Avast","Avast",0,{p2,p3,p4} ,30.0,"Gusanos");
    Software *s5 = new Seguridad("Norton","Norton",0,{p2,p3,p4} ,30.0,"Rootkits");
    Software *s6 = new Seguridad("Avira","Avira",0,{p2,p3,p4} ,30.0,"Sypwares");
    Software *sc1 = new Social("Facebook","Facebook",0,{p2,p3,p4} ,30.0,{p1,p2,p3});
    Software *sc2 = new Social("Twitter","Twitter",0,{p2,p3,p4} ,30.0,{p1,p2,p3,p4,p5});
    softwares.push_back(j1);
    softwares.push_back(j2);
    softwares.push_back(j3);
    softwares.push_back(j4);
    softwares.push_back(j5);
    softwares.push_back(j6);
    softwares.push_back(j7);
    softwares.push_back(j8);
    softwares.push_back(j9);
    softwares.push_back(j10);
    softwares.push_back(j11);
    softwares.push_back(j12);
    softwares.push_back(j13);
    softwares.push_back(j14);
    softwares.push_back(j15);
    softwares.push_back(j16);
    softwares.push_back(j17);
    softwares.push_back(j18);
    softwares.push_back(j19);
    softwares.push_back(j20);
    softwares.push_back(o1);
    softwares.push_back(o2);
    softwares.push_back(o3);
    softwares.push_back(o4);
    softwares.push_back(o5);
    softwares.push_back(pr1);
    softwares.push_back(pr2);
    softwares.push_back(pr3);
    softwares.push_back(pr4);
    softwares.push_back(na1);
    softwares.push_back(na2);
    softwares.push_back(s1);
    softwares.push_back(s2);
    softwares.push_back(s3);
    softwares.push_back(s4);
    softwares.push_back(s5);
    softwares.push_back(s6);
    softwares.push_back(sc1);
    softwares.push_back(sc2);
    /**
     * Crea un nuevo usuario actual "tu".
     * Crea una lista 'misSoftwares' vacia.
     * Llena la lista 'misSoftwares' con software que tienen al usuario dado como uno de sus usuarios.
     * 
     * Se va al menu principal.
    */
    Usuario* tu = login(usuarios);
    list<Software*> misSoftwares;
    misSoftwares =llenarMisSoftwares(tu,misSoftwares,softwares);
    menuPrincipal(tu,softwares,misSoftwares,usuarios);
    
    return 0;
}