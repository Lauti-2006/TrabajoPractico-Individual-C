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
El progrma cuenta con dos moodos de usos:
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
* Inscrbir Estudiante en Materias.
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

Nota: Al querer recompilar el código es recomendable eliminar el archvio "programa.exe." para evitar cualquier tipo de error.

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
* Y Mostrar Todo los datos.

## Descripcion General de cómo funcionan el sistema de calificacion de notas

Si la Nota 1 (Primer Parcial) y la Nota 2 (Segundo Parcial) es mayor o igual a 7, la materia esta Promocionada. En cambio, si en ambas notas son mayor igual a 4, pero menores a 7, entonces se rinde final completo de la materia. En cualquier otro caso, la materia esta desaprobada.

