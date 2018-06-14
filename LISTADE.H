#ifndef LISTADE_H_INCLUDED
#define LISTADE_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include "CONTACTO.H"
#include "NodoDE.h"
#include <stdio.h>
#include <string.h>
#include <math.h>


using namespace std;

class CListaDE{
public:
    int num_elementos;
    CContacto personita;
    CNodoDE *primerNodo;
public:
    CListaDE();
    void carga de datos();
    void insertarElementosLista();
    void insertarElementoAlInicio(CContacto persi);
    void eliminarElementoAlInicio();
    void imprimirLista();
    void ordenarLista();
    void buscarElementoTelefono(CContacto persi);
    void eliminarElemento(CContacto persi);
    void buscarElementoCorreo(CContacto persi);
    void modificarDatos(CContacto persi, CContacto persiBuscar);
    void eliminarContactos();
};

    CListaDE::CListaDE(){
        num_elementos=0;
        primerNodo=NULL;
    }
    void CListaDE::insertarElementosLista(){
        int opc=1, opc2=0;

        while (opc==1){
            strcpy(personita.nombre,"");
            strcpy(personita.telefono,"");
            strcpy(personita.celular,"");
            strcpy(personita.correo,"");

            cout<<"Nombre: ";
            //scanf("%f",personita.nombre);
            //getchar(personita.nombre);
            fflush(stdin);
            gets(personita.nombre);
            //cin>>personita.nombre;
            cout<<personita.nombre;
            cout<<"Desea ingresar telefono SI(1) . NO (0) ";
            cin>>opc2;
            if(opc2==1){
                cout<<"Telefono: ";
                cin>>personita.telefono;
                fflush(stdin);
            }
            cout<<"Desea ingresar celular SI(1) . NO (0) ";
            cin>>opc2;
            if(opc2==1){
                cout<<"Celular: ";
                cin>>personita.celular;
                fflush(stdin);
            }
            cout<<"Desea ingresar correo SI(1) . NO (0) ";
            cin>>opc2;
            if(opc2==1){
                cout<<"Correo: ";
                cin>>personita.correo;
                fflush(stdin);
            }
            insertarElementoAlInicio(personita);
            cout<<"¿Deseas ingresar otro dato? SI (1) - NO (0)"<<endl;
            cin>>opc;
        }
    }
    void CListaDE::insertarElementoAlInicio(CContacto persi){
        CNodoDE *nuevo=new CNodoDE(persi);

        if (primerNodo==NULL)
            primerNodo=nuevo;
        else{
            nuevo->sig=primerNodo;
            primerNodo->ant=nuevo;
            primerNodo=nuevo;
        }
        num_elementos++;
    }
    void CListaDE::eliminarElementoAlInicio(){
        CNodoDE *aux=primerNodo;
        if (primerNodo->sig==NULL)
            primerNodo=NULL;
        else{
            primerNodo=primerNodo->sig;
            primerNodo->ant=NULL;
            aux->eliminarNodo();
        }
        num_elementos--;
    }
    void CListaDE::imprimirLista(){
        CNodoDE *temp=primerNodo;
        if (primerNodo!=NULL){
            while (temp->sig!=NULL){
                temp->imprimirNodo();
                temp=temp->sig;
            }
            temp->imprimirNodo();
        }
        else
            cout<<"Error, agenda vacia :("<<endl;
    }
    void CListaDE::ordenarLista(){
        CNodoDE *temp=primerNodo;
        CNodoDE *temp2;
        CContacto aux;

        if (primerNodo->sig!=NULL){
            for(int i=1; i<num_elementos; i++){
                temp=primerNodo;

                for (int j=1; j<num_elementos; j++){
                    temp2=temp->sig;
                    aux=temp->persona;

                    for(int k=0;k<50;k++){
                        if(int(temp->persona.nombre[k])>int(temp2->persona.nombre[k])){
                            temp->persona=temp2->persona;
                            temp2->persona=aux;
                            k=60;
                        }
                        else
                            k=60;
                    }
                    temp=temp->sig;
                }
            }
        }
        else
            cout<<"No hay contactos en la agenda :("<<endl;
    }
    void CListaDE::buscarElementoCorreo(CContacto persi){
        CNodoDE *temp=primerNodo;
        if (temp!=NULL){
            while (temp!=NULL && strcmp(persi.correo, temp->persona.correo)!=0)
                temp=temp->sig;

            if (temp==NULL)
                cout<<"El dato no existe"<<endl;
            else{
                cout<<"Dato encontrado"<<endl;
                temp->persona.imprimir();
                }
        }
        else
            cout<<"No hay datos"<<endl;
    }
    void CListaDE::buscarElementoTelefono(CContacto persi){
        CNodoDE *temp=primerNodo;
        if (temp!=NULL){
            while (temp!=NULL && strcmp(persi.telefono, temp->persona.telefono)!=0)
                temp=temp->sig;

            if (temp==NULL)
                cout<<"El dato no existe"<<endl;
            else{
                cout<<"Dato encontrado"<<endl;
                temp->persona.imprimir();
                }
        }
        else
            cout<<"No hay datos"<<endl;
    }
    void CListaDE::eliminarElemento(CContacto persi){
        CNodoDE *temp=primerNodo;
        CNodoDE *anterior, *aux;

        if (primerNodo->sig==NULL)
            primerNodo=NULL;

        else if (temp!=NULL){
            while (temp!=NULL && strcmp(persi.nombre,temp->persona.nombre) != 0){
                anterior=temp;
                temp=temp->sig;
            }

            if (anterior==NULL){
                aux=temp;
                temp=temp->sig;
                temp->ant=NULL;
                aux->eliminarNodo();
            }
            else if (temp==NULL)
                cout<<"El Dato no esta en la lista"<<endl;
            else{
                aux=temp;
                temp=temp->sig;
                anterior->sig=temp;

                if (temp!=NULL)
                    temp->ant=anterior;

                aux->eliminarNodo();
            }
        }
        else
            cout<<"No hay datos"<<endl;
    }

    void CListaDE::modificarDatos(CContacto persi, CContacto persiBuscar){
        CNodoDE *temp=primerNodo;
        if (temp!=NULL){
            while (temp!=NULL && strcmp(persiBuscar.nombre, temp->persona.nombre)!=0)
                temp=temp->sig;

            if (temp==NULL)
                cout<<"El dato no existe"<<endl;
            else{
                cout<<"Dato encontrado"<<endl;
                puts("  Datos modificados");
                temp->persona.actualizar(persi.nombre, persi.telefono, persi.celular, persi.correo);
                }
        }
        else
            cout<<"No hay datos"<<endl;

    }

    void CListaDE::eliminarContactos(){
        CNodoDE *aux;
        CNodoDE *temp=primerNodo;
        if (primerNodo!=NULL){
            while (primerNodo->sig!=NULL){
                aux=primerNodo;
                primerNodo=primerNodo->sig;
                aux->eliminarNodo();
            }
            primerNodo=NULL;
            num_elementos=0;
            if (temp==NULL)
                cout<<"Contactos eliminados"<<endl;
        }
        else
            cout<<"No hay contactos en la agenda"<<endl;
    }
    void CListaDE::carga de datos(){
        FILE *entrada;
        FILE *salida;
        char registro[50];
        char aux[50];
        char *separador=";";
        char *ptr;

        int i, j;

            entrada=fopen("agenda.txt","r t");
            //salida=fopen("puntos.txt","w t");


            if ((entrada==NULL) || (salida==NULL)){

                cout<<"Error en Lectura/Escritura de archivos"<<endl;
                return 0;
            }else{
                puts("Cargando agenda...");
                //ccam=i;
                i=1;

                while(fgets(registro,50,entrada)){
                    ptr=strtok(registro,separador);
                    i=1;

                    while(ptr){


                    }

                }

            }




    }

#endif // LISTADE_H_INCLUDED
