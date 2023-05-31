#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include "../Firma/Firma.h"
#define ESC 27
#define ARCH C:\\Users\\gasty\\OneDrive\\Escritorio\\Programacion y laboratorio 1\\Archivos\\ejercicio 11


/**11. Crear una función que retorne la cantidad de alumnos que cursan un determinado año. El
año buscado se pasa por parámetro
*/
typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;

///prototipado
void cargar_archivo(FILE *archivo);
void mostrar_archivo(FILE *archivo);
void cursan_anio(FILE *archivo);
void carga_puntos();
int main()
{
    system("COLOR B");
   FILE *bin=NULL;
   bin= fopen("ARCH","rb");
   printf("Abriendo archivo, espere ");
   carga_puntos();
   if(bin == NULL){
cargar_archivo(bin);
mostrar_archivo(bin);
cursan_anio(bin);
   }
   else if(bin != NULL){

mostrar_archivo(bin);
cursan_anio(bin);

   }
   printf("Cerrando archivo, espere \n");
   carga_puntos();
   fclose(bin);
   firma();
    return 0;
}
///funciones
void cargar_archivo(FILE *archivo){
archivo = fopen("ARCH","ab");
 stAlumno alumno;
    do
    {

        printf("\nIngrese nombre y apellido \n");
        fflush(stdin);
        gets(alumno.nombreYapellido);
        printf("Ingrese edad\n");
        scanf("%d",&alumno.edad);
        printf("Ingrese legajo\n");
        scanf("%d",&alumno.legajo);
        printf("Ingrese año\n");
        scanf("%d",&alumno.anio);
        fwrite(&alumno,sizeof(alumno),1,archivo);

        printf("Presione ESCAPE para finalizar o cualquier tecla para continuar \n");
    }
    while(getche() !=ESC);

fclose(archivo);
}
void mostrar_archivo(FILE *archivo)
{

    stAlumno alumno;
    int cant;
    archivo= fopen("ARCH", "rb");
    if(archivo != NULL)
    {

        while(!feof(archivo))
        {

            cant=fread(&alumno,sizeof(alumno),1,archivo);

            for(int i=0; i<cant; i++)
            {

                printf("Nombre y Apellido: %s \n",alumno.nombreYapellido);
                printf("Edad: %d \n",alumno.edad);
                printf("Legajo: %d \n",alumno.legajo);
                printf("Anio: %d \n",alumno.anio);
                printf("-----------------\n");
            }
        }


        fclose(archivo);
    }
}
void cursan_anio(FILE *archivo)
{

    stAlumno alumno;
    int cant,anio,cont=0;

    archivo= fopen("ARCH", "rb");

    printf("Ingrese anio\n");
    scanf("%d",&anio);
    if(archivo != NULL)
    {

        while(!feof(archivo))
        {

            cant=fread(&alumno,sizeof(alumno),1,archivo);

            for(int i=0; i<cant; i++)
            {
if(alumno.anio == anio){
    printf("Alumno %s cursa en anio: %d \n",alumno.nombreYapellido,anio);
    cont+=1;
}
            }
        }


        fclose(archivo);
    }
    if(cont==0){
        printf("No hay alumnos que cursen en ese anio \n");
    }

}



void carga_puntos(){

int i,j;
int num_puntos = 2;
    for (i = 0; i < 8; i++) {
        // Imprimir los puntos con movimiento

        for (j = 0; j < num_puntos; j++) {

            printf("..");

            fflush(stdout); // Forzar la impresión inmediata del punto
            usleep(300000); // Retraso de 300 milisegundos (0.3 segundos)
            printf("\b \b"); // Borrar el punto anterior mediante caracteres de escape
        }
    }
system("cls");
}
