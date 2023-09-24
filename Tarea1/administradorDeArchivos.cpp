#include <iostream>
#include <string>
#include <fstream>
#include "CSVparser.hpp"
using namespace std;

void CrearArchivo()
{
    // Se ve un  poco extraño que elimine el anterior, pero es para que no se sobreescriba la cabecera una vez que el programa se ejecuta
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

void EscribirArchivo(string nombreCliente , string rutCliente , string tipoVehiculo , string marca , int numeroMotor, int cantidadRuedas, string tipoCombustible , string tanque , int anoFabricacion, int precio)
{
    string nombreArchivo = "Salida.csv";
    string fila = nombreCliente + "," + rutCliente + "," + tipoVehiculo + "," + marca + "," + to_string(numeroMotor) + "," + to_string(cantidadRuedas) + "," + tipoCombustible + "," + tanque + "," + to_string(anoFabricacion) + "," + to_string(precio);
    ofstream archivoSalida;
    archivoSalida.open(nombreArchivo, ios::app);
    archivoSalida << fila << endl;
    archivoSalida.close();
}

void AnalizarArchivo() 
{
    csv::Parser file = csv::Parser("Salida.csv");
    
    // Para calcular la cantidad de dinero hecho
    int k = 0;
    int l = 0;
    unsigned int j = 9;

    for (unsigned int i = 0; i < file.rowCount(); i++)
    {
        k = (stoi(file[i][j]));
        l += k;
    }

    int autos = 0;
    int promedioAutos = 0;
    
    for (unsigned int i = 0; i < file.rowCount(); i++)
    {
        if (file[i][j] == "Auto")
        {
            autos++;
        }
    }

    promedioAutos = l / autos;
    cout << "Cantidad de dinero hecho: $" << l << endl;

    // Para calcular la cantidad de vehiculos vendidos
    int m = 0;
    for (unsigned int i = 0; i < file.rowCount(); i++)
    {
        m++;
    }
    
    cout << "Cantidad de vehiculos vendidos: " << m << endl;

    // Para calcular la cantidad de vehiculos vendidos por tipo
    int n = 0;
    int o = 0;
    int p = 0;    

    string tipo = file[0][j];

    for (unsigned int i = 0; i < file.rowCount(); i++)
    {
        if (tipo == "Auto")
        {
            n++;
        }
        else if (file[i][j] == "Camion")
        {
            o++;
        }
        else if (file[i][j] == "Moto")
        {
            p++;
        }
    }
        cout << "Cantidad de autos vendidos: " << n << endl;
        cout << "Cantidad de camiones vendidos: " << o << endl;
        cout << "Cantidad de motos vendidas: " << p << endl;
}