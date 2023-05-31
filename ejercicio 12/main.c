#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include "../Firma/Firma.h"
#define ESC 27
#define ARCH C:\\Users\\gasty\\OneDrive\\Escritorio\\Programacion y laboratorio 1\\Archivos\\ejercicio 12
#define DIM 10

/**
12. Crear una función que reciba como parámetro un arreglo de tipo alumno y lo copie en el
archivo. Asimismo, realice otra función que pase los elementos del archivo a un arreglo de
alumnos, filtrando los estudiantes de un año en particular.
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
void cargar_archivo(FILE *archivo,stAlumno alumno);
void mostrar_archivo(FILE *archivo);
int cursan_anio(FILE *archivo,stAlumno alumnos[DIM]);
void carga_puntos();
int main()
{
    system("COLOR B");
    FILE *bin=NULL;
    stAlumno alumno;
    stAlumno alumnos[DIM];
    int i=0,validos=0;
    bin= fopen("ARCH","rb");
    printf("Abriendo archivo, espere ");
    carga_puntos();
    printf("Ingrese nombre\n");
    gets(alumno.nombreYapellido);
    printf("Ingrese legajo\n");
    scanf("%d",&alumno.legajo);
    printf("Ingrese edad \n");
    scanf("%d",&alumno.edad);
    printf("Ingrese anio \n");
    scanf("%d",&alumno.anio);
    if(bin == NULL)
    {


        cargar_archivo(bin,alumno);

        mostrar_archivo(bin);
        validos= cursan_anio(bin,alumnos);
    }
    else if(bin != NULL)
    {
cargar_archivo(bin,alumno);
        mostrar_archivo(bin);
        validos=cursan_anio(bin,alumnos);
printf("LOS VALIDOS %d",validos);
    }
    while(i<validos){

            printf(" LOS ALUMNOS QUE CURSAN EN ESTE ANIO SON:\n");
            printf("Nombre y Apellido: %s \n",alumnos[i].nombreYapellido);
              /*  printf("Edad: %d \n",alumnos[i].edad);
                printf("Legajo: %d \n",alumnos[i].legajo);
                printf("Anio: %d \n",alumnos[i].anio); */
                printf("-----------------\n");
        i++;

    }
    printf("Cerrando archivo, espere \n");
    carga_puntos();
    fclose(bin);
    firma();
    return 0;
}
///funciones
void cargar_archivo(FILE *archivo,stAlumno alumno)
{
    archivo = fopen("ARCH","ab");


    fwrite(&alumno,sizeof(alumno),1,archivo);

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
int cursan_anio(FILE *archivo,stAlumno alumnos[DIM])
{
    int j=0;
    stAlumno alumno;
    int cant,anio;

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
                if(alumno.anio == anio)
                {
                    alumnos[j]=alumno;
                    j++;
                }

            }
        }


        fclose(archivo);
    }
 return j;

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

            fflush(stdout); // Forzar la impresión inmediata del punto
            usleep(300000); // Retraso de 300 milisegundos (0.3 segundos)
            printf("\b \b"); // Borrar el punto anterior mediante caracteres de escape
        }
    }
    system("cls");
}
