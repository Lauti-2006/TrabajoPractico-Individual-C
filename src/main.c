#include "inscripciones.h"
#include "materias.h"
#include "estudiante.h"

int main()
{
    Estudiante estudiante;
    ListaMaterias listaMaterias;
    ListaInscripciones listaInscripciones;

    altaEstudiante(&estudiante, 1, "Juan Gonzalez", 21);
    inicializarListaDeMaterias(&listaMaterias);
    inicializarListaInscripciones(&listaInscripciones);

    int idProgramacion = altaMateria(&listaMaterias, "Programacion", 6);
    int idBaseDeDatos = altaMateria(&listaMaterias, "Base de Datos", 5);

    inscribirEnMateria(&listaInscripciones, estudiante.id, idProgramacion);
    inscribirEnMateria(&listaInscripciones, estudiante.id, idBaseDeDatos);

    registrarNotas(&listaInscripciones, idProgramacion, 8.5f, 7.0f);
    registrarNotas(&listaInscripciones, idBaseDeDatos, 5.0f, 6.0f);

    mostrarEstudiante(&estudiante);
    listarMaterias(&listaMaterias);
    listarInscripciones(&listaInscripciones, &listaMaterias);

    return 0;
}