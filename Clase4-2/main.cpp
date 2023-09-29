#include <iostream>
#include "persona.h"
using namespace std;

int main() {
  Profesor P("","");
  Estudiante E("","",0.0);

  E.pedirDatosE();
  E.mostrarDatosE();
  P.pedirDatosP();
  P.mostrarDatosP();
  
  return 0;
}