#include <iostream>
#include <string>
#include <fstream>
#include "CSVparser.hpp"
using namespace std;

void CrearArchivo()
{
    if ("Salida.csv"){
        remove("Salida.csv");

        string nombreArchivo = "Salida.csv";
        string cabecera = "Nombre del cliente, RUT, Tipo de vehiculo comprado, Marca, N° de motor, Cantidad de ruedas, Tipo de automovil, Tanque de combustible, Año, Precio";
        ofstream archivoSalida;
        archivoSalida.open(nombreArchivo, ios::app);
        archivoSalida << cabecera << endl;
        archivoSalida.close();
    }
    
}

void EscribirArchivo()
{
    string nombreArchivo = "Salida.csv";
    string fila = "Jerry,123456,Auto,Honda,123456789,4,Electrico,No,2023,3";
    string fila2 = "Jerry,123456,Auto,Honda,123456789,4,Electrico,No,2023,5";
    ofstream archivoSalida;
    archivoSalida.open(nombreArchivo, ios::app);
    archivoSalida << fila << endl;
    archivoSalida << fila2 << endl;
    archivoSalida.close();
}

void AnalizarArchivo() 
{
    csv::Parser file = csv::Parser("Salida.csv");
    
    // Para calcular la cantidad de dinero hecho
    int k = 0;
    int l = 0;
    for (int i = 0; i < file.rowCount(); i++)
    {
        int j = 9;
        k = (stoi(file[i][j]));
        l += k;
    }
        cout << "Cantidad de dinero hecho: $" << l << endl;

    // Para calcular la cantidad de vehiculos vendidos
    int m = 0;
    for (int i = 0; i < file.rowCount(); i++)
    {
        int j = 2;
        m++;
    }
        cout << "Cantidad de vehiculos vendidos: " << m << endl;

    // Para calcular la cantidad de vehiculos vendidos por tipo
    int n = 0;
    int o = 0;
    int p = 0;
    int q = 0;    

    int j = 2;

    string tipo = file[0][j];

    for (int i = 0; i < file.rowCount(); i++)
    {
        if (tipo == "Auto")
        {
            n++;
        }
        else if (file[i][j] == "Camioneta")
        {
            o++;
        }
        else if (file[i][j] == "Camion")
        {
            p++;
        }
        else if (file[i][j] == "Moto")
        {
            q++;
        }
    }
        cout << "Cantidad de autos vendidos: " << n << endl;
        cout << "Cantidad de camionetas vendidas: " << o << endl;
        cout << "Cantidad de camiones vendidos: " << p << endl;
        cout << "Cantidad de motos vendidas: " << q << endl;
}