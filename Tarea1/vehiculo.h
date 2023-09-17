// #ifndef VEHICULO_H
// #define VEHICULO_H

#include <iostream>
#include <string>
#include <map>
using namespace std;

// Ver los precios en precios.h
extern const map<string, int> preciosvehiculos; // Declaración externa del mapa

// Clase padre vehiculo, con los atributos numeroMotor, cantidadRuedas, tipoCombustible, anoFabricacion, tipoAuto, tanque
class Vehiculo 
{
    // En vez de la variable deposito de combustible, se va a dejar la variable capTanque, que se debe ingresar los litros si es gasolina y el string NO si es electrico  
    public:
        int numeroMotor, cantidadRuedas, tipoCombustible, anoFabricacion;
        string tipoAuto, tanque;

        Vehiculo(int numeroMotor, int cantidadRuedas, int tipoCombustible, int anoFabricacion, string tipoAuto, string tanque);
        ~Vehiculo();

        void PedirDatosVehiculo();
        void MostrarDatosv();
};

//Clase hijo de vehiculo, heredero de los atributos mas la variable marca y precio
class Auto:public Vehiculo
{
    
    public:
        string marca;
        int precio;

        Auto(string marca, int precio);
        ~Auto();
        
        void PedirDatosA();
        void MostrarDatosA();
        void CalcularPrecioA();
};

class Moto:public Vehiculo
{
    protected:
        string marca;
        int precio;
    public:
        Moto(string marca, int precio);
        ~Moto();

        void PedirDatosM();
        void MostrarDatosM();
        void CalcularPrecioM();

};

class CamionMediano:public Vehiculo
{
    protected:
        string marca;
    public:
        int precio;

        CamionMediano(string marca, int precio);
        ~CamionMediano();

        void PedirDatosCM();
        void MostrarDatosCM();
        void CalcularPrecioCM();
};

// // FIXME hay dos clases clientes
// class Cliente:public Vehiculo, public Auto, public Moto, public CamionMediano  
// {
//     protected:
//         string nombre, rut;
//     public:
//         Cliente(string nombre, string rut);
//         ~Cliente();
//         // Declaraciones de metodos relacionados con la funcionalidad de venta
//         // pongo esto aca para que se pueda programar en el .cpp los metodos sjjss
//         void pedirDatosc();
//         void mostrarDatosc();
//         void ventaVehiculo();
//         void reporteMensual();
//         void clienteQueComproMas();
//         void cantidadDeAutosComprados();
//         void cantidadDeMotosCompradas();
//         void cantidadDeCamionesComprados();
//         void cantidadTotalDeVehiculosComprados();
//         void totalDeVentasDeAutos();
//         void totalDeVentasDeMotos();
//         void totalDeVentasDeCamiones();
//         void totalDeVentasDeVehiculos();
//         void promedioDeVentasDeAutos();
//         void promedioDeVentasDeMotos();
//         void promedioDeVentasDeCamiones();
//         void promedioDeVentasTotalesDeVehiculos();
// };
//#endif // VEHICULO_H