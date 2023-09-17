#include <iostream>
#include <string>
#include <map>
using namespace std;

// TODO Seleccionar el precio de automovil basado en lo que ponga el usuario
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

// Clase hijo de vehiculo, heredero de los atributos mas la variable marca y precio
class Auto:public Vehiculo
{
    public:
        string marca;
        int precio;

        Auto(string marca, int precio);
        ~Auto();
        
        void PedirDatosA();
        void MostrarDatosA();
        int CalcularPrecioA(string marca);
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