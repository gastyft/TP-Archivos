#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <string.h>
#include "../Firma/Firma.h"
#define ESC 27
#define ARCH C:\\Users\\gasty\\OneDrive\\Escritorio\\Programacion y laboratorio 1\\Archivos\\ejercicio 15


/** 15. Realice una (o varias) funciones que permitan modificar un registro existente en el archivo
de alumnos. La misma debe permitir modificar uno o todos los campos de la estructura y
sobreescribir el registro existente en el archivo.

*/
typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
//a�o que cursa, recordar que no podemos utilizar la � para definir variables
} stAlumno;

///prototipado
void cargar_archivo(FILE *archivo);
void mostrar_archivo(FILE *archivo);
void cant_datos(FILE *archivo);
void carga_puntos();
void modificar(FILE *archivo);

int main()
{
    system("COLOR B");
    FILE *bin=NULL;
    bin= fopen("ARCH","rb");

    if(bin == NULL)
    {
        printf("Creando archivo, espere ");
        carga_puntos();
        cargar_archivo(bin);
        mostrar_archivo(bin);
        system("pause");
        system("cls");
        modificar(bin);
        mostrar_archivo(bin);
    }
    else if(bin != NULL)
    {
        printf("Abriendo archivo,espere");
        carga_puntos();
        mostrar_archivo(bin);
        modificar(bin);
        mostrar_archivo(bin);
    }
    // printf("Cerrando archivo, espere \n");
    // carga_puntos();
    fclose(bin);
    firma();
    return 0;
}
///funciones
void cargar_archivo(FILE *archivo)
{
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
        printf("Ingrese anio\n");
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


void carga_puntos()
{

    int i,j;
    int num_puntos = 2;
    for (i = 0; i < 8; i++)
    {
        // Imprimir los puntos con movimiento

        for (j = 0; j < num_puntos; j++)
        {

            printf("..");

            fflush(stdout); // Forzar la impresi�n inmediata del punto
            usleep(300000); // Retraso de 300 milisegundos (0.3 segundos)
            printf("\b \b"); // Borrar el punto anterior mediante caracteres de escape
        }
    }
    system("cls");
}

void cant_datos(FILE *archivo)
{

    archivo= fopen("ARCH","rb");

    int cant=0;
    int bytes=0;


    fseek(archivo,0,SEEK_END);
    bytes = ftell(archivo);
    cant=bytes/sizeof(stAlumno);
    printf("La cantidad de elementos es %d \n",cant);
    fclose(archivo);
}

void modificar(FILE *archivo)
{

    archivo=fopen("ARCH","r+b");
    stAlumno alumno;
    char aux[30];
    printf("Ingrese  nombre a modificar \n");
    fflush(stdin);
    gets(aux);
  ///  fseek(archivo,0,SEEK_SET);

 while ( fread (&alumno, sizeof (stAlumno), 1 , archivo) > 0) {
     if(strcmp(alumno.nombreYapellido,aux) == 0){

    printf("Nombre  \n");
    fflush(stdin);
    gets(alumno.nombreYapellido);
    printf("Edad \n");
    scanf("%d",&alumno.edad);
    printf("Legajo  \n");
    scanf("%d",&alumno.legajo);
    printf("Anio \n");
    scanf("%d",&alumno.anio);
    fseek(archivo,(-1)*sizeof(stAlumno),SEEK_CUR);

    fwrite(&alumno,sizeof(stAlumno),1,archivo);
    break;
     }

 }


    fclose(archivo);
}
