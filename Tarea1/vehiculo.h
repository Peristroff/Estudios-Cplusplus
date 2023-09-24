#include <iostream>
#include <string>
#include <map>
#pragma once
using namespace std;

extern std::string marcaG;
extern int precioG;

// Clase padre vehiculo, con los atributos numeroMotor, cantidadRuedas, tipoCombustible, anoFabricacion, tipoAuto, tanque
class Vehiculo 
{
    // En vez de la variable deposito de combustible, se va a dejar la variable capTanque, que se debe ingresar los litros si es gasolina y el string NO si es electrico
    public:
        int numeroMotor, cantidadRuedas, anoFabricacion;
        string tipoCombustible, tipoAuto, tanque;

        Vehiculo(int numeroMotor, int cantidadRuedas, int anoFabricacion, string tipoCombustible, string tipoAuto, string tanque);
        ~Vehiculo();

        void PedirDatosVehiculo();
        void MostrarDatosv();
};

// Clase hijo de vehiculo, heredero de los atributos mas la variable marca y precio
class Auto:public Vehiculo
{
    public:
        string marca;
        int precio;

        Auto(string marca, int precio);
        ~Auto();
        
        void PedirDatosA(string tipoAuto, int anoFrabricacion);
        void MostrarDatosA();
        int CalcularPrecioA(string marca);
};

class Moto:public Vehiculo
{
    public:
        string marca;
        int precio;
        Moto(string marca, int precio);
        ~Moto();

        void PedirDatosM(string tipoAuto, int anoFrabricacion);
        void MostrarDatosM();
        int CalcularPrecioM(string marca);

};

class CamionMediano:public Vehiculo
{
    protected:
    public:
        string marca;
        int precio;

        CamionMediano(string marca, int precio);
        ~CamionMediano();

        void PedirDatosCM(string tipoAuto, int anoFrabricacion);
        void MostrarDatosCM();
        int CalcularPrecioCM(string marca);
};