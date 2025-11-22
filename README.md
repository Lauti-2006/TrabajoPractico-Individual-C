# Sistema Académico Personal

## Descripcion del Proyecto
Este sistema amplia el trabajo original de “Estudiantes” transformándolo en una aplicación de gestión académica personal. Permite trabajar con estructuras de datos, relaciones entre entidades (Estudiante-Materia), persistencia en archivos CSV para reportes y estadísticas aplicando los fundamentos del TP general, pero con mayor alcance funcional.

Este Proyecto implementa un "Sistema Académico Personal" desarrollado en lenguaje c, que permite: 
* Gestionar un unico estudiante. 
* Administrar materias (alta, modificacion y listado).
* Inscribir al estudiante en materias.
* Registrar notas y determinar estados (promoción, final, deasaprobado).
* Guardar y leer datos para archivos CSV para persistencia.

### Modo de uso
El programa cuenta con dos modos de usos:
- Opción A: Cargar datos desde CSV existente.
- Opción B: Cargar datos manualmente y exportar a CSV.

## Estructura del Proyecto
![Árbol de Carpetas y Archivos](img/Captura-Estructura-Proyecto.png)

## Funcionalidades Principales

### Estudiante
* Alta.
* Mostrar Datos.

### Materias
* Alta.
* Listado. 
* Validaciones. 

### Inscripciones 
* Inscribir Estudiante en Materias.
* Registrar Notas. 
* Calcular Estados: Promociona, Final, Desaprobado.

### Persistencia
* Leer Estudiantes, Materias e Inscripciones desde CSV. 
* Exportar todos los datos a Archivos CSV.

## Intrucciones para la Ejecucion 

Dentro de la carpeta 'src' compilar todos los archivos.c con el siguiente comando: 
```
gcc *.c -o programa.exe
```

Y ejecutar: 
```
.\programa.exe
```

Nota: Al querer recompilar el código es recomendable eliminar el archivo "programa.exe." para evitar cualquier tipo de error.

## Lógica de Ejecución
**Opcion A: Usar Programa con CSV Almacenado**
Permite elegir si cargar: 
* Los archivos CSV precargados por el alumno, o 
* Los archivos CSV exportados por el usuario 

**Opcion B: Cargar Datos Manualmente, Visualizarlos y Exportarlos**
Permite agregar los sigientes datos:
* El nombre y la edad del Estudiante.
* La materia.
* Inscribir Estudiante en Materia.
* Registar Notas.
* Y Mostrar Todos los datos.

## Reglas de Negocio
* Se almacena un unico estudiante.
* El estudiante puede inscribirse a un numero no limitado de materias.
* Si ambas Notas (Primer Parcial y Segundo Parcial) son mayores o iguales a 7, el estudiante *Promociona*.
* Si el promedio es mayor o igual a 4, pero no promociona, debe rendir *Final*.
* Si el promedio es menor a 4, la materia queda *Desaprobada*.

## Validaciones 
* Estudiante: Se verifica que la edad ingresada sea positiva y mayor o igual 17.
* Inscripcion: 
1. Se verfica que la materia en la que se desea inscribir exista. 
2. Al registrar las notas, que esten en el rango 1~10.
3. Al intentar registrar una nota, se verifica que el alumno este inscripto en la materia.


