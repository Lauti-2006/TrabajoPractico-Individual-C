#include "inscripciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACIDAD_INICIAL 10

void asegurarCapacidadInscripciones(ListaInscripciones *lista)
{
    if (lista->cantidad < lista->capacidad)
        return;

    int nuevaCapacidad = (lista->capacidad == 0) ? CAPACIDAD_INICIAL : lista->capacidad * 2;
    Inscripcion *nuevasInscripciones = realloc(lista->inscripciones, nuevaCapacidad * sizeof(Inscripcion));
    if (!nuevasInscripciones)
    {
        fprintf(stderr, "Error al asignar memoria para inscripciones");
        exit(1);
    }
    lista->inscripciones = nuevasInscripciones;
    lista->capacidad = nuevaCapacidad;
}

void inicializarListaInscripciones(ListaInscripciones *lista)
{
    lista->inscripciones = NULL;
    lista->cantidad = 0;
    lista->capacidad = 0;
}

void liberarListaInscripciones(ListaInscripciones *lista)
{
    free(lista->inscripciones);
    lista->inscripciones = NULL;
    lista->cantidad = 0;
    lista->capacidad = 0;
}

void listarInscripciones(const ListaInscripciones *listaDeInscripciones, const ListaMaterias *listaDeMaterias)
{
    if (listaDeInscripciones->cantidad == 0)
    {
        printf("No hay Inscripciones para Mostrar.\n");
        return;
    }

    printf("\n == Listado de Inscripciones (%d) ==\n", listaDeInscripciones->cantidad);
    printf("Materia\t\tNota1\tNota2\tPromedio\tEstado\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < listaDeInscripciones->cantidad; i++)
    {
        const Inscripcion *insc = &listaDeInscripciones->inscripciones[i];
        const char *nombreMateria = "Desconocida";

        for (int j = 0; j < listaDeMaterias->cantidad; j++)
        {
            if (listaDeMaterias->materias[j].id == insc->idMateria)
            {
                nombreMateria = listaDeMaterias->materias[j].nombre;
                break;
            }
        }
        printf("%-15s\t%.2f\t%.2f\t%.2f\t\t%s\n", nombreMateria, insc->nota1, insc->nota2, insc->promedio, insc->estado);
    }
}

bool inscribirEnMateria(ListaInscripciones *listaDeInscripciones, int idEstudiante, int idMateria)
{

    for (int i = 0; i < listaDeInscripciones->cantidad; i++)
    {
        if (listaDeInscripciones->inscripciones[i].idMateria == idMateria)
        {
            printf("El estudiante ya esta inscripto en la materia\n");
            return false;
        }
    }
    asegurarCapacidadInscripciones(listaDeInscripciones);
    Inscripcion nuevaInscripcion;
    nuevaInscripcion.idEstudiante = idEstudiante;
    nuevaInscripcion.idMateria = idMateria;
    nuevaInscripcion.nota1 = 0;
    nuevaInscripcion.nota2 = 0;
    nuevaInscripcion.promedio = 0;
    strcpy(nuevaInscripcion.estado, "Pendiente");
    listaDeInscripciones->inscripciones[listaDeInscripciones->cantidad++] = nuevaInscripcion;
    return true;
}

bool registrarNotas(ListaInscripciones *listaDeInscripciones, int idMateria, float nota1, float nota2)
{
    for (int i = 0; i < listaDeInscripciones->cantidad; i++)
    {
        if (listaDeInscripciones->inscripciones[i].idMateria == idMateria)
        {
            listaDeInscripciones->inscripciones[i].nota1 = nota1;
            listaDeInscripciones->inscripciones[i].nota2 = nota2;
            listaDeInscripciones->inscripciones[i].promedio = (nota1 + nota2) / 2.0f;

            calcularEstado(&listaDeInscripciones->inscripciones[i]);
            return true;
        }
    }
    printf("Inscripcion no encontrada para la materia con ID %d\n", idMateria);
    return false;
}

void calcularEstado(Inscripcion *inscripcion)
{
    float n1 = inscripcion->nota1;
    float n2 = inscripcion->nota2;

    if (n1 >= 7 && n2 >= 7)
    {
        strcpy(inscripcion->estado, "Promocion");
    }
    else if (inscripcion->promedio >= 4)
    {
        strcpy(inscripcion->estado, "Final");
    }
    else
    {
        strcpy(inscripcion->estado, "Desaprobado");
    }
}