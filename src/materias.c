#include "materias.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CAPACIDAD_INICIAL 5

static void asegurarCapacidad(ListaMaterias *listaMaterias)
{
    if (listaMaterias->cantidad < listaMaterias->capacidad)
        return;
    int nuevaCapacidad = (listaMaterias->capacidad == 0) ? CAPACIDAD_INICIAL : listaMaterias->capacidad * 2;
    Materia *nuevaMemoria = realloc(listaMaterias->materias, nuevaCapacidad * sizeof(Materia));
    if (!nuevaMemoria)
    {
        fprintf(stderr, "Error al asignar memoria\n");
        exit(1);
    }
    listaMaterias->materias = nuevaMemoria;
    listaMaterias->capacidad = nuevaCapacidad;
}

void inicializarListaDeMaterias(ListaMaterias *listaMaterias)
{
    free(listaMaterias->materias);
    listaMaterias->materias = NULL;
    listaMaterias->cantidad = 0;
    listaMaterias->capacidad = 0;
    listaMaterias->next_id = 1;
}

void liberarListaDeMaterias(ListaMaterias *listaMaterias)
{
    free(listaMaterias->materias);
    listaMaterias->materias = NULL;
    listaMaterias->cantidad = 0;
    listaMaterias->capacidad = 0;
}

int altaMateria(ListaMaterias *listaMaterias, const char *nombre, int creditos)
{
    asegurarCapacidad(listaMaterias);
    Materia nuevaMateria;
    nuevaMateria.id = listaMaterias->next_id++;
    snprintf(nuevaMateria.nombre, NOMBRE_MAX, "%s", nombre);
    nuevaMateria.nombre[NOMBRE_MAX - 1] = '\0';
    nuevaMateria.creditos = creditos;

    listaMaterias->materias[listaMaterias->cantidad++] = nuevaMateria;
    return nuevaMateria.id;
}

// Funcion que nos Busca una Materia por su Id, y nos retorna su indice en el arreglo o -1 si no la encuentra
static int buscarMateriaPorId(const ListaMaterias *listaMaterias, int id)
{
    for (int i = 0; i < listaMaterias->cantidad; i++)
    {
        if (listaMaterias->materias[i].id == id)
            return i;
    }
    return -1;
}

bool bajaMateria(ListaMaterias *listaMaterias, int id)
{
    int indiceMateria = buscarMateriaPorId(listaMaterias, id);

    if (indiceMateria == -1)
        return false;

    listaMaterias->materias[indiceMateria] = listaMaterias->materias[listaMaterias->cantidad - 1];
    listaMaterias->cantidad--;
    return true;
}

bool modificarMateria(ListaMaterias *listaMaterias, int id, const char *nuevoNombre, int nuevosCreditos)
{
    int indiceMateria = buscarMateriaPorId(listaMaterias, id);

    if (indiceMateria == -1)
        return false;

    if (nuevoNombre && strlen(nuevoNombre) > 0)
    {
        snprintf(listaMaterias->materias[indiceMateria].nombre, NOMBRE_MAX, "%s", nuevoNombre);
        listaMaterias->materias[indiceMateria].nombre[NOMBRE_MAX - 1] = '\0';
    }

    if (nuevosCreditos > 0)
        listaMaterias->materias[indiceMateria].creditos = nuevosCreditos;

    return true;
}

void listarMaterias(const ListaMaterias *listaMaterias)
{
    printf("\n == Listado de ListaMaterias (%d) ==\n", listaMaterias->cantidad);
    printf("ID\tNombre\t\tCréditos\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < listaMaterias->cantidad; i++)
    {
        printf("%d\t%-16s%d\n", listaMaterias->materias[i].id,
               listaMaterias->materias[i].nombre,
               listaMaterias->materias[i].creditos);
    }
}