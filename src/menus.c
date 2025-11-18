#include <stdio.h>
#include "menus.h"
#include "persistencia.h"

void mostrarMenuPrincipal()
{
    // Bucle del Menu Principal
    char opcionMenuPrincipal;
    do
    {
        printf("\n== Sistema Academico ==\n");
        printf("Menu Principal:\n");
        printf("A) Usar el Programa con los CSV Pre-cargados\n");
        printf("B) Cargar Datos Manualmente, Visualizarlos y Exportarlos \n");
        printf("X) Salir\n");
        printf("Seleccione una opcion: ");
        scanf(" %c", &opcionMenuPrincipal);

        if (opcionMenuPrincipal == 'A' || opcionMenuPrincipal == 'a')
        {
            menuCSV();
        }
        else if (opcionMenuPrincipal == 'B' || opcionMenuPrincipal == 'b')
        {
            menuCargaManual();
        }
    } while (opcionMenuPrincipal != 'X' && opcionMenuPrincipal != 'x');
}

// Opcion A: Precargar CSV
void menuCSV()
{
    printf("Cargando Datos de CSV.....\n");
    Estudiante estudiante;
    ListaMaterias listaMaterias;
    ListaInscripciones listaInscripciones;

    estudiante = leerEstudianteCSV("../data/estudiante.csv");
    leerMateriasCSV("../data/materias.csv", &listaMaterias);
    leerInscripcionesCSV("../data/inscripciones.csv", &listaInscripciones);

    printf("Datos Cargados Exitosamente!\n");

    // SubMenu para Mostrar los Datos Cargados
    int opcionSubMenu = -1;
    while (opcionSubMenu != 0)
    {
        printf("\n-- SubMenu de Datos Cargados --\n");
        printf("1. Mostrar Estudiante\n");
        printf("2. Listar Materias\n");
        printf("3. Listar Inscripciones\n");
        printf("0. Volver al Menu Principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcionSubMenu);

        switch (opcionSubMenu)
        {
        case 1:
            mostrarEstudiante(&estudiante);
            break;
        case 2:
            listarMaterias(&listaMaterias);
            break;
        case 3:
            listarInscripciones(&listaInscripciones, &listaMaterias);
            break;
        case 0:
            printf("Volviendo al Menu Principal...\n");
            break;
        default:
            printf("Opcion invalida. Por favor intente de nuevo.\n");
            break;
        }
    }
}

// Opcion B: Cargar Datos Manualmente
void menuCargaManual()
{
    Estudiante estudiante;
    ListaMaterias listaMaterias;
    ListaInscripciones listaInscripciones;
    inicializarListaDeMaterias(&listaMaterias);
    inicializarListaInscripciones(&listaInscripciones);

    // SubMenu para la Carga Manual de Datos
    int subMenuDeFormaManual = -1;

    while (subMenuDeFormaManual != 0)
    {
        printf("\n-- SubMenu de Carga Manual --\n");
        printf("1. Agregar Estudiante\n");
        printf("2. Agregar Materia\n");
        printf("3. Inscribir Estudiante en Materia\n");
        printf("4. Registrar Notas\n");
        printf("5. Mostrar Todo\n");
        printf("6. Exportar a CSV\n");
        printf("0. Volver al Menu Principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &subMenuDeFormaManual);
        getchar();

        switch (subMenuDeFormaManual)
        {
        // Agregar Estudiante
        case 1:
            printf("Ingrese el Nombre del Estudiante: ");
            fgets(estudiante.nombre, NOMBRE_MAX, stdin);
            estudiante.nombre[strcspn(estudiante.nombre, "\n")] = '\0';
            printf("Ingrese Edad del Estudiante");
            scanf("%d", &estudiante.edad);
            getchar();
            estudiante.id = 1;
            printf("Estudiante Agregado Correctamente");
            break;

        // Agregar Materia
        case 2:
        {
            int creditos;
            char nombreDeLaMateria[NOMBRE_MAX];
            printf("Ingrese el Nombre de la Materia");
            fgets(nombreDeLaMateria, NOMBRE_MAX, stdin);
            nombreDeLaMateria[strcspn(nombreDeLaMateria, "\n")] = '\0';
            printf("Ingrese Creditos");
            scanf("%d", &creditos);
            getchar();
            int idNuevaMateria = altaMateria(&listaMaterias, nombreDeLaMateria, creditos);

            if (idNuevaMateria == -1)
            {
                perror("Error al Agregar la Materia");
            }
            else
            {
                printf("Materia agregada con el ID: %d\n", idNuevaMateria);
            }
            break;
        }
        }
    }
}