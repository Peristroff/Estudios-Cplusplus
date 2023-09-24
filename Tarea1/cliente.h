#include <iostream>
#include <string>
using namespace std;

class Cliente
{
    public:
        string nombre, rut;
        Cliente(string nombre, string rut);
        ~Cliente();

        void PedirDatosC();
};