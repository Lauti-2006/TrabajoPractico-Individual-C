#include "estudiante.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcion para dar de alta un Estudiante
void altaEstudiante(Estudiante *estudiante, int id, const char *nombre, int edad)
{
    estudiante->id = id;
    snprintf(estudiante->nombre, NOMBRE_MAX, "%s", nombre);
    estudiante->nombre[NOMBRE_MAX - 1] = '\0'; // Asegurar terminacion nula
    estudiante->edad = edad;
}

// Funcion para Mostrar los Datos del Estudiante
void mostrarEstudiante(const Estudiante *estudiante)
{
    printf("\n == Datos del Estudiante ==\n");
    printf("ID: %d\n", estudiante->id);
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
}

// Funcion para Modificar un Estudiante
void modificarEstudiante(Estudiante *estudiante, const char *nuevoNombre, int nuevaEdad)
{
    if (nuevoNombre && strlen(nuevoNombre) > 0)
    {
        snprintf(estudiante->nombre, NOMBRE_MAX, "%s", nuevoNombre);
        estudiante->nombre[NOMBRE_MAX - 1] = '\0'; // Asegurar terminacion nula
    }

    if (nuevaEdad > 0 && nuevaEdad != estudiante->edad)
    {
        estudiante->edad = nuevaEdad;
    }
}
