#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "estudiante.h"
#include "materias.h"
#include "inscripciones.h"

//Funciones de Lectura
Estudiante leerEstudianteCSV(const char *rutaArchivo);
void leerMateriasCSV(const char *rutaArchivo, ListaMaterias *listaDeMaterias);
void leerInscripcionesCSV(const char *rutaArchivo, ListaInscripciones *listaDeInscripciones);

//Funciones de Exportacion/Guardar
void guardarEstudianteCSV(const char *ruta, Estudiante *estudiante);
void guardarMateriasCSV(const char *ruta, ListaMaterias *listaMaterias);
void guardarInscripcionesCSV(const char *ruta, ListaInscripciones *listaInscripciones);
#endif // PERSISTENCIA_H

