#ifndef NODODE_H_INCLUDED
#define NODODE_H_INCLUDED
#include <iostream>
#include "CONTACTO.H"

using namespace std;

class CNodoDE {
public:
    CContacto persona;
    CNodoDE *sig;
    CNodoDE *ant;
public:
    CNodoDE();
    CNodoDE(CContacto per);
    void imprimirNodo();
    void actualizarNodo(CContacto per);
    void eliminarNodo();
};

    CNodoDE::CNodoDE(){
        sig=NULL;
        ant=NULL;
    }
    CNodoDE::CNodoDE(CContacto per){
        strcpy(persona.nombre,per.nombre);
        strcpy(persona.telefono,per.telefono);
        strcpy(persona.celular,per.celular);
        strcpy(persona.correo,per.correo);
        sig=NULL;
        ant=NULL;
    }
    void CNodoDE::imprimirNodo(){
        persona.imprimir();
    }
    void CNodoDE::actualizarNodo(CContacto per){

        persona.actualizar(per.nombre, per.telefono, per.celular, per.correo);
    }
    void CNodoDE::eliminarNodo(){
        persona.eliminar();
        delete this;
    }

#endif // NODODE_H_INCLUDED
