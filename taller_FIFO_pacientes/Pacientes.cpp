// Código completado

// Integrantes:
// Deymar Andrés Ampudia Rivas
// Rodigo Arturo Perez Angulo

#include <iostream>
#include <malloc.h> //archivo de cabecera para gestionar memoria

using namespace std;

struct Pacientes
{
    int acumulador;
    int Cedula = 0;
    char Nombre[20];   // se pone un limitador de letras que la variable Nombre puede guardar
    char Apellido[20]; // se pone un limitador de letras que la variable Apellido puede guardar
    Pacientes *sig;
};
Pacientes *cab, *aux, *aux2;
int registrar()
{
    if (cab == NULL)
    {
        cab = (struct Pacientes *)malloc(sizeof(struct Pacientes));
        cout << "Ingrese su cedula: ";
        cin >> cab->Cedula;

        cout << "ingrese su primer nombre: ";
        cin >> cab->Nombre;

        cout << "ingrese su primer apellido: ";
        cin >> cab->Apellido;

        cab->sig = NULL;

        if (cab == NULL)
        {
            cab = aux;
            cab->acumulador = 1;
            aux = NULL;

            free(aux);
        }
        return 0;
    }
    else
    {
        aux = (struct Pacientes *)malloc(sizeof(struct Pacientes));
        cout << "ingrese su cedula: ";
        cin >> aux->Cedula;

        cout << "ingrese su primer nombre: ";
        cin >> aux->Nombre;

        cout << "ingrese su primer apellido: ";
        cin >> aux->Apellido;

        aux->sig = NULL;
        aux2 = cab;

        while (aux2->sig != NULL)
        {
            aux2 = aux2->sig;
        }

        aux->acumulador = aux2->acumulador + 1;
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
        cout << "Orden de atencion: " << aux->acumulador + 1 << endl;
        cout << "Nombre: " << aux->Nombre << " " << aux->Apellido << endl;
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
        cout << "Programa de Registro de Pacientes" << endl;
        cout << "Por favor, elija una opcion" << endl;
        cout << "" << endl;

        cout << "1. Registrar Paciente" << endl;
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
            cout << "" << endl;
            cout << "personas registradas: " << endl;
            cout << "" << endl;
            mostrar();
            break;

        case 3:
            cout << "Programa finalizado. Que tenga buen dia" << endl;
            break;

        default:
            cout << "opcion invalida. intente nuevamente" << endl;
            break;
        }
    } while (opcion != 3);

    return 0;
}