#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../carga_muestra_lib/carga_muestra.h"
#define ESC 27
#define ARCH C:\\Users\\gasty\\OneDrive\\Escritorio\\Programacion y laboratorio 1\\Archivos\\ejercicio 4\\ejercicio4.bin

/**
4. Crear una función que cargue un archivo de alumnos. Abrirlo de manera tal de verificar si el
archivo ya está creado previamente. Cargar el archivo con 5 datos. Cerrarlo dentro de la
función
*/



///prototipado

void cargar_archivo(FILE *archivo);



int main()
{
    system ("COLOR B");
    FILE *bin=NULL;


///carga de alumnos

///carga archivo
bin =fopen("ARCH","rb");
if(bin == NULL){
cargar_archivo(bin);

}
else if(bin != NULL)
{
    printf("Ya existe el archivo y contiene datos \n");
}

    return 0;
}
void cargar_archivo(FILE *archivo){


stAlumno alumno1;
    archivo = fopen("ARCH", "a+b" );
if ( archivo != NULL) {
do {

printf("Ingrese nombre y apellido \n");
fflush(stdin);
gets(alumno1.nombreYapellido);
printf("Ingrese legajo \n");
scanf("%d",&alumno1.legajo);
printf("Ingrese edad \n");
scanf("%d",&alumno1.edad);
printf("Ingrese anio \n");
scanf("%d",&alumno1.anio);
fwrite (&alumno1, sizeof (alumno1), 1, archivo);

printf ( "Presione ESC para terminar \n" );
} while ((getche () ) != ESC );
}
else{
printf("ERROR de datos");
}
fclose (archivo);

}



