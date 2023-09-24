#include <iostream>
#include <string>
#include <fstream>
#include "CSVparser.hpp"
using namespace std;

// Esta funcion crea el archivo .csv, pero elimina el antiguo para refrescar el contenido
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
    else 
    {
        string nombreArchivo = "Salida.csv";
        string cabecera = "Nombre del cliente, RUT, Tipo de vehiculo comprado, Marca, N° de motor, Cantidad de ruedas, Tipo de automovil, Tanque de combustible, Año, Precio";
        ofstream archivoSalida;
        archivoSalida.open(nombreArchivo, ios::app);
        archivoSalida << cabecera << endl;
        archivoSalida.close();
    }
    
}

// Esta funcion escribe en el archivo .csv
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
    // Para contar la cantidad de vehículos
    csv::Parser file = csv::Parser("Salida.csv");
    tipoVehiculo = Minusculas(tipoVehiculo);

    int AU = 0, CA = 0, MO = 0;
    unsigned int j = 2;

    for (unsigned int i = 0; i < file.rowCount(); i++)
    {
        if (file[i][j] == tipoVehiculo)
        {
            if (tipoVehiculo == "auto")
            {
                AU++;
            }
            if (tipoVehiculo == "camion mediano")
            {
                CA++;
            }
            if (tipoVehiculo == "moto")
            {
                MO++;
            }
        }
    }

    if (tipoVehiculo == "auto")
    {
        return AU;
    }
    else if (tipoVehiculo == "camion mediano")
    {
        return CA;
    }
    else if (tipoVehiculo == "moto")
    {
        return MO;
    }
    else
    {
        cout << "No se encontro ese vehiculo" << endl;
        return -1;
    }
}

int VendidoVehiculos(string tipoVehiculo)
{
    // Cantidad vendida de los vehiculos por tipo
    csv::Parser file = csv::Parser("Salida.csv");
    tipoVehiculo = Minusculas(tipoVehiculo);
    
    int AU = 0, CA = 0, MO= 0, valor = 0;
    unsigned int j = 9;

    for (unsigned int i = 0; i < file.rowCount(); i++)
    {
        if (file[i][2] == tipoVehiculo)
        {
            valor = stoi(file[i][j]);
            cout << "Valor: " << valor << endl;

            if (tipoVehiculo == "auto")
            {
                AU += valor;
            }
            else if (tipoVehiculo == "camion mediano")
            {
                CA += valor;
            }
            else if (tipoVehiculo == "moto")
            {
                MO += valor;
            }
        }
    }
    if (tipoVehiculo == "auto")
        {
            return AU;
        }
        else if (tipoVehiculo == "camion mediano")
        {
            return CA;
        }
        else if (tipoVehiculo == "moto")
        {
            return MO;
        }
        else
        {
            cout << "No se encontro ese vehiculo" << endl;
            return -1;
        }
}

int PromedioVehiculos(string tipoVehiculo)
{
    // Calcular el promedio de los vehículos por tipo
    tipoVehiculo = Minusculas(tipoVehiculo);
    int AU = 0, AU2 = 0, CA = 0, CA2 = 0, MO = 0, MO2 = 0, promedio = 0;

    if (tipoVehiculo == "auto" || tipoVehiculo == "camion mediano" || tipoVehiculo == "moto")
    {
        csv::Parser file = csv::Parser("Salida.csv");

        for (unsigned int i = 0; i < file.rowCount(); i++)
        {
            if (file[i][2] == tipoVehiculo)
            {
                int valor = stoi(file[i][9]);
                if (tipoVehiculo == "auto")
                {
                    AU += valor;
                    AU2++;
                }
                else if (tipoVehiculo == "camion mediano")
                {
                    CA += valor;
                    CA2++;
                }
                else if (tipoVehiculo == "moto")
                {
                    MO += valor;
                    MO2++;
                }
            }
        }

        if (tipoVehiculo == "auto")
        {
            promedio = AU / AU2;
        }
        else if (tipoVehiculo == "camion mediano")
        {
            promedio = CA / CA2;
        }
        else if (tipoVehiculo == "moto")
        {
            promedio = MO / MO2;
        }
        return promedio;
    }
    else
    {
        cout << "No se encontró ese vehículo" << endl;
        return -1;
    }
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