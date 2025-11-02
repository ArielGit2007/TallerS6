#include <stdio.h>
#include <string.h>

void BorrarSaltolinea ( char a[]);
float IngresoDatos (char a[], float b[] , int cont);
float PrecioTotal(float Precio[], int cont);
void MasCaroBarato(float Precio[],char producto[][50], int cont);
void PrecioPromedio(float Precio[], int cont);
void Buscarnombre(char Producto[][50], float Precio[], int cont);


float IngresoDatos (char a[], float b[], int cont ){
    if (cont<10){
    char c[1][50];
    
    fgets(c[0], sizeof(c), stdin);
    printf("Nombre del producto: ");
    fgets(a, 50, stdin);
    BorrarSaltolinea(a);
    printf("Precio del producto: ");
    scanf("%f",&b[cont]);
    fgets(c[0], sizeof(c), stdin);
    cont++;
    return cont;
    }
    else{
        printf("Cantidad Maxima de productos alcanzada\n");
        return cont;
    }
    
}

float PrecioTotal(float Precio[], int cont){
    float Total=0;
    for ( int i = 0; i < cont; i++)
    {
        Total+=Precio[i];
    }
    return Total;
}

void MasCaroBarato(float Precio[],char producto[][50], int cont){
    int indice1=0, indice2=0;
    float MasCaro=0, MasBarato=1000;
    for (int i = 0; i < cont; i++)
    {
        if (Precio[i]>MasCaro)
        {
            MasCaro=Precio[i];
            indice1=i;
        }
        if (Precio[i]<MasBarato)
        {
            MasBarato=Precio[i];
            indice2=i;
        }
        
    }
    printf("El producto mas caro del inventario es %s de precio: %.02f\n", producto[indice1], Precio[indice1]);
    printf("El producto mas barato del inventario es %s de precio: %0.2f\n", producto[indice2], Precio[indice2]);
}

void PrecioPromedio(float Precio[], int cont){
    float Sumatoria=0, promedio=0;    
    Sumatoria=PrecioTotal(Precio, cont);
    promedio=Sumatoria/(cont);

    printf("El precio promedio de todos los productos es de: %.02f\n",promedio);
}

void Buscarnombre(char Producto[][50], float Precio[], int cont){
    char BuscarProducto[1][50]={0};
    int Encontrado=-1;
    char c[1][50];

    fgets(c[0], sizeof(c), stdin);
    printf("Ingrese el nombre del producto que desea buscar (tenga cuidado con Mayusculas y espacios)\n");
    fgets(BuscarProducto[0],50, stdin);
    BorrarSaltolinea (BuscarProducto[0]);
    for (int i = 0; i < cont; i++)
    {
        int iguales=0;
        for (int j = 0; j < 50; j++)
        {
           if (Producto[i][j]==BuscarProducto[0][j])
                {
                    iguales=1;
                }
                else{
                    iguales=0;
                break;
            }
            if (Producto[i][j] == '\0' && BuscarProducto[0][j] == '\0')
            {
                break;
            }
            
        }
        
        if(iguales==1){
        Encontrado=i;
        break;
        }
        
    }
    if (Encontrado!=-1)
    {
        printf("Producto encontrado:\n");
        printf("N\tNombre\t\t\tPrecio\n");
        printf("%d\t%s\t\t\t%0.2f\n",Encontrado, Producto[Encontrado],Precio[Encontrado]);
    }
    else{
        printf("Producto no encontrado, intente de nuevo\n");
    }
    
    
}

void BorrarSaltolinea (char a[]){
 int len = strlen(a);
if (len > 0 && a[len-1] == '\n') {
     a[len-1] = '\0';
}
}