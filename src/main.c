#include <stdio.h> // Para printf
#include "inscripciones.h"
#include "materias.h"
#include "estudiante.h"
#include "persistencia.h"

int main()
{
   Estudiante estudiante;
   ListaMaterias listaMaterias;
   ListaInscripciones listaInscripciones;

   estudiante = leerEstudianteCSV("../data/estudiante.csv");
   leerMateriasCSV("../data/materias.csv", &listaMaterias);
   leerInscripcionesCSV("../data/inscripciones.csv", &listaInscripciones);

   mostrarEstudiante(&estudiante);
   listarMaterias(&listaMaterias);
   listarInscripciones(&listaInscripciones, &listaMaterias);


    return 0;
}