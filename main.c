#include <stdio.h>
#include "funciones.h"

int main(int argc, char const *argv[])
{
    int opc1=0, opc2=0;


    printf("<<GESTION DE PRODUCTOS DEL INVENTARIO>>\n");
    do
    {
    printf("Elija una de las siguientes opciones\n");
    printf("1. Ingrese los datos de los productos\n");
    printf("2. Calcular el precio total del inventario\n");
    printf("3. Encontrar el producto más caro y el más barato\n");
    printf("4. Calcular el precio promedio de todos los productos\n");
    printf("5. Buscar un producto\n");
    scanf("%d", &opc1);
    switch (opc1)
    {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;  
    case 4:

        break;
    case 5:

        break;
    
    default:
        break;
    }
    
    printf("Quiere hacer otra operacion 1. Si 2. No: ");
    scanf("%d",&opc2);
    } while (opc2==1);
    


    return 0;
}
