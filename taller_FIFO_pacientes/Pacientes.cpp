// Código incompleto. solo se puede registrar el numero de documento 
//falta registrar el nombre

#include <iostream>
#include <malloc.h> //archivo de cabecera para gestionar memoria

using namespace std;

struct Pacientes
{
    int valCedula = 0;
    Pacientes *sigCedula;
};
Pacientes *cabCedula, *auxCedula, *aux2Cedula;

int registrar()
{
    if (cabCedula == NULL)
    {
        cabCedula = (struct Pacientes *)malloc(sizeof(struct Pacientes));
        cout << "ingrese su numero de cedula: " << endl;
        cin >> cabCedula->valCedula;
        cabCedula->sigCedula = NULL;
    }
    else
    {
        auxCedula = (struct Pacientes *)malloc(sizeof(struct Pacientes));
        cout << "ingrese su numero de cedula: " << endl;
        cin >> auxCedula->valCedula;
        auxCedula->sigCedula = NULL;
        aux2Cedula = cabCedula;
        while (aux2Cedula->sigCedula != NULL)
        {
            aux2Cedula = aux2Cedula->sigCedula;
        }
        aux2Cedula->sigCedula = auxCedula;
        auxCedula = NULL;
        aux2Cedula = auxCedula;

        free(auxCedula);
        free(aux2Cedula);
    }
    return 0;
}

int mostrar()
{

    for (auxCedula = cabCedula; auxCedula != NULL; auxCedula = auxCedula->sigCedula)
    {
        cout << "Numero de Cedula: " << auxCedula->valCedula << endl;
    }
    return 0;
}

int main()
{
    int opcion = 0; // menu de accion

    do
    {
        cout << "menu de regirtro de pacientes" << endl;
        cout << "1. regisrar paciente" << endl;
        cout << "2. ver lista de pacientes" << endl;
        cout << "3. salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            registrar();
            break;

        case 2:
            mostrar();
            break;

        case 3:
            cout << "adios" << endl;
            break;

        default:
            cout << "opcion invalida. intente nuevamente" << endl;
            break;
        }
    } while (opcion != 3);

    return 0;
}