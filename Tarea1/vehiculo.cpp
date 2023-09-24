#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <string>
#include "vehiculo.h"
#include "precios.h"
#include "administradorDeArchivos.h"
#include "CSVparser.hpp"
#include "cliente.h"
using namespace std;

string marcaG;
int precioG;

// BUG modificar el precio que se guarda en el csv, actualmente se esta guardando el precio sin los descuentos
// Prototipo de las funciones, las funciones que estan al final del archivo no funcionan si no se declara el prototipo antes
double CalcularDescuentos(int precioBase, int anoFabricacion, string tipoAuto);
string TransformarAMinusculas(string palabra);

Vehiculo::Vehiculo(int numeroMotorVehiculo, int cantidadRuedasVehiculo, int anoFabricacionVehiculo, string tipoCombustibleVehiculo, string tipoAutoVehiculo, string tanqueVehiculo)
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
    //cout << "\n Destructor de vehiculo";
}

// Comprueba si se ingresa un string
string entradaValidaString(string &entrada)
{
    bool esStringValido = false;
    do
    {
        getline(cin, entrada);

        if (!entrada.empty()) 
        {
            esStringValido = true;
        }
        else
        {
            cout << "Favor ingresar una entrada valida: ";
        }
    } while (!esStringValido);

    return entrada;
}

// Comprobar si el dato ingresado es un numero y si es mayor a 0
int entradaValidaNumeros(int &entrada)
{
    bool Numero = false;
    do
    {
        if (cin >> entrada && entrada > 0)
        {
            Numero = true;
        }
        else
        {
            cout << "Favor ingresar un numero entero positivo: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }while (!Numero);
    return entrada;
}

// Funcion para ingresar los datos de la clase vehiculo
void Vehiculo::PedirDatosVehiculo()
{
    string autoSeleccionado;

    cout << "\n Ingrese el numero de motor: ";
    //cin >> this -> numeroMotor;
    entradaValidaNumeros(this->numeroMotor);

    cout << "\n Ingrese la cantidad de ruedas: ";
    entradaValidaNumeros(this->cantidadRuedas);

    cout << "\n Ingrese el tipo de combustible (gasolina, gas o electrico): ";
    entradaValidaString(this->tipoCombustible);

    this -> tipoCombustible = TransformarAMinusculas(this -> tipoCombustible);

    cout << "\n Ingrese el deposito de combustible (capacidad del tanque en litros si es gasolina): ";
    entradaValidaString(this->tanque);

    cout << "\n Ingrese el año de fabricacion: ";
    entradaValidaNumeros(this->anoFabricacion);

    cout << "\n Ingrese el tipo de vehiculo: ";
    cout << "\n a. Auto";
    cout << "\n b. Moto";
    cout << "\n c. Camion Mediano\n";
    cin >> autoSeleccionado;
    
    autoSeleccionado = TransformarAMinusculas(autoSeleccionado);

    if (autoSeleccionado == "a" || autoSeleccionado == "auto") {
        this -> tipoAuto = "Auto";
        Auto auto1("", 0);
        auto1.PedirDatosA(this -> tipoAuto, this -> anoFabricacion);
        marcaG = auto1.marca;
        precioG = auto1.precio;
    } else if (autoSeleccionado == "b" || autoSeleccionado == "moto") {
        this -> tipoAuto = "Moto";
        Moto moto1("", 0);
        moto1.PedirDatosM(this -> tipoAuto, this -> anoFabricacion);
        marcaG = moto1.marca;
        precioG = moto1.precio;
    } else if (autoSeleccionado == "c" ||autoSeleccionado == "camion mediano") {
        this -> tipoAuto = "Camion Mediano";
        CamionMediano camionMediano1("", 0);
        camionMediano1.PedirDatosCM(this -> tipoAuto, this -> anoFabricacion);
        marcaG = camionMediano1.marca;
        precioG = camionMediano1.precio;
    }
}

Auto::Auto(string marcaAuto, int precioAuto):Vehiculo(0, 0, 0, "", "", "")
{
    this->marca = marcaAuto;
    this->precio = precioAuto;
}

Auto::~Auto()
{
    //cout << "\n Destructor de Auto";
}

// Ingresa los datos a las variables de la clase Auto
void Auto::PedirDatosA(string tipoAutoA, int anoFabricacionA)
{
    double precioFinal;
    cout << "\n Ingrese la marca del auto: ";
    cin >> this -> marca;
    
    precio = CalcularPrecioA(marca);

    cout << "\n El precio base es: $" << precio;
    
    precioFinal = CalcularDescuentos(precio, anoFabricacionA, tipoAutoA);
    
    cout << "\n El precio final es: $" << fixed << setprecision(0) << precioFinal << endl;
}

//TODO manejar excepciones para que entrege un error si la marca no está en el diccionario
// Funcion para calcular el precio del auto segun la marca alojada en precios.h
int Auto::CalcularPrecioA(string marcaAuto)
{
    marcaAuto = TransformarAMinusculas(marcaAuto);
    int precioBase = 0;
    try {
        precioBase = preciosAutos.at(marcaAuto);
    } catch(const out_of_range& e) 
    {
        cout << "Marca no encontrada en la lista de precios." << endl;
        cout << "Ingrese una marca valida: ";
        cin >> marcaAuto;
        CalcularPrecioA(marcaAuto);
    }
    return precioBase;
}

Moto::Moto(string marcaMoto, int precioMoto): Vehiculo(0, 0, 0, "", "", "")
{
    this->marca = marcaMoto;
    this->precio = precioMoto;
}

Moto::~Moto()
{
    //cout << "\n Destructor de Moto";
}

// Ingresa los datos a las variables de la clase Moto
void Moto::PedirDatosM(string tipoAutoM, int anoFabricacionM)
{
    double precioFinal;
    cout << "\n Ingrese la marca de la moto: ";
    cin >> this -> marca;

    precio = CalcularPrecioM(marca);

    cout << "\n El precio base es: $" << precio;
    
    precioFinal = CalcularDescuentos(precio, anoFabricacionM, tipoAutoM);
    
    cout << "\n El precio final es: $" << fixed << setprecision(0) << precioFinal << endl;
}

// Funcion para calcular el precio de la Moto segun la marca alojada en precios.h
int Moto::CalcularPrecioM(string marcaMoto)
{
    marcaMoto = TransformarAMinusculas(marcaMoto);
    int precioBase = 0;
    try {
        precioBase = preciosMotos.at(marcaMoto);
    } catch(const out_of_range& e) 
    {
        cout << "Marca no encontrada en la lista de precios." << endl;
        cout << "Ingrese una marca valida: ";
        cin >> marcaMoto;
        CalcularPrecioM(marcaMoto);
    }
    return precioBase;
}

CamionMediano::CamionMediano(string marcaCamion, int precioCamion): Vehiculo(0, 0, 0, "", "", "")
{
    this->marca = marcaCamion;
    this->precio = precioCamion;
}

CamionMediano::~CamionMediano()
{
    //cout << "\n Destructor de Camion Mediano";
}

void CamionMediano::PedirDatosCM(string tipoAutoCM, int anoFabricacionCM)
{
    double precioFinal;
    cout << "\n Ingrese la marca de la moto: ";
    cin >> this -> marca;

    precio = CalcularPrecioCM(marca);

    cout << "\n El precio base es: $" << precio;
    
    precioFinal = CalcularDescuentos(precio, anoFabricacionCM, tipoAutoCM);
    
    cout << "\n El precio final es: $" << fixed << setprecision(0) << precioFinal << endl;
}

// Funcion para calcular el precio del CamionMediano segun la marca alojada en precios.h
int CamionMediano::CalcularPrecioCM(string marcaCamion)
{
    marcaCamion = TransformarAMinusculas(marcaCamion);
    int precioBase = 0;
    try {
        precioBase = preciosCamiones.at(marcaCamion);
    } catch(const out_of_range& e) 
    {
        cout << "Marca no encontrada en la lista de precios." << endl;
        cout << "Ingrese una marca valida: ";
        cin >> marcaCamion;
        CalcularPrecioCM(marcaCamion);
    }
    return precioBase;
}

double CalcularDescuentos(int precioBase, int anoFabricacion, string tipoAuto)
{
    double descuento = 0;

    if (anoFabricacion < 2000) 
    {
        descuento = 0.5;  // 50% de descuento
    } 
    else if (anoFabricacion >= 2000 && anoFabricacion <= 2017) 
    {
        descuento = 0.3;  // 30% de descuento
    } 
    else if (anoFabricacion > 2017) 
    {
        descuento = 0.15; // 15% de descuento
    }

    // Calcular el precio final con descuento
    double precioConDescuento = precioBase - (precioBase * descuento);

    if (tipoAuto == "eléctrico" || tipoAuto == "gas") 
    {
        // Aplicar incremento de precio si es eléctrico o de gas
        // Aumentar el precio en un 20%
        precioConDescuento *= 1.2;
    }
    return precioConDescuento;
}

// Funcion para transformar un string a minusculas
string TransformarAMinusculas(string palabra)
{
    for (char &c : palabra) {
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }

    return palabra;
}