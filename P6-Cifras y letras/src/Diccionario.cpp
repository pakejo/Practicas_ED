
#include <Diccionario.h>

Diccionario::Diccionario() {}

int Diccionario::size() const
{
    return this->datos.size();
}

vector<string> Diccionario::PalabrasLongitud(unsigned int longitud)
{
    vector<string> diccionario;

    for (auto it = datos.begin(); it != datos.end(); ++it)
    {
        if (it->size() == longitud)
            diccionario.push_back(*it);
    }

    return diccionario;
}

bool Diccionario::Esta(string palabra)
{
    set<string>::iterator it = datos.find(palabra);

    return it != datos.end();
}

istream &operator>>(istream &is, Diccionario &D)
{
    string palabra;

    while (getline(is, palabra))
    {
        if(!palabra.empty())
            D.datos.insert(palabra);
    }

    return is;
}

ostream &operator<<(ostream &os, Diccionario &D)
{
    for (auto it = D.datos.begin(); it != D.datos.end(); ++it)
    {
        cout << *it << endl;
    }

    return os;
}

Diccionario::iterator::iterator() {}

string Diccionario::iterator::operator*()
{
    return *it;
}

Diccionario::iterator& Diccionario::iterator::operator++()
{
    ++it;
    return *this;
}

Diccionario::iterator& Diccionario::iterator::operator=(Diccionario::iterator &i)
{
    if(this != &i)
        this->it = i.it;
    
    return *this;
}

bool Diccionario::iterator::operator==(const Diccionario::iterator &i)
{
    return this->it == i.it;
}

bool Diccionario::iterator::operator!=(const Diccionario::iterator &i)
{
    return this->it != i.it;
}

Diccionario::iterator Diccionario::begin()
{
    iterator iter;
    iter.it = this->datos.begin();
    return iter;
}

Diccionario::iterator Diccionario::end()
{
    iterator iter;
    iter.it = this->datos.end();
    return iter;
}

