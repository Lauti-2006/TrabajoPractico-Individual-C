#ifndef MATERIAS_H
#define MATERIAS_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOMBRE_MAX 50

typedef struct
{
    int id;
    char nombre[NOMBRE_MAX];
    int creditos;
} Materia;

typedef struct
{
    Materia *materias;
    int cantidad;
    int capacidad;
    int next_id;
} Materias;

// Funciones Principales
void inicializarListaDeMaterias(Materias *listaMaterias);
void liberarListaDeMaterias(Materias *listaMaterias);

// Funciones Basicas
void altaMateria(Materias *listaMaterias, const char *nombre, int creditos);
bool bajaMateria(Materias *listaMaterias, int id);
bool modificarMateria(Materias *listaMaterias, int id, const char *nuevoNombre, int nuevosCreditos);
void listarMaterias(const Materias *listaMaterias);

#endif // MATERIAS_H
