// Código completado

// Integrantes:
// Deymar Andrés Ampudia Rivas
// Rodigo Arturo Perez Angulo


#include <iostream>
#include <malloc.h> //archivo de cabecera para gestionar memoria

using namespace std;

struct Pacientes
{
    int Cedula = 0;
    char Nombre[100];
    Pacientes *sig;
};
Pacientes *cab, *aux, *aux2;
int registrar()
{
    if (cab == NULL)
    {
        cab = (struct Pacientes *)malloc(sizeof(struct Pacientes));
        cout << "cedula: ";
        cin >> cab->Cedula;
        cout << "nombre ";
        cin >> cab->Nombre;
        cab->sig = NULL;
    }
    else
    {
        aux = (struct Pacientes *)malloc(sizeof(struct Pacientes));
        cout << "ingrese su numero de cedula: ";
        cin >> aux->Cedula;

        cout << "ingrese su nombre: ";
        cin >> aux->Nombre;
        aux->sig = NULL;
        
        aux2 = cab;
        
        while (aux2->sig != NULL)
        {
            aux2 = aux2->sig;
        }
        aux2->sig = aux;
        aux = NULL;
        aux2 = aux;

        free(aux);
        free(aux2);
    }
    return 0;
}

int mostrar()
{

    for (aux = cab; aux != NULL; aux = aux->sig)
    {
        cout << "Nombre: " << aux->Nombre << endl;;
        cout << "Numero de Cedula: " << aux->Cedula << endl;
        cout << "" << endl;
    }
    return 0;
}

int main()
{
    int opcion = 0; 

    do // menu de accion
    {
        cout << "Registro de Pacientes" << endl;
        cout << "1. Regisrar Paciente" << endl;
        cout << "2. Ver Lista de Pacientes" << endl;
        cout << "3. salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            registrar();
            break;

        case 2:
            cout << "personas registradas: " << endl;
            cout << "" << endl;
            mostrar();
            break;

        case 3:
            cout << "Programa finalizado. Que tenga buen día" << endl;
            break;

        default:
            cout << "opcion invalida. intente nuevamente" << endl;
            break;
        }
    } while (opcion != 3);

    return 0;
}