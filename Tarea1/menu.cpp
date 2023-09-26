#include <iostream>
#include "menu.h"
#include "administradorDeArchivos.h"
using namespace std;

// Menu para navegar en las distintas funciones del codigo
void Menu::MostrarMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Realizar una venta" << endl;
    cout << "2. Ver promedio de ventas" << endl;
    cout << "3. Ver cantidad de vehiculos comprados" << endl;
    cout << "4. Ver ventas de vehiculos" << endl;
    cout << "5. Salir" << endl;
}

void Menu::SubmenuRaiz()
{
    cout << "1. Autos" << endl;
    cout << "2. Motos" << endl;
    cout << "3. Camiones medianos" << endl;
    cout << "4. Total" << endl;
}

void Menu::Submenu1()
{
    cout << "\nMostrar promedio de ventas:" << endl;
    SubmenuRaiz();
    int opcion;
    cout << "Ingrese una opción: ";
    cin >> opcion;

        switch (opcion) 
        {
            case 1:
                cout << "Promedio de ventas de Autos: $" << PromedioVehiculos("auto") << endl;
                break;
            case 2:
                cout << "Promedio de ventas de Motos: $" << PromedioVehiculos("moto") << endl;
                break;
            case 3:
                cout << "Promedio de ventas de Camiones: $" << PromedioVehiculos("camiones") << endl;
                break;
            case 4:
                cout << "Promedio de ventas totales de vehículos: $" << PromedioGeneral() << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
}

void Menu::Submenu2()
{
    cout << "\nMostrar cantidad de vehiculos comprados:" << endl;
    SubmenuRaiz();
    int opcion;
    cout << "Ingrese una opción: ";
    cin >> opcion;

    switch (opcion) 
        {
            case 1:
                cout << "Cantidad de autos vendidos: " << CantidadVehiculos("auto") << endl;
                break;
            case 2:
                cout << "Cantidad de motos vendidas: " << CantidadVehiculos("moto") << endl;
                break;
            case 3:
                cout << "Cantidad de camiones vendidos: " << CantidadVehiculos("camiones") << endl;
                break;
            case 4:
                int total;
                cout << "Vehiculos totales vendidos" << endl;
                cout << "\nAutos: " << CantidadVehiculos("auto") << endl;
                cout << "Motos: " << CantidadVehiculos("moto") << endl;
                cout << "Camiones medianos: " << CantidadVehiculos("camion mediano") << endl;
                total = CantidadVehiculos("auto") + CantidadVehiculos("moto") + CantidadVehiculos("camion mediano");
                cout << "Vehiculos vendidos en total: " << total << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
}

void Menu::Submenu3()
{
    cout << "\nMostrar ventas de vehiculos:" << endl;
    SubmenuRaiz();
    int opcion;
    cout << "Ingrese una opción: ";
    cin >> opcion;
        switch (opcion) {
        case 1:
            cout << "Ventas de Autos: $" << VendidoVehiculos("auto") << endl;
            break;
        case 2:
            cout << "Ventas de Motos: $" << VendidoVehiculos("moto") << endl;
            break;
        case 3:
            cout << "Ventas de Camiones: $" << VendidoVehiculos("camion mediano") << endl;
            break;
        case 4:
            cout << "Ventas totales de vehículos" << endl;
            cout << "\nAutos: $" << VendidoVehiculos("auto") << endl;
            cout << "Motos: $" << VendidoVehiculos("moto") << endl;
            cout << "Camiones medianos: $" << VendidoVehiculos("camion mediano") << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
    }
}