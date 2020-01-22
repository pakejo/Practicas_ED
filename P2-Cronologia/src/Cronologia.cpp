/**
  * @file Cronologia.cpp
  * @brief Implementación del TDA Cronologia
  *
  */

#include "Cronologia.h"

//------------------ Funciones auxiliares-----------------
void merge(VectorDinamico<FechaHistorica> &v, int izda, int medio, int dcha)
{
    int n1, n2, i, j, k;

    n1 = medio - izda + 1;
    n2 = dcha - medio;

    VectorDinamico<FechaHistorica> L, R;
    L.resize(n1);
    R.resize(n2);

    // Inicializacion L[]
    for (int i = 0; i < n1; i++)
        L[i] = v[izda + i];

    // Inicializacion R[]
    for (int j = 0; j < n2; j++)
        R[j] = v[medio + j + 1];

    i = j = 0;
    //Comparamos y mezclamos los vectores
    for (k = izda; i < n1 && j < n2; k++)
    {
        if (L[i].getFecha() < R[j].getFecha())
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
    }

    //Si el vecotr L[] tiene mas elementos que R[]
    //entonces añadimos el resto de elementos de L[] a v
    while (i < n1)
    {
        v[k] = L[i];
        k++;
        i++;
    }

    //Si el vecotr R[] tiene mas elementos que L[]
    //entonces añadimos el resto de elementos de R[] a v
    while (j < n2)
    {
        v[k] = R[j];
        k++;
        j++;
    }
}

/**
 * Implementación del algoritmo de ordenación por mezcla O(nlogn)
 */
void mergesort(VectorDinamico<FechaHistorica> &v, int izda, int dcha)
{
    int medio;

    if (izda < dcha)
    {
        medio = (izda + dcha) / 2;
        mergesort(v, izda, medio);
        mergesort(v, medio + 1, dcha);
        merge(v, izda, medio, dcha);
    }
}

inline void Cronologia::ordenar()
{
    mergesort(this->cronologia, 0, this->cronologia.size() - 1);
}

/**
 * Implementacion del algoritmo de la busqueda binaria o(logn)
 */
inline int Cronologia::buscar(int x)
{
    int izda, dcha, medio;

    izda = 0;
    dcha = this->cronologia.size() - 1;

    while (izda <= dcha)
    {
        medio = (izda + dcha) / 2;

        if (this->cronologia[medio].getFecha() < x)
            izda = medio + 1;
        else if (this->cronologia[medio].getFecha() > x)
            dcha = medio - 1;
        else
            return medio;
    }

    return -1;
}

/* _________________________________________________________________________ */

Cronologia::Cronologia() {}

/* _________________________________________________________________________ */

Cronologia::Cronologia(const Cronologia &original)
{
    this->cronologia = original.cronologia;
}

/* _________________________________________________________________________ */
int Cronologia::size() const
{
    return this->cronologia.size();
}

/* _________________________________________________________________________ */
FechaHistorica Cronologia::getFecha(int i)
{
    int resultado = this->buscar(i);

    if (resultado != -1)
        return this->cronologia[resultado];
    else
        return FechaHistorica(i);
}

/* _________________________________________________________________________ */
FechaHistorica Cronologia::getIndex(int i)
{
    return this->cronologia[i];
}

/* _________________________________________________________________________ */
void Cronologia::setFecha(FechaHistorica f)
{
    int resultado = this->buscar(f.getFecha());

    if (resultado != -1)
        this->cronologia[resultado] = f;
}

/* _________________________________________________________________________ */
void Cronologia::add(FechaHistorica f)
{
    int resultado = this->buscar(f.getFecha());

    if (resultado == -1)
        this->cronologia.push_back(f);

    this->ordenar();
}

/* _________________________________________________________________________ */
VectorDinamico<string> Cronologia::getEventosFecha(int i)
{
    int resultado = this->buscar(i);
    VectorDinamico<string> v;

    if (resultado != -1)
        return this->cronologia[resultado].getSucesos();
    else
    {
        VectorDinamico<string> v;
        return v;
    }
}

/* _________________________________________________________________________ */
Cronologia Cronologia::getEventosEntre(int x, int y)
{
    Cronologia nueva;

    for (int i = 0; i < this->cronologia.size(); i++)
    {
        if (this->cronologia[i].getFecha() >= x && this->cronologia[i].getFecha() <= y)
            nueva.add(this->cronologia[i]);
    }

    return nueva;
}

/* _________________________________________________________________________ */
int Cronologia::buscarEvento(string s)
{
    for (int i = 0; i < this->cronologia.size(); i++)
    {
        for (int j = 0; j < this->cronologia[i].getNumSucesos(); j++)
        {
            if (this->cronologia[i].getSucesos()[j] == s)
                return this->cronologia[i].getFecha();
        }
    }

    return -1;
}

/* _________________________________________________________________________ */
Cronologia Cronologia::filtrarPalabra(string &s)
{
    Cronologia filtrada;
    size_t encontrado;

    for (int i = 0; i < this->cronologia.size(); i++)
    {
        VectorDinamico<string> tmp = this->cronologia[i].getSucesos();

        for (int j = 0; j < tmp.size(); j++)
        {
            encontrado = tmp[j].find(s);

            if (encontrado != std::string::npos)
                filtrada.add(this->cronologia[i]);
        }
    }

    return filtrada;
}

/* _________________________________________________________________________ */
Cronologia &Cronologia::operator=(const Cronologia &c)
{
    if (this != &c)
        this->cronologia = c.cronologia;

    return *this;
}

/* _________________________________________________________________________ */
Cronologia Cronologia::operator+(Cronologia c)
{
    Cronologia suma;
    int tmp = 0;

    for (int i = 0; i < c.size(); i++)
    {
        tmp = this->buscar(c.getIndex(i).getFecha());

        if (tmp == -1) // Añadimos una nueva fecha
            suma.add(c.getIndex(i));
        else
            suma.add(this->cronologia[tmp] + c.getIndex(i));
    }

    return suma;
}

/* _________________________________________________________________________ */
ostream &operator<<(ostream &os, const Cronologia &c)
{
    for (int i = 0; i < c.cronologia.size(); i++)
        os << c.cronologia[i];

    return os;
}

/* _________________________________________________________________________ */
istream &operator>>(istream &is, Cronologia &c)
{
    string aux;
    while (!is.eof())
    {
        getline(is, aux, '\n');
        if (!aux.empty())
        {
            FechaHistorica faux;
            istringstream ss(aux);
            ss >> faux;
            c.add(faux);
        }
    }
    return is;
}