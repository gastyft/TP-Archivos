#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<unistd.h>
#include "../Firma/Firma.h"
#define ESC 27
#define ARCH C:\\Users\\gasty\\OneDrive\\Escritorio\\Programacion y laboratorio 1\\Archivos\\ejercicio 14


/**14. Dado un archivo de alumnos, que tenga al menos 10 registros, hacer una función que
muestre el contenido de un registro, cuyo número (entre 0 y 9) se pase por parámetro.
Controlar no sobrepasar los límites del archivo.

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
void muestra_param(int num,FILE *archivo);
void carga_puntos();

int main()
{
    system("COLOR B");
    FILE *bin=NULL;
    bin= fopen("ARCH","rb");
    int num=0;
    if(bin == NULL)
    {
        printf("Creando archivo, espere ");
        carga_puntos();
        cargar_archivo(bin);
        mostrar_archivo(bin);
        system("cls");
        printf("Ingrese un numero del 0 al 9 \n");
        scanf("%d",&num);
        if(num>9 || num<0){
            printf("INGRESE NUMERO DEL 0 AL 9 \n");
            scanf("%d",&num);
        }
        muestra_param(num,bin);

    }
    else if(bin != NULL)
    {
        printf("Abriendo archivo,espere");
        carga_puntos();
        mostrar_archivo(bin);
        system("cls");
        printf("Ingrese un numero del 0 al 9 \n");
        scanf("%d",&num);
           if(num>9 || num<0){
            printf("INGRESE NUMERO DEL 0 AL 9 \n");
            scanf("%d",&num);
        }
        muestra_param(num,bin);

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

            fflush(stdout); // Forzar la impresión inmediata del punto
            usleep(300000); // Retraso de 300 milisegundos (0.3 segundos)
            printf("\b \b"); // Borrar el punto anterior mediante caracteres de escape
        }
    }
    system("cls");
}
void muestra_param(int num,FILE *archivo)
{
    int bytes=0,cant=1;
    archivo=fopen("ARCH","rb");
    stAlumno alumno;

 fseek(archivo,0,SEEK_SET);

       while(cant-1 != num){
        fseek(archivo,sizeof(stAlumno),SEEK_CUR);
           bytes = ftell(archivo);
    cant=bytes/sizeof(stAlumno);

    }


    if(cant-1 == num){
        fseek(archivo,(-1)*sizeof(stAlumno),SEEK_CUR);
            fread(&alumno,sizeof(stAlumno),1,archivo);
        printf("Nombre: %s \n",alumno.nombreYapellido);
        printf("Edad: %d \n",alumno.edad);
        printf("Legajo: %d \n",alumno.legajo);
        printf("Anio: %d \n",alumno.anio);
    }
    else if(cant-1 != num){
        printf("ERROR \n");
    }


fclose(archivo);
}

