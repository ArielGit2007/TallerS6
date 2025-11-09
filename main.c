#include <stdio.h>
#include "funciones.h"

void main(int argc, char const *argv[])
{
    int opc1=0, opc2=0, cont=0;
    char Nombre[10][50]={""}, c[1][100];
    float Precio [10]={0}, Total=0;

    printf("<<GESTION DE PRODUCTOS DEL INVENTARIO>>\n");
    do
    {
    printf("Elija una de las siguientes opciones\n");
    printf("1. Ingrese los datos de los productos\n");
    printf("2. Calcular el precio total del inventario\n");
    printf("3. Encontrar el producto mas caro y el mas barato\n");
    printf("4. Calcular el precio promedio de todos los productos\n");
    printf("5. Buscar un producto\n");
    if (scanf("%d", &opc1)==1){ // Si ingresas algo que no sea un número no te lo válida y termina el switch sin pasar por las opcciones
    switch (opc1)
    {
    case 1:   
        cont=IngresoDatos(Nombre[cont], Precio,cont); // Ingresas los datos y te devuelve el contador para avanzar a la siguiente posicion del arreglo
        break;
    case 2:
        Total=PrecioTotal(Precio, cont);//Te regresa el precio el precio total del inventario
        printf("El precio total del inventario es de:  %.2f\n", Total);
        break;
    case 3:
        MasCaroBarato(Precio, Nombre,cont);//Regresa el prodcuto mas caro y el mas barato de los exitentes
        break;  
    case 4:
        PrecioPromedio(Precio, cont);//Regresa el precio promedio de los productos en su conjunto
        break;
    case 5:
        Buscarnombre(Nombre,Precio, cont);//Ingresas un nombre y lo busca en lao datos que se tienen
        break;
    default:
        break;
    }
    }
    else{
        printf("No es una opcion valida\n");
        fgets(c[0], sizeof(c), stdin); //Limpia el buffer
    }
  opc2=validarOpc();//Obtiene la opc de seguir con el programa o no

    } while (opc2==1);
    
}
