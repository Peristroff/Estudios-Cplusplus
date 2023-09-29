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
    cout << "\n Destructor de Cliente";
}

// Funcion para ingresar los datos a las variables de la clase
void Cliente::PedirDatosC()
{
    cin.ignore(); // Limpia el búfer de entrada para evitar un bug de getline
    cout << "\n Ingrese el nombre del cliente: ";
    getline(cin, this -> nombre);

    cout << "\n Ingrese el RUT del cliente: ";
    cin >> this -> rut;
}