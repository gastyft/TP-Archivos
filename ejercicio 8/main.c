#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ESC 27
#define ARCH C:\\Users\\gasty\\OneDrive\\Escritorio\\Programacion y laboratorio 1\\Archivos\\ejercicio 8


/**
8. Dado un archivo de alumnos, hacer una función que cuente la cantidad de alumnos
mayores a edad específica que se envía por parámetro.
*/
typedef struct {
int legajo;
char nombreYapellido [30];
int edad;
int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;



///prototipado
void cant_edad(int num);
void mostrar_archivo(FILE *archivo);
void cargar_archivo(FILE *archivo);



int main()
{
system("COLOR B");
int num=0;
    FILE *bin=NULL;
bin=fopen("ARCH","rb");


if(bin == NULL){
cargar_archivo(bin);
mostrar_archivo(bin);
}
else{
mostrar_archivo(bin);

cant_edad(num); ///En este caso es el mismo archivo
}

fclose(bin);


    return 0;
}

///funciones
void cargar_archivo(FILE *archivo){

stAlumno alumno;
archivo= fopen("ARCH","ab");

do{
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
}while(getche() !=ESC);

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
void cant_edad(int num){
stAlumno alumno;
FILE *archivo;
char nombre[50];
 int cant,cont=0;
 printf("Ingrese edad para buscar mayores \n");
scanf("%d",&num);
printf("Ingrese direccion de archivo \n");
fflush(stdin);
gets(nombre);

    archivo= fopen(nombre, "rb");
    if(archivo != NULL)
    {

        while(!feof(archivo))
        {

            cant=fread(&alumno,sizeof(alumno),1,archivo);

            for(int i=0; i<cant; i++)
            {
                if(alumno.edad >=num){
                    cont+=1;
                }

            }


        }



    }
printf("Los alumnos mayores de edad son: %d",cont);
  fclose(archivo);
}


