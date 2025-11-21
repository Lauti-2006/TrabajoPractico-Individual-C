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
        printf("A) Usar el Programa con los CSV ya Alamacenados\n");
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

// Opcion A: Usar el Programa con los CSV ya Almacenados
void menuCSV()
{
    printf("Cargando Datos de CSV.....\n");
    Estudiante estudiante;
    ListaMaterias listaMaterias;
    ListaInscripciones listaInscripciones;

    int opcionCSV = -1;
    printf("\n -- SubMenu Carga de CSV Almacenados --\n");
    printf("1. CSV Precargado por el Alumno\n");
    printf("2. CSV Exportado luego de Carga Manual\n");
    printf("Elija una Opcion: ");
    scanf("%d", &opcionCSV);
    if (opcionCSV == 1)
    {
        estudiante = leerEstudianteCSV("../data/datosPrecargados/estudiante.csv");
        leerMateriasCSV("../data/datosPrecargados/materias.csv", &listaMaterias);
        leerInscripcionesCSV("../data/datosPrecargados/inscripciones.csv", &listaInscripciones);
        printf("Datos Cargados Exitosamente!\n");
    }
    else if (opcionCSV == 2)
    {
        estudiante = leerEstudianteCSV("../data/datosExportados/estudiante.csv");
        leerMateriasCSV("../data/datosExportados/materias.csv", &listaMaterias);
        leerInscripcionesCSV("../data/datosExportados/inscripciones.csv", &listaInscripciones);
        printf("Datos Cargados Exitosamente!\n");
    }
    else
    {
        printf("La Opcion es Invalida, Volviendo al Menu Principal...\n");
        return;
    }

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

// Funcion Auxiliar, para verificar que exista el estudiante y al menos una materia
static bool verificarListaDeMateriasyAlumno(int idAlumno, ListaMaterias *listaMaterias)
{
    if (idAlumno == 0)
    {
        printf("Error, primero debe agregar un Estudiante\n");
        return false;
    }

    if (listaMaterias->cantidad == 0)
    {
        printf("Error, no hay Materias Agregadas\n");
        return false;
    }
    return true;
}
void menuCargaManual()
{
    Estudiante estudiante;
    ListaMaterias listaMaterias;
    ListaInscripciones listaInscripciones;
    inicializarListaDeMaterias(&listaMaterias);
    inicializarListaInscripciones(&listaInscripciones);
    estudiante.id = 0;

    // SubMenu para la Carga Manual de Datos
    int subMenuDeFormaManual = -1;

    while (subMenuDeFormaManual != 0)
    {
        printf("\n\n-- SubMenu de Carga Manual --\n");
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
            printf("Ingrese Edad del Estudiante: ");
            scanf("%d", &estudiante.edad);
            while (estudiante.edad < 0 || estudiante.edad < 17)
            {
                printf("La Edad Ingresada No es Valida (debe ser positiva y mayor a 17)\n");
                printf("Ingrese Edad del Estudiante: ");
                scanf("%d", &estudiante.edad);
            }
            getchar();
            break;

        // Agregar Materia
        case 2:
        {
            asegurarCapacidadMaterias(&listaMaterias);
            int creditos;
            char nombreDeLaMateria[NOMBRE_MAX];
            printf("Ingrese el Nombre de la Materia: ");
            fgets(nombreDeLaMateria, NOMBRE_MAX, stdin);
            nombreDeLaMateria[strcspn(nombreDeLaMateria, "\n")] = '\0';
            printf("Ingrese Creditos: ");
            scanf("%d", &creditos);
            getchar();

            int idNuevaMateria = altaMateria(&listaMaterias, nombreDeLaMateria, creditos);

            idNuevaMateria = altaMateria(&listaMaterias, nombreDeLaMateria, creditos);

            if (idNuevaMateria == -1)
            {
                perror("Error al Agregar la Materia\n");
            }
            else
            {
                printf("Materia agregada con el ID: %d\n", idNuevaMateria);
            }
            break;
        }

        case 3:
        {
            if (verificarListaDeMateriasyAlumno(estudiante.id, &listaMaterias) == true)
            {
                int idMateriaSeleccionada;
                do
                {
                    printf("Lista de Materias:");
                    listarMaterias(&listaMaterias);
                    printf("Seleccione el ID de la Materia: ");
                    scanf("%d", &idMateriaSeleccionada);
                    if (idMateriaSeleccionada == 0)
                    {
                        printf("Volviendo al Anterior Menu...\n");
                        break;
                    }

                    if (!existeMateria(&listaMaterias, idMateriaSeleccionada))
                    {
                        printf("Ese ID Materia No Exite, Intente Nuevamente\n");
                    }

                } while (!existeMateria(&listaMaterias, idMateriaSeleccionada));

                if (idMateriaSeleccionada != 0)
                {
                    asegurarCapacidadInscripciones(&listaInscripciones);
                    inscribirEnMateria(&listaInscripciones, estudiante.id, idMateriaSeleccionada);
                    printf("El Alumno fue Inscripto a la Materia Correctamente\n");
                }
            }
            break;
        }

        case 4:
        {
            if (verificarListaDeMateriasyAlumno(estudiante.id, &listaMaterias) == true)
            {
                int idMateriaSeleccionada = -1;
                float nota1, nota2;
                do
                {
                    printf("Lista de Materias:");
                    listarMaterias(&listaMaterias);
                    printf("Seleccione el ID de la Materia (0 para volver): ");
                    scanf("%d", &idMateriaSeleccionada);
                    if (idMateriaSeleccionada == 0)
                    {
                        printf("Volviendo al Anterior Menu...\n");
                        break;
                    }
                    if (!existeMateria(&listaMaterias, idMateriaSeleccionada))
                    {
                        printf("Ese ID Materia No Exite, Intente Nuevamente\n");
                        continue;
                    }
                    if (!verificarSiElAlumnoEstaInscriptoEnUnaMateria(&listaInscripciones, estudiante.id, idMateriaSeleccionada))
                    {
                        printf("El Estudiante No esta Inscripto en esa Materia, por lo que no se puede Registrar las Notas\n");
                        printf("Intentelo Nuevamente\n");
                    }
                } while (!verificarSiElAlumnoEstaInscriptoEnUnaMateria(&listaInscripciones, estudiante.id, idMateriaSeleccionada) || !existeMateria(&listaMaterias, idMateriaSeleccionada));
                if (idMateriaSeleccionada == 0)
                    break;

                // Si llegamos a este punto, y esta inscripto, entonces pedimos la Nota 1 y la Nota 2

                printf("Ingrese la Nota 1: ");
                scanf("%f", &nota1);
                while (nota1 < 1 || nota1 > 10)
                {
                    printf("Nota Incorrecta, la Nota debe estar entre 1 y 10, vuelva a intentarlo: ");
                    getchar;
                    scanf("%f", &nota1);
                }
                printf("Ingrese la Nota 2: ");
                scanf("%f", &nota2);
                while (nota2 < 1 || nota2 > 10)
                {
                    printf("Nota Incorrecta, la Nota debe estar entre 1 y 10, vuelva a intentarlo: ");
                    scanf("%f", &nota2);
                }
                registrarNotas(&listaInscripciones, idMateriaSeleccionada, nota1, nota2);
                printf("Se Registraron las Notas Correctamente\n");
            }
            break;
        }
        case 5:
            if (verificarListaDeMateriasyAlumno(estudiante.id, &listaMaterias) == true)
            {
                mostrarEstudiante(&estudiante);
                listarMaterias(&listaMaterias);
                listarInscripciones(&listaInscripciones, &listaMaterias);
            }
            else
            {
                printf("Debe Ingresar Informacion Primero\n");
                break;
            }
            break;
        case 6:
            guardarEstudianteCSV("../data/datosExportados/estudiante.csv", &estudiante);
            guardarMateriasCSV("../data/datosExportados/materias.csv", &listaMaterias);
            guardarInscripcionesCSV("../data/datosExportados/inscripciones.csv", &listaInscripciones);
            printf("Datos Exportados Correctamente\n");
            break;

        default:
            printf("Opcion Invalida, Intentelo Nuevamente\n");
            break;
        }
    }
}
