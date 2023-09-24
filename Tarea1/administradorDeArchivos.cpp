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
string Minusculas(string palabra)
{
    for (char &c : palabra) {
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }

    return palabra;
}
int CantidadVehiculos(string tipoVehiculo)
{
    // Para contar la cantidad de vehiculos
    csv::Parser file = csv::Parser("Salida.csv");
    tipoVehiculo = Minusculas(tipoVehiculo);

    int AU, CA, MO = 0;
    unsigned int j = 2;

    for (unsigned int i = 0; i < file.rowCount(); i++)
    {
        if (file[i][j] == tipoVehiculo && tipoVehiculo == "auto")
        {
            AU++;
        }
        if(file[i][j] == tipoVehiculo && tipoVehiculo == "camion")
        {
            CA++;
        }
        if(file[i][j] == tipoVehiculo && tipoVehiculo == "moto")
        {
            MO++;
        }
    }
    if (tipoVehiculo == "auto")
    {
        return AU;
    }
    if (tipoVehiculo == "camion")
    {
        return CA;
    }
    if (tipoVehiculo == "moto")
    {
        return MO;
    }
    else{ cout << "No se encontro ese vehiculo" << endl; return -1;}

}

int VendidoVehiculos(string tipoVehiculo)
{
    // Cantidad vendida de los vehiculos por tipo
    csv::Parser file = csv::Parser("Salida.csv");
    tipoVehiculo = Minusculas(tipoVehiculo);
    
    int AU, CA, MO, valor = 0;
    unsigned int j = 9;

    for (unsigned int i = 0; i < file.rowCount(); i++)
    {
        if (file[i][2] == tipoVehiculo && tipoVehiculo == "auto")
        {
            valor = (stoi(file[i][j]));;
            AU += valor;
        }
        if(file[i][2] == tipoVehiculo && tipoVehiculo == "camion")
        {
            valor = (stoi(file[i][j]));;
            CA += valor;
        }
        if(file[i][2] == tipoVehiculo && tipoVehiculo == "moto")
        {
            valor = (stoi(file[i][j]));;
            MO += valor;
        }
    }
    if (tipoVehiculo == "auto")
    {
        return AU;
    }
    if (tipoVehiculo == "camion")
    {
        return CA;
    }
    if (tipoVehiculo == "moto")
    {
        return MO;
    }
    else{ cout << "No se encontro ese vehiculo" << endl; return -1;}

}

int PromedioVehiculos(string tipoVehiculo)
{
    // Calcular el promedio de los vehiculos por tipo
    tipoVehiculo = Minusculas(tipoVehiculo);
    int AU, CA, MO, promedio = 0;

    if (tipoVehiculo == "auto")
    {
        AU = VendidoVehiculos(tipoVehiculo);
        promedio = AU / CantidadVehiculos(tipoVehiculo);
        return promedio;
    }
    if (tipoVehiculo == "camion")
    {
        CA = VendidoVehiculos(tipoVehiculo);
        promedio = CA / CantidadVehiculos(tipoVehiculo);
        return promedio;
    }
    if (tipoVehiculo == "moto")
    {
        MO = VendidoVehiculos(tipoVehiculo);
        promedio = MO / CantidadVehiculos(tipoVehiculo);
        return promedio;
    }
    else{ cout << "No se encontro ese vehiculo" << endl; return -1;}

}

int PromedioGeneral()
{
    // Promedio general de los vehiculos vendidos
    csv::Parser file = csv::Parser("Salida.csv");
    int promedio = 0;
    int valor = 0;
    unsigned int j = 9;

    for (unsigned int i = 0; i < file.rowCount(); i++)
    {
        valor = (stoi(file[i][j]));
        promedio += valor;
    }
    promedio = promedio / static_cast<int>(file.rowCount());
    return promedio;
    
}
