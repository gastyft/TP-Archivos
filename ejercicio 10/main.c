#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ESC 27
#define ARCH C:\\Users\\gasty\\OneDrive\\Escritorio\\Programacion y laboratorio 1\\Archivos\\ejercicio 10


/**
10. Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar
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
void mayor_alumno(FILE *archivo);

int main()
{
    system("COLOR B");
   FILE *bin=NULL;
   bin= fopen("ARCH","rb");
   if(bin == NULL){
cargar_archivo(bin);
mostrar_archivo(bin);
   }
   else if(bin != NULL){

mostrar_archivo(bin);
mayor_alumno(bin);

   }
   fclose(bin);
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

void mayor_alumno(FILE *archivo){

    stAlumno alumno,mayor;
    int cant;
    archivo= fopen("ARCH", "rb");
    if(archivo != NULL)
    {
        fread(&mayor,sizeof(mayor),1,archivo);


        while(!feof(archivo))
        {

            cant=fread(&alumno,sizeof(alumno),1,archivo);

            for(int i=0; i<cant; i++)
            {
                if(alumno.edad > mayor.edad){
                    mayor=alumno;
                }
            }
        }
printf("El alumno mayor es: %s \n",mayor.nombreYapellido);

        fclose(archivo);
    }


}







