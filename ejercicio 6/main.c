#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <conio.h>
#define ESC 27
#define ARCH

/**6. Crear una función que permita agregar de a un elemento al final del archivo. O sea, se debe
abrir el archivo, se piden los datos (se llena una variable de tipo struct alumno), se escribe
en el archivo y se cierra.
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
void cargar_nuevo_elemento(FILE *archivo);

int main()
{

    system ("COLOR B");
    FILE *bin= NULL;
    bin= fopen("ARCH","rb");
    if(bin == NULL)
    {
        printf("Creando nuevo archivo\n");
        cargar_archivo(bin);
        mostrar_archivo(bin);

    }
    else if(bin != NULL)
    {

        printf("Existe el archivo, agregara datos al archivo \n");
        cargar_nuevo_elemento(bin);
        mostrar_archivo(bin);

    }
fclose(bin);
    return 0;
}

void cargar_archivo(FILE *archivo)
{

    archivo =fopen("ARCH","ab");
    stAlumno alumno;

    do
    {
        printf("Ingrese nombre y apellido \n");
        fflush(stdin);
        gets(alumno.nombreYapellido);
        printf("Ingrese edad\n");
        scanf("%d",&alumno.edad);
        printf("Ingrese legajo\n");
        scanf("%d",&alumno.legajo);
        printf("Ingrese año\n");
        scanf("%d",&alumno.anio);
        fwrite(&alumno,sizeof(alumno),1,archivo);
        printf ( "Presione ESC para terminar o any key to continue \n" );
    }
    while(getche() != ESC);
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
                printf("Año: %d \n",alumno.anio);
                printf("-----------------\n");
            }
        }


        fclose(archivo);
    }
}

void cargar_nuevo_elemento(FILE *archivo)
{
    stAlumno alumno;
    archivo =fopen("ARCH","a+b");
    if(archivo!= NULL)
    {
        printf("Ingrese nombre y apellido \n");
        fflush(stdin);
        gets(alumno.nombreYapellido);
        printf("Ingrese edad\n");
        scanf("%d",&alumno.edad);
        printf("Ingrese legajo\n");
        scanf("%d",&alumno.legajo);
        printf("Ingrese año\n");
        scanf("%d",&alumno.anio);

        fwrite(&alumno,sizeof(alumno),1,archivo);
    }
    else
    {
        printf("Error al abrir el archivo \n");
    }
    fclose(archivo);
}



