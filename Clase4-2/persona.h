#include <iostream>
using namespace std;

class Persona{
  protected:
    string nombre,rut,direccion,telefono,sexo,correo;
  public:
    Persona(string nombre,string rut,string direccion,string telefono,string sexo,string correo);
    ~Persona();
    void pedirDatos();
    void mostrarDatos();
};

class Profesor:public Persona{
  string cargo,categoria;
  public:
    Profesor(string cargo,string categoria);
    ~Profesor();
    void pedirDatosP();
    void mostrarDatosP();
};

class Estudiante:public Persona{
  string carrera,sede;
  double PPA;
  public:
    Estudiante(string carrera,string sede,double PPA);
    ~Estudiante();
    void pedirDatosE();
    void mostrarDatosE();
};