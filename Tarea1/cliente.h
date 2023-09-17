#include <iostream>
#include <string>
using namespace std;

class Cliente
{
    protected:
        string nombre, rut;
    public:
        Cliente(string nombre, string rut);
        ~Cliente();

        void PedirDatosC();
        void MostrarDatosC();
        void VentaVehiculo();
        void ReporteMensual();
        void ClienteQueComproMas();
        void CantidadDeAutosComprados();
        void CantidadDeMotosCompradas();
        void CantidadDeCamionesComprados();
        void CantidadTotalDeVehiculosComprados();
        void TotalDeVentasDeAutos();
        void TotalDeVentasDeMotos();
        void TotalDeVentasDeCamiones();
        void TotalDeVentasDeVehiculos();
        void PromedioDeVentasDeAutos();
        void PromedioDeVentasDeMotos();
        void PromedioDeVentasDeCamiones();
        void PromedioDeVentasTotalesDeVehiculos();
};