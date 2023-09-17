#include "vehiculo.h"
#include "precios.h"
#include <iostream>
using namespace std;

Vehiculo::Vehiculo(int numeroMotorVehiculo, int cantidadRuedasVehiculo, int tipoCombustibleVehiculo, int anoFabricacionVehiculo, string tipoAutoVehiculo, string tanqueVehiculo)
{
    this->numeroMotor = numeroMotorVehiculo;
    this->cantidadRuedas = cantidadRuedasVehiculo;
    this->tipoCombustible = tipoCombustibleVehiculo;
    this->anoFabricacion = anoFabricacionVehiculo;
    this->tipoAuto = tipoAutoVehiculo;
    this->tanque = tanqueVehiculo;
}

Vehiculo::~Vehiculo()
{
    cout << "\n Destructor de vehiculo";
}

void Vehiculo::PedirDatosVehiculo()
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

Auto::Auto(string marcaAuto, int precioAuto):Vehiculo(0, 0, 0, 0, "", "")
{
    this->marca = marcaAuto;
    this->precio = precioAuto;
}

Auto::~Auto()
{
    cout << "\n Destructor de Auto";
}

void Auto::PedirDatosA()
{
    cout << "\n Ingrese la marca del auto: ";
    cin >> this -> marca;
    cout << "\n Ingrese el precio del auto: ";
    cin >> this -> precio;
}

void Auto::MostrarDatosA()
{
    cout << "\n Marca: " << this -> marca;
    cout << "\n Precio: " << this -> precio;
}

void Auto::CalcularPrecioA()
{
    int precioBase = 0;
    if (marca == "Toyota") {
        precioBase = preciosvehiculos.at("Toyota");
    } else if (marca == "Hyundai") {
        precioBase = preciosvehiculos.at("Hyundai");
    } else if (marca == "Suzuki") {
        precioBase = preciosvehiculos.at("Suzuki");
    } else if (marca == "Ford") {
        precioBase = preciosvehiculos.at("Ford");
    } else if (marca == "Chevrolet") {
        precioBase = preciosvehiculos.at("Chevrolet");
    } else if (marca == "Honda") {
        precioBase = preciosvehiculos.at("Honda");
    }
}

Moto::Moto(string marcaMoto, int precioMoto): Vehiculo(0, 0, 0, 0, "", "")
{
    this->marca = marcaMoto;
    this->precio = precioMoto;
}

Moto::~Moto()
{
    cout << "\n Destructor de Moto";
}

void Moto::PedirDatosM()
{
    cout << "\n Ingrese la marca de la moto: ";
    cin >> this -> marca;
    cout << "\n Ingrese el precio de la moto: ";
    cin >> this -> precio;
}

void Moto::MostrarDatosM()
{
    cout << "\n Marca: " << this -> marca;
    cout << "\n Precio: " << this -> precio;
}

void Moto::CalcularPrecioM()
{
    // Buscar el precio en el mapa usando la marca
    map<string, int>::const_iterator it = preciosvehiculos.find(marca);
    if (it != preciosvehiculos.end()) {
        double precioBase = it->second;

        // Obtener el año de fabricación del vehículo
        cout << "\n Ingrese el año de fabricación: ";
        cin >> this -> anoFabricacion;

        // Aplicar descuentos según el año de fabricación
        double descuento = 0.0;
        if (anoFabricacion < 2000) {
            descuento = 0.5;  // 50% de descuento
        } else if (anoFabricacion >= 2000 && anoFabricacion <= 2017) {
            descuento = 0.3;  // 30% de descuento
        } else if (anoFabricacion > 2017) {
            descuento = 0.15; // 15% de descuento
        }

        // Verificar si el tipo de auto es eléctrico o a gas
        cout << "\n Ingrese el tipo de auto (eléctrico o gas): ";
        cin >> tipoAuto;

        if (tipoAuto == "eléctrico" || tipoAuto == "gas") {
            // Aumentar el precio en un 20%
            precioBase *= 1.2;
        }

        // Calcular el precio final con descuento
        double precioFinal = precioBase - (precioBase * descuento);

        cout << "\n Precio base: " << precioBase;
        cout << "\n Año de fabricación: " << anoFabricacion;
        cout << "\n Tipo de auto: " << tipoAuto;
        cout << "\n Precio final: " << precioFinal << endl;
    } else {
        cout << "Marca no encontrada en la lista de precios." << endl;
    }
}

CamionMediano::CamionMediano(string marcaAuto, int precioAuto): Vehiculo(0, 0, 0, 0, "", "")
{
    this->marca = marcaAuto;
    this->precio = precioAuto;
}

CamionMediano::~CamionMediano()
{
    cout << "\n Destructor de Camion Mediano";
}

void CamionMediano::PedirDatosCM()
{
    cout << "\n Ingrese la marca del camion mediano: ";
    cin >> this -> marca;
    cout << "\n Ingrese el precio del camion mediano: ";
    cin >> this -> precio;
}

void CamionMediano::MostrarDatosCM()
{
    cout << "\n Marca: " << this -> marca;
    cout << "\n Precio: " << this -> precio;
}

void CamionMediano::CalcularPrecioCM()
{
    // TODO calcular el descuento para los camiones medianos
}