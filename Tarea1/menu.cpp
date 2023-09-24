#include <iostream>
#include "menu.h"
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
}

void Menu::Submenu2()
{
    cout << "\nMostrar cantidad de vehiculos comprados:" << endl;
    SubmenuRaiz();
}

void Menu::Submenu3()
{
    cout << "\nMostrar ventas de vehiculos:" << endl;
    SubmenuRaiz();
}