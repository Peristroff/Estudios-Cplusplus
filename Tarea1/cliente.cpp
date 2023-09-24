#include <iostream>
#include "cliente.h"
#include "administradorDeArchivos.h"
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

// Funcion para ingresar los datos a las variables de la clase
void Cliente::PedirDatosC()
{
    cout << "\n Ingrese el nombre del cliente: ";
    cin >> this -> nombre;

    cout << "\n Ingrese el RUT del cliente: ";
    cin >> this -> rut;
}