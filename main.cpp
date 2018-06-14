#include <iostream>
#include <fstream>
#include "NodoDE.h"
#include "ListaDE.h"
#include "CONTACTO.H"


using namespace std;

int main()
{
    CListaDE Lista;
    CContacto personota, personota2;
    int opc, opc2;

    do {
        cout << "---Menu---" << endl << endl << "(1) Cargar Agenda" << endl << "(2) Guardar Agenda" << endl;
        cout << "(3) Anadir Contacto" << endl  <<  "(4) Eliminar Contacto" << endl;
        cout <<  "(5) Buscar Contacto" << endl << "(6) Modificar Datos de Contacto" << endl;
        cout << "(7) Ordenar por Nombre Ascendente" << endl  << "(8) Imprimir Todos los Contactos" << endl;
        cout << "(9) Eliminar Todos los Contactos"<< endl <<  "(0) Salir" << endl << endl;
        cin>>opc;
        switch (opc){
        case 1:
            break;
        case 2:
            break;
        case 3:
            Lista.insertarElementosLista();
            break;
        case 4:
            puts("Nombre del contacto a eliminar: ");
            cin>>personota.nombre;
            Lista.eliminarElemento(personota);
            break;
        case 5:
            puts("Por: Correo (1)  Telefono (2) : ");
            cin>>opc2;
            if(opc2==1){
                    puts("ingrese el correo: ");
                    cin>>personota.correo;
                    Lista.buscarElementoCorreo(personota);
            }else if(opc2==2){
                    puts("ingrese el telefono: ");
                    cin>>personota.telefono;
                    Lista.buscarElementoTelefono(personota);
            }
            break;
        case 6:
            strcpy(personota.nombre,"");
            strcpy(personota.telefono,"");
            strcpy(personota.celular,"");
            strcpy(personota.correo,"");

            puts("Ingrese el nombre del contacto a modificar: ");
            cin>>personota2.nombre;
            cout<<"Desea modificar el nombre SI(1) . NO (0) ";
            cin>>opc2;
            if (opc2==1){
                cout<<"Nombre: ";
                cin>>personota.nombre;
            }
            cout<<"Desea modificar el telefono SI(1) . NO (0) ";
            cin>>opc2;
            if(opc2==1){
                cout<<"Telefono: ";
                cin>>personota.telefono;
            }
            cout<<"Desea modificar el celular SI(1) . NO (0) ";
            cin>>opc2;
            if(opc2==1){
                cout<<"Celular: ";
                cin>>personota.celular;
            }
            cout<<"Desea modificar el correo SI(1) . NO (0) ";
            cin>>opc2;
            if(opc2==1){
                cout<<"Correo: ";
                cin>>personota.correo;
            }
            Lista.modificarDatos(personota, personota2);
            break;
        case 7:
            Lista.ordenarLista();
            puts("lista ordenada :D");
            break;
        case 8:
            Lista.imprimirLista();
            break;
        case 9:
            Lista.eliminarContactos();
            break;
        case 0:
            break;
        default:
            cout<<"Opcion invalida"<<endl;
        }
    } while (opc!=0);
    return 0;
}
