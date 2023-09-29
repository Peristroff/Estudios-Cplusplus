#include <iostream>
#include <limits>
#include "menu.h"
#include "cliente.h"
#include "precios.h"
#include "vehiculo.h"
#include "administradorDeArchivos.h"
#include "CSVparser.hpp"
using namespace std;

int main() {
    CrearArchivo();

    Menu menu;
    Cliente cliente("", "");
    Vehiculo vehiculo(0, 0, 0, "", "", "");
    int opcion;

    do {
        menu.MostrarMenu();
        cout << "Ingrese su eleccion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cliente.PedirDatosC();
                vehiculo.PedirDatosVehiculo();

                EscribirArchivo(cliente.nombre, cliente.rut, vehiculo.tipoAuto, marcaG, vehiculo.numeroMotor, vehiculo.cantidadRuedas, vehiculo.tipoCombustible, vehiculo.tanque, vehiculo.anoFabricacion, precioG);
                break;
            case 2:
                menu.Submenu1();
                break;
            case 3:
                menu.Submenu2();
                break;
            case 4:
                menu.Submenu3();
                break;
            case 5:
                cout << "Saliendo del programa...\n" << endl;
                break;
            default:
                cout << "\nOpcion no válida. Intente de nuevo." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (opcion != 5);

    return 0;
}