#ifndef FUNCIONES_H
#define FUNCIONES_H

void CrearArchivo();

// Estos son los parametros por defecto que recibe la funcion si estan vacios
void EscribirArchivo(string nombreCliente = "", string rutCliente = "", string tipoVehiculo = "", string marca = "", int numeroMotor = 0, int cantidadRuedas = 0, string tipoCombustible = "", string tanque = "", int anoFabricacion = 0, int precio = 0);

void AnalizarArchivo();

int CantidadVehiculos(string tipoVehiculo);
int VendidoVehiculos(string tipoVehiculo);
int PromedioVehiculos(string tipoVehiculo);
int PromedioGeneral();

#endif