#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Cronologia cronologia_1, cronologia_2, cronologia_3;

    if(argc < 3)
    {
        cout << "Para la demostración hace falta dos cronologias" <<endl;
        exit(1);
    }

    ifstream f(argv[1]);

    if(!f)
    {
        cout << "No se pudo arir el archivo 1" <<endl;
        exit(1);
    }

    f >> cronologia_1;

    ifstream f2(argv[2]);

    if(!f2)
    {
        cout << "No se pudo arir el archivo 1" <<endl;
        exit(1);
    }

    f2 >> cronologia_3;

    cout << "Cronologia leida" <<endl;
    cout << "Numero de fechas: " << cronologia_1.size() <<endl;
    cout << "Obtenemos un fecha por su año. Ej: 1967: " <<endl;
    cout << cronologia_1.getFecha(1967) <<endl;
    cout << "Obtenemos un fecha por si indice: Ej: 10" <<endl;
    cout << cronologia_1.getIndex(10) <<endl;
    cout << "Obtenemos un periodo de tiempo (ej. 1956-1967)" <<endl;

    cronologia_2 = cronologia_1.getEventosEntre(1956,1967);
    cout << cronologia_2 <<endl;

    cout << "Buscamos el año de un evento en la nueva cronologia (Ej: Heapsort developed by J. W. J. Williams)" <<endl;
    cout << cronologia_2.buscarEvento("Heapsort developed by J. W. J. Williams") <<endl;
    cout << "Obtenemos los eventos de una fecha Ej: año 1998" <<endl;
    
    VectorDinamico<string> eventos = cronologia_1.getEventosFecha(1998);

    for (int i = 0; i < eventos.size(); i++)
        cout << '#' <<eventos[i] <<endl;

    cout << "Sumamos dos cronologias, timeline de algoritmos y peliculas" <<endl;
    cronologia_3 = cronologia_1 + cronologia_3;
    cout << cronologia_3 <<endl;

    cout << "Filtramos una cronologia por una palabra. Ej: number" <<endl;
    string s("number");
    cronologia_3 = cronologia_3.filtrarPalabra(s);
    cout << cronologia_3 <<endl;
}