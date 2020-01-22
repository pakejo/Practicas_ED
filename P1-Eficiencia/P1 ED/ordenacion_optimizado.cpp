#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

    for (int i = 0; i < tam; i++)
        v[i] = 1 + rand() % (101 - 1); // Genera número aleatorio entre 1 y 100
}

void ordenar(int *v, int n)
{
    bool cambio = true;
    for (int i = 0; i < n - 1 && cambio; i++)
    {
        cambio = false;
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1])
            {
                cambio = true;
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
    }
}

void crearMejorCaso(int *v, int tam)
{
    for (int i = 0; i < tam; i++)
        v[i] = i;
}

void crearPeorCaso(int *v, int tam)
{
    for (int i = tam; i < 0; i--)
        v[i] = i;
}

int main(int argc, char *argv[])
{
    steady_clock::time_point inicio, fin;
    duration<double> tiempo;

    if (argc != 2)
        sintaxis();

    int tamanio = atoi(argv[1]);

    int *vec = new int[tamanio];

    //llenarVector(vec, tamanio);
    crearMejorCaso(vec,tamanio);
    //crearPeorCaso(vec, tamanio);

    inicio = steady_clock::now();

    ordenar(vec, tamanio); //  Ordenamos el vecotr

    fin = steady_clock::now();

    tiempo = duration_cast<duration<double>>(fin - inicio);

    cout << tamanio << "\t" << tiempo.count() << endl;

    delete[] vec;
}