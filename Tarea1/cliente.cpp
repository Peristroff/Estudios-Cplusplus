#include "cliente.h"
#include <iostream>
using namespace std;

// HACK por ahora RUT va a ser string, pero Jerry quiere que haya alguna comprobacion de que sea numero y el ultimo digito sea un string
Cliente::Cliente(string nombreCliente, string rutCliente)
{
    this->nombre = nombreCliente;
    this->rut = rutCliente;
}

Cliente::~Cliente()
{
    //cout << "\n Destructor de Cliente";
}

void Cliente::PedirDatosC()
{
    cout << "\n Ingrese el nombre del cliente: ";
    cin >> this -> nombre;
    cout << "\n Ingrese el rut del cliente: ";
    cin >> this -> rut;
}

void Cliente::MostrarDatosC()
{
    cout << "\n Nombre: " << this -> nombre;
    cout << "\n Rut: " << this -> rut;
}