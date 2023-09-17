#include <iostream>
#include "menu.h"
using namespace std;

void Menu::MostrarMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Realizar una venta" << endl;
    cout << "2. Ver promedio de ventas" << endl;
    cout << "3. Ver cantidad de vehiculos comprados" << endl;
    cout << "4. Ver ventas de vehiculos" << endl;
    cout << "5. Salir" << endl;
}