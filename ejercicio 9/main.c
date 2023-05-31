#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ESC 27
#define ARCH C:\\Users\\gasty\\OneDrive\\Escritorio\\Programacion y laboratorio 1\\Archivos\\ejercicio 10


/**
9. Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre un
rango de edades específico (por ejemplo, entre 17 y 25 años). Dicho rango debe recibirse
por parámetro. Modularizar
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
void cant_edad(int num1,int num2);

int main()
{
    int num1=0,num2=0;
    system("COLOR B");
    FILE *bin=NULL;
    bin=fopen("ARCH","rb");

    if(bin== NULL)
    {
        cargar_archivo(bin);
        mostrar_archivo(bin);

    }
    else if(bin != NULL)
    {
        mostrar_archivo(bin);
        cant_edad(num1,num2);
    }

    fclose(bin);
    return 0;
}

///funciones


void cargar_archivo(FILE *archivo)
{
    archivo=fopen("ARCH","ab");
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
void cant_edad(int num1,int num2)
{
    stAlumno alumno;
    FILE *archivo;

    char nombre[50];
    int cant;
    printf("Ingrese edad menor \n");
    scanf("%d",&num1);
    printf("Ingrese edad mayor \n");
    fflush(stdin);
    scanf("%d",&num2);
    printf("Ingrese direccion de archivo \n");
    fflush(stdin);
    gets(nombre);
    archivo= fopen(nombre, "rb");

    if(archivo != NULL)
    {

        while(!feof(archivo))
        {

            cant=fread(&alumno,sizeof(alumno),1,archivo);
for(int i=0;i<cant;i++){
 if(alumno.edad >= num1 && alumno.edad < num2 )
                {
                    printf("Nombre del alumno: %s \n",alumno.nombreYapellido);

                }

}
        }






    }

fclose(archivo);
}
