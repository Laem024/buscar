#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <emscripten.h>

// int Secuencial(int);
// int Binario(int);
// void Burbuja(int[]);
// void Quicksort(int[]);
void qs(int[], int, int);

//Burbuja
EMSCRIPTEN_KEEPALIVE
void Burbuja()
{
    int vector[]= {1,2,10,15,36,40};
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
    int vector[]= {1,2,10,15,36,40};
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

//Quicksort
EMSCRIPTEN_KEEPALIVE
void Quicksort()
{
    int vector[] = {1,2,40,36,10,15};
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