#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <stdbool.h>
#define NOMBRE_MAX 50

typedef struct
{
    int id;
    char nombre[NOMBRE_MAX];
    int edad;
} Estudiante;

// Funciones Basicas

void altaEstudiante(Estudiante *estudiante, int id, const char *nombre, int edad);
void mostrarEstudiante(const Estudiante *estudiante);
void modificarEstudiante(Estudiante *estudiante, const char *nuevoNombre, int nuevaEdad);

#endif // ESTUDIANTE_H
