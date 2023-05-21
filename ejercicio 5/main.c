#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define ESC 27
#define ARCH C:\\Users\\gasty\\OneDrive\\Escritorio\\Programacion y laboratorio 1\\Archivos\\ejercicio 5

/**
5. Crear una función que muestre por pantalla los registros de un archivo de alumnos.
Modularizar.
*/

typedef struct {
int legajo;
char nombreYapellido [30];
int edad;
int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;


///prototipado

void cargar_archivo(FILE *archivo);
void mostrar_archivo(FILE *archivo);


int main()
{
    system ("COLOR B");
    FILE *bin=NULL;




///carga archivo
bin =fopen("ARCH","rb");
if(bin == NULL){
cargar_archivo(bin);
  mostrar_archivo(bin);
}
else if(bin != NULL)
{
    mostrar_archivo(bin);
}
fclose(bin);
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

void mostrar_archivo(FILE *archivo){ ///Muestra datos y devuelve cantidad de datos
int cant;
stAlumno alumno;
archivo = fopen("ARCH", "r+b");
if ( archivo != NULL) {
while ( !feof (archivo)) {

cant= fread ( &alumno, sizeof (alumno), 1, archivo);

for(int i=0;i<cant;i++){
printf("Nombre y Apellido: %s \n",alumno.nombreYapellido);
printf("Legajo: %d \n",alumno.legajo);
printf("Edad: %d \n",alumno.edad);
printf("Anio: %d \n",alumno.anio);
printf("----------------------- \n");
}
}




fclose (archivo);

/// para realizar instrucciones si se debe    getch();
}
else{
printf("ERROR de datos");
}

}
