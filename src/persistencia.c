#include "persistencia.h"
#include <stdio.h>
#include <stdlib.h>

// Implementación de funciones de persistencia (lectura y escritura de archivos)

Estudiante leerEstudianteCSV(const char *rutaArchivo)
{
    Estudiante est;
    FILE *archivo = fopen(rutaArchivo, "r");
    if (!archivo)
    {
        printf("No se pudo Abrir el Archivo %s\n", rutaArchivo);
        exit(1);
    }

    char linea[200];
    fgets(linea, sizeof(linea), archivo);
    fscanf(archivo, "%d,%49[^,], %d", &est.id, est.nombre, &est.edad);
    fclose(archivo);
    return est;
}

void leerMateriasCSV(const char *rutaArchivo, ListaMaterias *listaDeMaterias)
{
    FILE *archivo = fopen(rutaArchivo, "r");
    if (!archivo)
    {
        printf("No se pudo Abrir el Archivo %s\n", rutaArchivo);
        exit(1);
    }

    inicializarListaDeMaterias(listaDeMaterias);
    char linea[200];
    fgets(linea, sizeof(linea), archivo);
    int id, creditos;
    char nombre[NOMBRE_MAX];

    while (fscanf(archivo, "%d,%49[^,], %d", &id, nombre, &creditos) == 3)
    {
        asegurarCapacidadMaterias(listaDeMaterias);
        Materia nuevaMateria;
        nuevaMateria.id = id;
        strcpy(nuevaMateria.nombre, nombre);
        nuevaMateria.creditos = creditos;
        listaDeMaterias->materias[listaDeMaterias->cantidad++] = nuevaMateria;
        if (id >= listaDeMaterias->next_id)
        {
            listaDeMaterias->next_id = id + 1;
        }
    }
    fclose(archivo);
}

void leerInscripcionesCSV(const char *rutaArchivo, ListaInscripciones *listaDeInscripciones)
{
    FILE *archivo = fopen(rutaArchivo, "r");
    if (!archivo)
    {
        printf("No se pudo Abrir el Archivo %s\n", rutaArchivo);
        exit(1);
    }

    inicializarListaInscripciones(listaDeInscripciones);
    char linea[200];
    fgets(linea, sizeof(linea), archivo);
    int idEst, idMat;
    float nota1, nota2, promedio;
    char estado[20];

    while (fscanf(archivo, "%d,%d,%f,%f,%f,%19s", &idEst, &idMat, &nota1, &nota2, &promedio, estado) == 6)
    {
        asegurarCapacidadInscripciones(listaDeInscripciones);
        Inscripcion nuevaInscripcion;
        nuevaInscripcion.idEstudiante = idEst;
        nuevaInscripcion.idMateria = idMat;
        nuevaInscripcion.nota1 = nota1;
        nuevaInscripcion.nota2 = nota2;
        nuevaInscripcion.promedio = promedio;
        strcpy(nuevaInscripcion.estado, estado);
        listaDeInscripciones->inscripciones[listaDeInscripciones->cantidad++] = nuevaInscripcion;
    }
    fclose(archivo);
}