#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void sintaxis()
{
    cerr << "Sintaxis:" << endl;
    cerr << " TAM: Tamaño del vector (>0)" << endl;
    exit(EXIT_FAILURE);
}

void llenarVector(int *v, int tam)
{
    srand(time(NULL));
    int num;

    for(int i= 0; i<tam; i++)
        v[i] = 1+rand()%(101-1);    // Genera número aleatorio entre 1 y 100
}

void ordenar(int *v, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1])
            {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
}

void crearMejorCaso(int *v, int tam)
{
    for(int i=0; i<tam; i++)
        v[i] = i;
}

void crearPeorCaso(int *v, int tam)
{
    for(int i=0; i<tam; i++)
        v[i] = tam - i;
}

int main(int argc, char *argv[])
{
    clock_t ti, tf;

    if(argc != 2)
        sintaxis();

    int tamanio = atoi(argv[1]);

    int *vec = new int[tamanio];

    //llenarVector(vec, tamanio);
    //crearMejorCaso(vec,tamanio);
    crearPeorCaso(vec,tamanio);

    ti = clock();   // Anotamos tiempo de inicio

    ordenar(vec, tamanio);  //  Ordenamos el vecotr

    tf = clock();   // Anotamos el tiempo de finalizacion

    cout <<tamanio <<"\t" << (tf-ti)/(double)CLOCKS_PER_SEC << endl;

    delete [] vec;
    
}