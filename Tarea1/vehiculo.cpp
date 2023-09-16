#include "vehiculo.h"
#include <iostream>
using namespace std;

// TODO hacer que el programa entregue un menu al inicio

vehiculo::vehiculo(int numeroMotor, int cantidadRuedas, int tipoCombustible, int anoFabricacion, string tipoAuto, string tanque)
{
    this->numeroMotor = numeroMotor;
    this->cantidadRuedas = cantidadRuedas;
    this->tipoCombustible = tipoCombustible;
    this->anoFabricacion = anoFabricacion;
    this->tipoAuto = tipoAuto;
    this->tanque = tanque;

}

vehiculo::~vehiculo()
{
    cout << "\n Destructor de vehiculo";
}

void vehiculo::PedirDatosVehiculo()
{
    cout << "\n Ingrese el numero de motor: ";
    cin >> this -> numeroMotor;
    cout << "\n Ingrese la cantidad de ruedas: ";
    cin >> this -> cantidadRuedas;
    cout << "\n Ingrese el tipo de combustible: ";
    cin >> this -> tipoAuto;
    cout << "\n Ingrese el deposito de combustible: ";
    cin >> this -> tanque;
    cout << "\n Ingrese el ano de fabricacion: ";
    cin >> this -> anoFabricacion;
    cout << "\n Ingrese el tipo de auto: ";
    cin >> this -> tipoAuto;
}

Auto::Auto(string marca, int precio):vehiculo(0, 0, 0, 0, "", "")
{
    this->marca = marca;
    this->precio = precio;
}

Auto::~Auto()
{
    cout << "\n Destructor de Auto";
}

void Auto::pedirDatosa()
{
    cout << "\n Ingrese la marca del auto: ";
    cin >> this -> marca;
    cout << "\n Ingrese el precio del auto: ";
    cin >> this -> precio;
}

void Auto::mostrarDatosa()
{
    cout << "\n Marca: " << this -> marca;
    cout << "\n Precio: " << this -> precio;
}

void Auto::calcularPrecio()
{
    // TODO Aqui calcula el descuento
}

Moto::Moto(string marca, int precio): vehiculo(0, 0, 0, 0, "", "")
{
    this->numeroMotor = numeroMotor;
    this->cantidadRuedas = cantidadRuedas;
    this->tipoCombustible = tipoCombustible;
    this->anoFabricacion = anoFabricacion;
    this->tipoAuto = tipoAuto;
    this->tanque = tanque;
}

Moto::~Moto()
{
    cout << "\n Destructor de Moto";
}

void Moto::pedirDatosm()
{
    cout << "\n Ingrese la marca de la moto: ";
    cin >> this -> marca;
    cout << "\n Ingrese el precio de la moto: ";
    cin >> this -> precio;
}

void Moto::mostrarDatosm()
{
    cout << "\n Marca: " << this -> marca;
    cout << "\n Precio: " << this -> precio;
}

void Moto::calcularPrecio()
{
    //Aqui calcula con descuento
}

CamionMediano::CamionMediano(string marca, int precio): vehiculo(0, 0, 0, 0, "", "")
{
    this->marca = marca;
    this->precio = precio;
}

CamionMediano::~CamionMediano()
{
    cout << "\n Destructor de Camion Mediano";
}

void CamionMediano::pedirDatoscm()
{
    cout << "\n Ingrese la marca del camion mediano: ";
    cin >> this -> marca;
    cout << "\n Ingrese el precio del camion mediano: ";
    cin >> this -> precio;
}

void CamionMediano::mostrarDatoscm()
{
    cout << "\n Marca: " << this -> marca;
    cout << "\n Precio: " << this -> precio;
}

void CamionMediano::calcularPrecio()
{
    // TODO calcular el descuento
}

cliente::cliente(string nombre, string rut)
{
    this->nombre = nombre;
    this->rut = rut;
}

cliente::~cliente()
{
    cout << "\n Destructor de cliente";
}

void cliente::pedirDatosc()
{
    cout << "\n Ingrese el nombre del cliente: ";
    cin >> this -> nombre;
    cout << "\n Ingrese el rut del cliente: ";
    cin >> this -> rut;
}

void cliente::mostrarDatosc()
{
    cout << "\n Nombre: " << this -> nombre;
    cout << "\n Rut: " << this -> rut;
}

/* metodo de descuentos?

void vehiculo::CalcularPrecio()
{
    if (anoFabricacion < 2000)
    {
        precio *= 0.5; //descuento del 50% si es < 2000
    }
    else if (anoFabricacion >= 2000 && anoFabricacion <= 2017)
    {
        precio *= 0.7; //descuento del 30% si es entre el 2000 y 2017
    }
    else
    {
        precio *= 0.85; // descuento del 15% si > 2017
    }

    if (tipoAuto == "electrico" || tipoAuto == "gas")
    {
        precio *= 1.2; // Aumenta un 20% si es autohomsexual o hetero
    }
}

// hya que agregar los precios priero en una lista uwu
*/