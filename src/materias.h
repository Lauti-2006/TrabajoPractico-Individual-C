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
} ListaMaterias;

// Funciones Principales
void inicializarListaDeMaterias(ListaMaterias *listaMaterias);
void liberarListaDeMaterias(ListaMaterias *listaMaterias);
void asegurarCapacidadMaterias(ListaMaterias *listaMaterias);

// Funciones Basicas
int altaMateria(ListaMaterias *listaMaterias, const char *nombre, int creditos);
bool bajaMateria(ListaMaterias *listaMaterias, int id);
bool modificarMateria(ListaMaterias *listaMaterias, int id, const char *nuevoNombre, int nuevosCreditos);
void listarMaterias(const ListaMaterias *listaMaterias);

#endif // MATERIAS_H
