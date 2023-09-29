#include <iostream>
#include "persona.h"
using namespace std;

Persona::Persona(string nombrePersona,string rutPersona,string direccionPersona,string telefonoPersona,string sexoPersona,string correoPersona){
  this->nombre = nombrePersona;
  this->rut = rutPersona;
  this->direccion = direccionPersona;
  this->telefono = telefonoPersona;
  this->sexo = sexoPersona;
  this->correo = correoPersona;
}

Persona::~Persona(){
  cout<<"\nSaliendo de Persona"<<endl;
}

void Persona::pedirDatos(){
  cout<<"Escriba el Nombre ";
  cin>>this->nombre;
  cout<<"Escriba el RUT ";
  cin>>this->rut;
  cout<<"Escriba la Dirección ";
  cin>>this->direccion;
  cout<<"Escriba el Telefono ";
  cin>>this->telefono;
  cout<<"Escriba el Sexo ";
  cin>>this->sexo;
  cout<<"Escriba el Correo ";
  cin>>this->correo;
}

void Persona::mostrarDatos(){
  cout<<"Nombre: "<<this->nombre<<endl;
  cout<<"RUT: "<<this->rut<<endl;
  cout<<"Dirección: "<<this->direccion<<endl;
  cout<<"Fono: "<<this->telefono<<endl;
  cout<<"Sexo: "<<this->sexo<<endl;
  cout<<"Correo: "<<this->correo<<endl;
}

Profesor::Profesor(string cargoProfesor,string categoriaProfesor):Persona("nombre","rut","direccion","telefono","sexo","correo"){
  this->nombre = nombre;
  this->rut = rut;
  this->direccion = direccion;
  this->telefono = telefono;
  this->sexo = sexo;
  this->correo = correo;
  this->cargo = cargoProfesor;
  this->categoria = categoriaProfesor;
}

Profesor::~Profesor(){
  cout<<"Liberando Profesor"<<endl;
}

void Profesor::pedirDatosP(){
  pedirDatos();
  cout<<"Escriba el Cargo ";
  cin>>this->cargo;
  cout<<"Escriba la Categoria ";
  cin>>this->categoria;
}

void Profesor::mostrarDatosP(){
  mostrarDatos();
  cout<<"Cargo: "<<this->cargo<<endl;
  cout<<"Categoria: "<<this->categoria<<endl;
}

Estudiante::Estudiante(string carreraEstudiante,string sedeEstudiante,double PPAEstudiante):Persona("nombre","rut","direccion","telefono","sexo","correo"){
  this->nombre = nombre;
  this->rut = rut;
  this->direccion = direccion;
  this->telefono = telefono;
  this->sexo = sexo;
  this->correo = correo;
  this->carrera = carreraEstudiante;
  this->sede = sedeEstudiante;
  this->PPA = PPAEstudiante;
}

Estudiante::~Estudiante(){
  cout<<"Liberando Estudiante"<<endl;
}

void Estudiante::pedirDatosE(){
  pedirDatos();
  cout<<"Escriba la Carrera ";
  cin>>this->carrera;
  cout<<"Escriba la Sede ";
  cin>>this->sede;
  cout<<"Escriba el PPA ";
  cin>>this->PPA;
}

void Estudiante::mostrarDatosE(){
  mostrarDatos();
  cout<<"Carrera: "<<this->carrera<<endl;
  cout<<"Sede: "<<this->sede<<endl;
  cout<<"PPA: "<<this->PPA<<endl;
}