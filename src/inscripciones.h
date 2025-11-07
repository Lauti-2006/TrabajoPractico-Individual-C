#ifndef INSCRIPCIONES_H
#define INSCRIPCIONES_H
#include <stdbool.h>
#include "materias.h"

typedef struct
{
    int idEstudiante;
    int idMateria;
    float nota1;
    float nota2;
    float promedio;
    char estado[20]; // "Promociona", "Final" o "Desaprobado"
} Inscripcion;

typedef struct
{
    Inscripcion *inscripciones;
    int cantidad;
    int capacidad;
} ListaInscripciones;

// Funciones Principales
void inicializarListaInscripciones(ListaInscripciones *lista);
void liberarListaInscripciones(ListaInscripciones *lista);

// Funciones Basicas
bool inscribirEnMateria(ListaInscripciones *listaDeInscripciones, int idEstudiante, int idMateria);
void listarInscripciones(const ListaInscripciones *listaDeInscripciones, const ListaMaterias *listaDeMaterias);
bool registrarNotas(ListaInscripciones *listaDeInscripciones, int idMateria, float nota1, float nota2);
void calcularEstado(Inscripcion *inscripcion);

#endif // INSCRIPCIONES_H