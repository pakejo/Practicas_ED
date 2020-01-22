
#include <Diccionario2.h>

Diccionario2::Diccionario2()
{
    this->n_elementos = 0;
}

///////////////////////////////////////////////////////////////////////////
string Diccionario2::reconstruirPalabra(ArbolGeneral<tBase>::Nodo n2)
{
    string palabra = "";

    // Añadimos la inicial
    palabra += n2->padre->etiqueta.first;

    // Reconstruimos la palabra
    while (n2 != 0)
    {
        palabra += n2->etiqueta.first;
        n2 = n2->izqda;
    }

    return palabra;
}

void Diccionario2::Insertar(ArbolGeneral<tBase> &origen, ArbolGeneral<tBase> &rama)
{
    ArbolGeneral<tBase>::Nodo n = origen.raiz()->izqda;
    bool encontrado = false;

    // Buscamos el nodo cuya inicial sea la inicial de la rama
    while (n != 0 && !encontrado)
    {
        if ((*n).etiqueta.first == rama.raiz()->etiqueta.first)
            encontrado = true;
        else
            n = (*n).drcha;
    }

    // Si no hemos encontrado la letra creamos un nodo
    if (!encontrado)
    {
        // Si el arbol solo tiene la raiz creamos el hijo mas a la izquierda
        if (origen.raiz()->izqda == 0)
            origen.insertar_hijomasizquierda(origen.raiz(), rama);

        else // Insertamos un nuevo nodo mas a la derecha
        {
            n = origen.raiz()->izqda;

            while ((*n).drcha != 0)
                n = (*n).drcha;

            origen.insertar_hermanoderecha(n, rama);
        }
    }
    else // Si hemos encontrado la letra n apuntará a ese nodo por lo que añadimo la rama
    {
        // Si existe la inicial es porque ya hay una palabra con esa inicial por lo que solo
        // tenemos que crear un hijo a la derecha del hijo mas a la izquierda

        // Si la palabra es monosílabo
        if ((*n).izqda == 0)
        {
            ArbolGeneral<tBase> rama_sin_incial;
            rama_sin_incial.asignar_subarbol(rama, rama.raiz()->izqda);
            origen.insertar_hijomasizquierda(n, rama_sin_incial);

            //Propagar la longitud de la palabra a la inicial
            if ((*n).etiqueta.second < rama.raiz()->etiqueta.second)
                (*n).etiqueta.second = rama.raiz()->etiqueta.second;
        }
        else
        {
            //Propagar la longitud de la palabra a la inicial
            if ((*n).etiqueta.second < rama.raiz()->etiqueta.second)
                (*n).etiqueta.second = rama.raiz()->etiqueta.second;

            // Insertar la nueva palabra
            n = (*n).izqda;

            while ((*n).drcha != 0)
                n = (*n).drcha;

            // Eliminamos la raiz de la rama
            ArbolGeneral<tBase> rama_sin_incial;
            rama_sin_incial.asignar_subarbol(rama, rama.raiz()->izqda);
            origen.insertar_hermanoderecha(n, rama_sin_incial);
        }
    }
}

void Diccionario2::CrearArbolPalabra(string &p, ArbolGeneral<tBase> &arb)
{

    if (arb.empty())
    {
        string temp;
        temp.push_back(*(p.begin()));
        arb.AsignaRaiz(make_pair(temp, p.size()));
    }
    else
    {
        ArbolGeneral<tBase> temp;
        ArbolGeneral<tBase>::Nodo n = arb.raiz();
        string s;

        s.push_back(p[0]);

        temp.AsignaRaiz(make_pair(s, arb.raiz()->etiqueta.second));

        while ((*n).izqda != 0)
            n = (*n).izqda;

        arb.insertar_hijomasizquierda(n, temp);
    }

    p.erase(p.begin());

    if (!p.empty())
        CrearArbolPalabra(p, arb);
}

//////////////////////////////////////////////////////////////////////////
int Diccionario2::size() const
{
    return this->n_elementos;
}

vector<string> Diccionario2::PalabrasLongitud(unsigned int longitud)
{
    vector<string> diccionario;

    ArbolGeneral<tBase>::Nodo n1 = this->arbol.raiz()->izqda;
    ArbolGeneral<tBase>::Nodo n2;

    // Recorremos el primer nivel
    while (n1 != 0)
    {
        // Recorremos el segundo nivel
        n2 = n1->izqda;

        while (n2 != 0)
        {
            if ((*n2).etiqueta.second == longitud)
                diccionario.push_back(reconstruirPalabra(n2));

            n2 = n2->drcha;
        }

        n1 = n1->drcha;
    }

    return diccionario;
}

bool Diccionario2::Esta(string palabra)
{
    string p;
    ArbolGeneral<tBase>::Nodo n1 = this->arbol.raiz()->izqda;
    ArbolGeneral<tBase>::Nodo n2;

    // Recorremos el primer nivel
    while (n1 != 0)
    {
        // Recorremos el segundo nivel
        n2 = n1->izqda;

        while (n2 != 0)
        {
            p = reconstruirPalabra(n2);
            n2 = n2->drcha;

            if (p == palabra)
                return true;
        }

        n1 = n1->drcha;
    }

    return false;
}

istream &operator>>(istream &is, Diccionario2 &D)
{
    ArbolGeneral<pair<string, int>> palabra;
    string p;
    set<string> dic_set;

    // Se inserta en un set para que se ordenen automaticamente
    while (getline(is, p))
    {
        if (!p.empty())
            dic_set.insert(p);
    }

    // Pasamos el set a arbol
    for (auto it = dic_set.begin(); it != dic_set.end(); ++it)
    {
        p = *it;
        D.n_elementos++;
        palabra.clear();

        // Pasamos la palabra a un arbol
        D.CrearArbolPalabra(p, palabra);

        // Lo insertamos a su inicial
        D.Insertar(D.arbol, palabra);
    }

    return is;
}

ostream &operator<<(ostream &os, Diccionario2 &D)
{

    for (auto it = D.begin(); it != D.end(); ++it)
        cout << *it << endl;

    return os;
}

Diccionario2::iterator::iterator() {}

string Diccionario2::iterator::operator*()
{
    return dic->reconstruirPalabra(this->n2);
}

Diccionario2::iterator &Diccionario2::iterator::operator++()
{

    if (this->n2->drcha != 0)
        this->n2 = this->n2->drcha;
    else
    {
        if (this->n2->padre->drcha == 0)
            this->n2 = 0;
        else
            this->n2 = this->n2->padre->drcha->izqda;
    }

    return *this;
}

Diccionario2::iterator &Diccionario2::iterator::operator=(Diccionario2::iterator &i)
{
    if (this != &i)
    {
        this->dic = i.dic;
        this->n2 = i.n2;
    }

    return *this;
}

bool Diccionario2::iterator::operator==(const Diccionario2::iterator &i)
{
    return this->n2 == i.n2;
}

bool Diccionario2::iterator::operator!=(const Diccionario2::iterator &i)
{
    return this->n2 != i.n2;
}

Diccionario2::iterator Diccionario2::begin()
{
    iterator iter;
    iter.dic = this;
    iter.n2 = iter.dic->arbol.raiz()->izqda->izqda;
    return iter;
}

Diccionario2::iterator Diccionario2::end()
{
    iterator iter;
    iter.dic = this;
    iter.n2 = 0;
    return iter;
}
