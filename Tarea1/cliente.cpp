#include "cliente.h"
#include <iostream>
using namespace std;

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

    cout << "\n Ingrese el RUT del cliente: ";
    cin >> this -> rut;
}

void Cliente::MostrarDatosC()
{
    cout << "\n Nombre: " << this -> nombre;
    cout << "\n RUT: " << this -> rut;
}