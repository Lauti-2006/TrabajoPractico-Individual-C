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
        printf("No se Pudo Abrir. Primero debe Exportar los Datos %s\n", rutaArchivo);
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
        printf("No se Pudo Abrir. Primero debe Exportar los Datos %s\n", rutaArchivo);
        exit(1);
    }

    inicializarListaDeMaterias(listaDeMaterias);
    char linea[200];
    fgets(linea, sizeof(linea), archivo);
    int id, creditos;
    char nombre[NOMBRE_MAX];

    while (fscanf(archivo, "%d,%80[^,],%d", &id, nombre, &creditos) == 3)
    {
        nombre[NOMBRE_MAX - 1] = '\0'; // Asegurar terminación nula
        asegurarCapacidadMaterias(listaDeMaterias);
        Materia nuevaMateria;
        nuevaMateria.id = id;
        strcpy(nuevaMateria.nombre, nombre);
        nuevaMateria.nombre[NOMBRE_MAX - 1] = '\0'; // Asegurar terminación nula
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
        printf("No se Pudo Abrir. Primero debe Exportar los Datos %s\n", rutaArchivo);
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

void guardarEstudianteCSV(const char *ruta, Estudiante *estudiante)
{
    FILE *archivo = fopen(ruta, "w");
    if (!archivo)
    {
        printf("No Se Pudo Guardar el Archivo\n");
        return;
    }
    fprintf(archivo, "id,nombre,edad\n");
    fprintf(archivo, "%d,%s,%d\n", estudiante->id, estudiante->nombre, estudiante->edad);
    fclose(archivo);
}

void guardarMateriasCSV(const char *ruta, ListaMaterias *listaMaterias)
{
    FILE *archivo = fopen(ruta, "w");
    if (!archivo)
    {
        printf("No se Pudo Guardar el Archivo\n");
        return;
    }
    fprintf(archivo, "id,nombre,creditos\n");
    for (int i = 0; i < listaMaterias->cantidad; i++)
    {
        Materia *materia = &listaMaterias->materias[i];
        fprintf(archivo, "%d,%s,%d\n", materia->id, materia->nombre, materia->creditos);
    }
    fclose(archivo);
}

void guardarInscripcionesCSV(const char *ruta, ListaInscripciones *listaInscripciones)
{
    FILE *archivo = fopen(ruta, "w");
    if (!archivo)
    {
        printf("No se Pudo Guardar el Archivo\n");
        return;
    }
    fprintf(archivo, "idEstudiante,idMateria,nota1,nota2,promedio,estado\n");
    for (int i = 0; i < listaInscripciones->cantidad; i++)
    {
        Inscripcion *inscripcion = &listaInscripciones->inscripciones[i];
        fprintf(archivo, "%d,%d,%.2f,%.2f,%.2f,%s\n",
                inscripcion->idEstudiante,
                inscripcion->idMateria,
                inscripcion->nota1,
                inscripcion->nota2,
                inscripcion->promedio,
                inscripcion->estado);
    }
    fclose(archivo);
}