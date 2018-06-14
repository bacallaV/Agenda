#ifndef CONTACTO_H_INCLUDED
#define CONTACTO_H_INCLUDED
#include <string.h>

using namespace std;

class CContacto{
    public:
        char nombre[50];
        char telefono[10];
        char celular[10];
        char correo[50];
    public:
        CContacto();
        CContacto(char nom_1[50], char tel_1[10] , char cel_1[10] , char correo_1[50]);
        void actualizar (char nom_1[50], char tel_1[10] , char cel_1[10] , char correo_1[50] );
        void imprimir ();
        void eliminar ();
};
    CContacto::CContacto(){
        strcpy(nombre,"");
        strcpy(telefono,"");
        strcpy(celular,"");
        strcpy(correo,"");
    }
    CContacto::CContacto(char nom_1[50], char tel_1[10] , char cel_1[10] , char correo_1[50]){
        strcpy(nombre,nom_1);
        strcpy(telefono,tel_1);
        strcpy(celular,cel_1);
        strcpy(correo,correo_1);
    }
    void CContacto::actualizar (char nom_1[50], char tel_1[10] , char cel_1[10] , char correo_1[50] ){
        if(strncmp(nom_1,"",25) != 0)
            strcpy(nombre,nom_1);
        if(strncmp(tel_1,"",25) != 0)
            strcpy(telefono,tel_1);
        if(strncmp(cel_1,"",25) != 0)
            strcpy(celular,cel_1);
        if(strncmp(correo_1,"",25) != 0)
            strcpy(correo,correo_1);
    }
    void CContacto::imprimir (){
        cout<<"nombre: "<<nombre<<endl;
        cout<<"telefono: "<<telefono<<endl;
        cout<<"celular: "<<celular<<endl;
        cout<<"correo: "<<correo<<endl<<endl;
    }
    void CContacto::eliminar ( ){
        delete this;
    }

#endif // CONTACTO_H_INCLUDED
