#include <iostream>
#include "menu.h"
#include "cliente.h"
#include "precios.h"
#include "vehiculo.h"
using namespace std;

// TODO Jerry menciono que la forma que hay que manejar el archivo en que se guardan los datos, puede ser un array, en archivo .json o .csv
int main() {
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
                break;
            case 2:
                // TODO ingresar funcion para ver promedio de ventas
                break;
            case 3:
                // TODO ingresar funcion para ver cantidad de vehiculos comprados
                break;
            case 4:
                // TODO ingresar funcion para ver ventas de vehiculos
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "\nOpcion no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}