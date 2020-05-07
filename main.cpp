#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include<time.h>

using namespace std;
void menu(){
    cout << endl<<endl<<endl<<"<=======MENÚ DEL SISTEMA========>"<<endl<<endl<<endl;
    cout <<"<========1.-Lista de libros=======>"<<endl;
    cout <<"<========2.-Préstamo de libros=======>"<<endl;
    cout <<"<========3.-Devolución de libros=======>"<<endl;
    cout <<"<========4.-Información de libros=======>"<<endl;
    cout <<"<========5.-Salir =======>"<<endl;
}

void desplegar(string libros[10], string autores[10], int prestamos[100], bool estatus[100], int prestamosC){
    cout << endl<<endl<<endl<<"<=======LIBROS========>"<<endl<<endl<<endl;
    for (int i = 0; i < 10; ++i) {
        cout << "<===========================>"<<endl;
        cout << "<==== Número:"<< i << "======>"<<endl;
        cout << "<=== Nombre: "<< libros[i]<< "======>"<<endl;
        cout << "<=== Author: "<< autores[i]<<"======>"<<endl;
        for (int j = 0; j < prestamosC; ++j) {
            if(i==prestamos[j]){
                if(!estatus[i]){
                    cout << "<=== No disponible ======>"<<endl;
                }
            }
        }
        cout << "<===========================>"<<endl;
    }
}

void detalles(int nu,string libro,string autor,int prestamos[100],string nombres[100],bool estatus[100],int prestamosC){

    cout << endl<<endl<<endl<<"<=======DETALLE DE LIBRO========>"<<endl<<endl<<endl;
    cout << "<===========================>"<<endl;
    cout << "<==== Número:"<< nu << "======>"<<endl;
    cout << "<=== Nombre: "<< libro<< "======>"<<endl;
    cout << "<=== Author: "<< autor<<"======>"<<endl;
    cout << "<===========================>"<<endl;

    cout << endl<<endl<<endl<<"<=======HISTORIAL DE PRESTAMOS========>"<<endl<<endl<<endl;
    for (int i = 0; i < prestamosC; ++i) {
        if(nu==prestamos[i]){
            cout << "Persona: "<< nombres[i]<<endl;

            if(estatus[i]){
                cout << "Estado: Devuelto"<<endl;
            }else{
                cout << "Estado: En prestamo"<<endl;
            }

        }
    }
}

void devolucion(int nu,int prestamos[100],bool estatus[100],int prestamosC){

    for (int i = 0; i < prestamosC; ++i) {
        if(nu == prestamos[i]){
            if(!estatus[i]){
                estatus[i] = true;
            }
        }
    }
}

int main(){

    string libros[]={"El las montañas de la locura",
                       "Harry Poter 1",
                       "Perci Jarckson",
                       "El señor de los anillos",
                       "Alicia en el país de las maravillas",
                       "Redacción para investigación",
                       "Don quijote de la mancha",
                       "El kamasutra",
                       "Nerve",
                       "Las baqueritas"};
    string autores[]={"Hp Lovecraft",
                      "J.K. Rowling",
                      "J.l Gofftert",
                      "J.R Tolkien",
                      "Juanito León",
                      "Dr. Murillo león",
                      "Miguel D. Cervantes",
                      "Emmanuel cochinote",
                      "Armando",
                      "Edgar cochinote"};
    bool pw = true;
    int op, nu, prestamosC = 0;
    int prestamos[100];string nombres[100];bool estatus[100];

    while(pw){
        menu();
        cin >> op;
        switch (op) {
            case 1:
                desplegar(libros,autores,prestamos,estatus,prestamosC);
                break;
            case 2:
                desplegar(libros,autores,prestamos,estatus,prestamosC);
                cout << "¿Qué número de libro desea?"<<endl;
                cin >> prestamos[prestamosC];

                cout << "Ingrese su nombre"<<endl;
                cin >> nombres[prestamosC];

                estatus[prestamosC] = false;

                prestamosC++;
                break;
            case 3:
                cout << "¿Qué número de libro desea regresar?";
                cin >> nu;

                devolucion(nu,prestamos,estatus,prestamosC);
                break;
            case 4:
                cout << "¿Qué número de libro desea?";
                cin >> nu;

                detalles(nu,libros[nu],autores[nu],prestamos,nombres,estatus,prestamosC);
                break;
            default:
                pw = false;
        }
    }
    return 0;
}