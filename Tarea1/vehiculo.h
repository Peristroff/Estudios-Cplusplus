#include <iostream>
#include <string>
using namespace std;

//Clase padre vehiculo, con los atributos numeroMotor, cantidadRuedas, tipoCombustible, anoFabricacion, tipoAuto, tanque
class vehiculo 
{
    // En vez de la variable deposito de combustible, se va a dejar la variable capTanque, que se debe ingresar los litros si es gasolina y el string NO si es electrico  
    public:
        int numeroMotor, cantidadRuedas, tipoCombustible, anoFabricacion;
        string tipoAuto, tanque;

        vehiculo(int numeroMotor, int cantidadRuedas, int tipoCombustible, int anoFabricacion, string tipoAuto, string tanque);
        ~vehiculo();

        void PedirDatosVehiculo();
        void MostrarDatosv();
};
//Clase hijo de vehiculo, heredero de los atributos mas la variable marca y precio
class Auto:public vehiculo
{
    
    public:
        string marca;
        int precio;

        Auto(string marca, int precio);
        ~Auto();
        
        void pedirDatosa();
        void mostrarDatosa();
        void calcularPrecio();
};

class Moto:public vehiculo
{
    protected:
        string marca;
    
    public:
        int precio;
        
        Moto(string marca, int precio);
        ~Moto();

        void pedirDatosm();
        void mostrarDatosm();
        void calcularPrecio();

};

class CamionMediano:public vehiculo
{
    protected:
        string marca;
    public:
        int precio;

        CamionMediano(string marca, int precio);
        ~CamionMediano();

        void pedirDatoscm();
        void mostrarDatoscm();
        void calcularPrecio();
};

class cliente:public vehiculo, public Auto, public Moto, public CamionMediano  
{
    protected:
        string nombre, rut;
    public:
        cliente(string nombre, string rut);
        ~cliente();

        void pedirDatosc();
        void mostrarDatosc();
};