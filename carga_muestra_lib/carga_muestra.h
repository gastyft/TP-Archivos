#ifndef CARGA_MUESTRA_H_INCLUDED
#define CARGA_MUESTRA_H_INCLUDED
#define DIM 10
///struct
typedef struct {
int legajo;
char nombreYapellido [30];
int edad;
int anio;
//a�o que cursa, recordar que no podemos utilizar la � para definir variables
} stAlumno;

///prototipado
stAlumno cargar_1_alumno();
int cargar_alumnos(stAlumno alumno[DIM]);
void mostrar_alumnos(stAlumno alumnos[DIM],int validos);


#endif // CARGA_MUESTRA_H_INCLUDED
