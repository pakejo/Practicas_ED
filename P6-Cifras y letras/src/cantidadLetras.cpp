#include <iostream>
#include <fstream>
#include <vector>
#include <Diccionario.h>
#include <Letra.h>

using namespace std;

vector<Letra> CargarLetras(const char *filename)
{
    vector<Letra> vec;
    fstream f(filename);
    string letra;

    while (getline(f, letra))
    {
        Letra l;
        l.setLetra(letra[0]);
        vec.push_back(l);
    }

    return vec;
}

void CrearFicheroLetras(set<Letra> conjunto)
{
    ofstream f("./datos/ficheroLetras.txt", std::ios::out | std::ios::trunc);

    if (!f)
    {
        cout << "Error al abrir el ficheroLetras";
        exit(-1);
    }

    f << "#Letra Cantidad Puntos" << endl;

    for (auto it = conjunto.begin(); it != conjunto.end(); it++)
    {
        f << '\t' << (*it).getLetra() << "\t\t" << (*it).getFrecuencia() << "\t\t" << (*it).getPuntos() << endl;
    }
}

void CalcularPuntosLetra(vector<Letra> &letras)
{
    for(int i = 0; i < letras.size(); ++i)
    {
        letras[i].setPuntos(letras[i].getFrecuencia() % 10);
    }
}

void CalcularInfoLetras(Diccionario D, vector<Letra> letras, set<Letra> &conjunto)
{
    int n_repeticiones = 0;
    int letra_actual = 0;
    int contador_apariciones = 0;
    int puntos_letra = 0;
    string palabra;

    for (int i = 0; i < letras.size(); i++)
    {
        for (Diccionario::iterator it = D.begin(); it != D.end(); ++it)
        {
            palabra = *it;

            for (int j = 0; j < palabra.size(); j++)
            {
                if (palabra[j] == letras[i].getLetra())
                    contador_apariciones++;
            }
        }
        letras[i].setFrec(contador_apariciones);
        contador_apariciones = 0;
    }

    CalcularPuntosLetra(letras);

    for (int i = 0; i < letras.size(); i++)
        conjunto.insert(letras[i]);
}

int main(int argc, char const *argv[])
{
    if (argc < 4)
    {
        cout << "Formato: cantidad_letras diccionario letras ficheroSalida" << endl;
        return -1;
    }

    ifstream f1(argv[1]);

    if (!f1)
    {
        cout << "Error al abir el diccionario" << endl;
        return -1;
    }

    Diccionario D;
    cout << "Cargando diccionario..." << endl;
    f1 >> D;
    cout << "Diccionario leido" << endl;

    vector<Letra> letras;
    cout << "Cargando letras..." << endl;
    letras = CargarLetras(argv[2]);
    cout << "Letras cargadas" << endl;

    cout << "Generando ficheroLetras" << endl;
    set<Letra> conjunto;
    CalcularInfoLetras(D, letras, conjunto);
    CrearFicheroLetras(conjunto);
    cout << "Fichero letras generado en datos/FicheroLetras.txt" << endl;
}