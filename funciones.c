#include <stdio.h>
#include <string.h>

void BorrarSaltolinea ( char a[]);
float IngresoDatos (char a[], float b[] , int cont);
float PrecioTotal(float Precio[], int cont);
void MasCaroBarato(float Precio[],char producto[][50], int cont);
void PrecioPromedio(float Precio[], int cont);
void Buscarnombre(char Producto[][50], float Precio[], int cont);
int validarOpc();


float IngresoDatos (char a[], float b[], int cont ){
    if (cont<10){ // esto permite solo 10 productos
    char c[1][100];
    
    printf("MAX: 10 productos\n");
    fgets(c[0], sizeof(c), stdin); // un fgets que cumple la función del fflush de limpiar el buffer. sizeof -> tamaño de, en este caso de las misma variable
    do
    {
    printf("Nombre del producto: ");
    fgets(a, 50, stdin);
    BorrarSaltolinea(a);
    } while (a[0]=='\0'); // si la cadena esta vacia '\0' entonces no te deja avanzar
    
    printf("Precio del producto: ");
    if (scanf("%f",&b[cont])!=1){ //Para que el valor ingresado si sea un float
        fgets(c[0], sizeof(c), stdin);
        printf("El valor ingresado no es valido\n");
        return cont; // no aumenta el contador, por ende invalida este intento de ingreso de datos
    }
    else if (b[cont]<0) //Para que solo pueda ser un valor positivo
    {
        printf("El valor ingresado no es valido\n");
        return cont; // no aumenta el contador, por tanto inválida del intento
    }
    else{
    cont++; // si todo se hizo correctamente el contador aumenta a la siguiente iteración
    return cont;
    }
   
    }
    else{
        printf("Cantidad Maxima de productos alcanzada\n");
        return cont; // si ya se consiguieron mas de 10 productos, no te deja hacer nada más
    }
    
}

float PrecioTotal(float Precio[], int cont){
    float Total=0;
    for ( int i = 0; i < cont; i++)
    {
        Total+=Precio[i]; // suma todos lo precios de productos que hay hasta el contador
    }
    return Total;
}

void MasCaroBarato(float Precio[],char producto[][50], int cont){
    int indice1=0, indice2=0;
    float MasCaro=0, MasBarato=1000; /*se inicializa el Mascaro para que el primera valor que haya sea el mayor, en MasBarato se 
    inicializa en un numero grande, para que el primera valor que haya sea el menor y depues comparar con los demás */ 
    if (cont>0) //Esto solo si hay al menos un producto registrado
    {
    for (int i = 0; i < cont; i++)//El contador funciona para comparar con la totalidad de productos que se tienen hasta el momento
    {
        if (Precio[i]>MasCaro)
        {
            MasCaro=Precio[i];
            indice1=i; //Si es mas caro que los demas, se guarda el indice del producto
        }
        if (Precio[i]<MasBarato)
        {
            MasBarato=Precio[i];
            indice2=i;// Si es mas barato que los demás se guarda el indice del producto
        }
        
    }
    printf("El producto mas caro del inventario es %s de precio: %.02f\n", producto[indice1], Precio[indice1]); //Imprime el mas caro con su indice
    printf("El producto mas barato del inventario es %s de precio: %0.2f\n", producto[indice2], Precio[indice2]);//Imprime el mas barato con su indice
    }
    else{
        printf("No hay productos en el inventario\n");
    }
    
}

void PrecioPromedio(float Precio[], int cont){
    float Sumatoria=0, promedio=0;
    if (cont>0) //Mientras haya al menos 1 producto registrado
    {    
    Sumatoria=PrecioTotal(Precio, cont); //Se reutiliza la función que calcula la suma de los precios de los productos
    promedio=Sumatoria/(cont); // se divide para el numero de productos

    printf("El precio promedio de todos los productos es de: %.02f\n",promedio);
    }
    else{
        printf("No dispone de ningun producto en el invertario\n");
    }
    
}

void Buscarnombre(char Producto[][50], float Precio[], int cont){
    char BuscarProducto[1][50]={0};
    int Encontrado=-1; //En esta variable se guardará el indice del producto
    char c[1][100];

    if (cont>0) //Siempre que haya 1 producto registrado
    {
    fgets(c[0], sizeof(c), stdin); //Limpia el buffer
    printf("Ingrese el nombre del producto que desea buscar (tenga cuidado con los espacios)\n");
    fgets(BuscarProducto[0],50, stdin);
    BorrarSaltolinea (BuscarProducto[0]);//Borrar el salto de linea
    
    for (int i = 0; i < cont; i++) //Con el for se compara todas las cadenas de nombre con la que tu ingresaste
    {
        if(_stricmp(Producto[i], BuscarProducto[0])==0){ //la función _stricmp compara dos cadenas, retorna el valor de 0 si son iguales (no distingue mayusculas)
            Encontrado=i; //Si encuentra el producto deja de comparar y sale de for, encontrado sera igual al indice de la cadena encontrada
            break;
        }
    }
    if (Encontrado!=-1)// si se encotro la cadena, el indice sera de 0 en adelante
    {
        printf("Producto encontrado:\n");
        printf("N\tNombre\t\t\tPrecio\n");
        printf("%d\t%s\t\t\t%0.2f\n",Encontrado, Producto[Encontrado],Precio[Encontrado]);
    }
    else{ // si no se ha encontrado la cadena buscada te pide intetarlo nuevamente
        printf("Producto no encontrado, intente de nuevo\n");
    }
    }
    else{
        printf("No dispone de ningun producto en el inventario\n");
    }
    
}

void BorrarSaltolinea (char a[]){
int len = strlen(a);//Obtiene el tamaño de la cadena
if (len > 0 && a[len-1] == '\n') { // se asegura de que la cadena no este vacia y de que el ultimo caracter si sea un salto de linea
    a[len-1] = '\0'; //De haber un salto de linea, lo cambia por el valor nulo
}
}

int validarOpc(){
    int opc2=0;
    char c[1][50];
     do {
        printf("Quiere hacer otra operacion 1. Si 2. No: ");
        if (scanf("%d", &opc2) != 1) { //Que valide que sea un numero int
            printf("Entrada invalida. Intente de nuevo.\n");
            fgets(c[0], sizeof(c), stdin); //Limpia el buffer
            opc2 = 0; 
        }
    } while (opc2 != 1 && opc2 != 2);// que solo puedas elegir entre esas dos opciones 1 o 2
    return opc2; //Regresa la opción escogida
}
