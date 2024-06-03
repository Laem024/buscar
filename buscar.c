#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <emscripten.h>

int Secuencial(int);
int Binario(int);
void Burbuja(int[]);
void Quicksort(int[]);
void qs(int[], int, int);

int main() {
    int original[] = {1,2,40,10,15,36};
    int vector[] = {};
    int resultado;

    for (int i = 0; i < 6; i++)
    {
        vector[i] = original[i];
    }

    printf("Secuencial\n");
    resultado = Secuencial(2);

    if(resultado > -1)
    {
        printf("el numero buscado se encuenta en la posicion => %d\n", resultado);
    }else{
        printf("el numero buscado no se encuenta en el arreglo");
    }


    printf("Binario\n");
    resultado = Binario(2);

    if(resultado > -1)
    {
        printf("el numero buscado se encuenta en la posicion => %d\n", resultado);
    }else{
        printf("el numero buscado no se encuenta en el arreglo");
    }
    

    printf("Desordenado\n");

    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", vector[i]);
    }

    Burbuja(vector);  

    printf("Burbuja\n");

    for (int i = 0; i < 7; i++)
    {
        printf("%d\n", vector[i]);
    }
    
    
    
    for (int i = 0; i < 6; i++)
    {
        vector[i] = original[i];
    }

    Quicksort(vector);

    printf("Quicksort\n");

    for (int i = 1; i < 7; i++)
    {
        printf("%d\n", vector[i]);
    }



    return 0;
}

//ordenamos el vector
EMSCRIPTEN_KEEPALIVE
void Burbuja(int vector[])
{
    //int vector[]= {1,2,40,36,10,15};
    int tamaño = 6;
    int aux;
    for (int i = 0; i < tamaño; i++)
    {
        for (int j = 0; j < tamaño; j++)
        {
            if(vector[j] > vector[j+1])
            {
                aux = vector[j+1];
                vector[j+1] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

//Busqueda secuencial
EMSCRIPTEN_KEEPALIVE
int Secuencial(int valorBuscado)
{
    int vector[] = {1,2,40,36,10,15};
    int tamaño = 6;

    for (int i = 0; i < tamaño; i++)
    {
        if(vector[i] == valorBuscado)
        {
            return i;
        }
    }

    return -1;
    
}

//Busqueda binaria
EMSCRIPTEN_KEEPALIVE
int Binario(int dato)
{
    int vector[] = {1,2,10,15,36,40};
    int inicio=0;
    int final=6;
    int mid;

    while (inicio <= final)
    {
        mid = (inicio + final) / 2;

        if(vector[mid] == dato)
        {
            return mid;
        }else if(dato < vector[mid]){
            final  = mid -1;
        }else{
            inicio = mid + 1;
        }
    }

    return -1;
}

EMSCRIPTEN_KEEPALIVE
void Quicksort(int vector[])
{
    //int vector[] = {1,2,40,36,10,15};
    int tam = 6;

    qs(vector, 0, tam-1);

    //printf("%d", *vector);
}

void qs(int vector[], int inicio, int final)
{
    int izq, der, pivote, aux;

    izq = inicio;
    der = final;

    pivote = vector[(izq + der) / 2];

    do
    {
        while (vector[izq] < pivote && izq < final)
        {
            izq++;
        }
        
        while (vector[der] > pivote && der > inicio)
        {
            der --;
        }

        if (izq <= der)
        {
            aux = vector[izq];
            vector[izq] = vector[der];
            vector[der] = aux;
            izq ++;
            der --;
        }
        
        
    } while (izq <= der);

    if(inicio <= der)
    {
        qs(vector, inicio, der);
    }

    if (final > izq)
    {
        qs(vector, izq, final);
    }
    
    
}