
#include "guiatlf.h"

/*----------------Funciones auxiliares----------------*/

istream &operator>>(istream &is, pair<string, string> &d)
{

    getline(is, d.first, '\t');
    getline(is, d.second);
    return is;
}

ostream &operator<<(ostream &os, std::pair<string, string> &d)
{

    os << d.first << '\t' << d.second << endl;
    return os;
}

/*----------------------------------------------------*/

Guia_Tlf::Guia_Tlf(string name, string tlf)
{
    datos.insert(std::pair<string, string>(name, tlf));
}

Guia_Tlf::Guia_Tlf(std::initializer_list<map<string, string>::value_type> l)
{
    datos.insert(l);
}

int Guia_Tlf::size() const
{
    return datos.size();
}

void Guia_Tlf::clear()
{
    datos.clear();
}

string Guia_Tlf::getTelefono(const string &nombre)
{
    map<string, string>::iterator it = datos.find(nombre);
    if (it == datos.end())
        return string("");
    else
        return it->second;
}

pair<map<string, string>::iterator, bool> Guia_Tlf::insert(string nombre, string tlf)
{
    pair<string, string> p(nombre, tlf);
    pair<map<string, string>::iterator, bool> ret;

    ret = datos.insert(p);
    return ret;
}

pair<map<string, string>::iterator, bool> Guia_Tlf::insert(pair<string, string> p)
{

    pair<map<string, string>::iterator, bool> ret;

    ret = datos.insert(p);
    return ret;
}

void Guia_Tlf::borrar(const string &nombre)
{
    map<string, string>::iterator itlow = datos.lower_bound(nombre);
    map<string, string>::iterator itupper = datos.lower_bound(nombre);
    itupper++;
    datos.erase(itlow, itupper);

    /*map<string, string>::iterator it = datos.find(nombre);

    if(it != datos.end())
        datos.erase(it);*/
}

void Guia_Tlf::borrar(const string &nombre, const string &tlf)
{
    map<string, string>::iterator itlow = datos.lower_bound(nombre);   //el primero que tiene dicho nombre
    map<string, string>::iterator itupper = datos.upper_bound(nombre); //el primero que ya no tiene dicho nombre
    map<string, string>::iterator it;
    bool salir = false;

    for (it = itlow; it != itupper && !salir; ++it)
    {
        if (it->second == tlf)
        {
            datos.erase(it);
            salir = true;
        }
    }
}

Guia_Tlf Guia_Tlf::previos(const string &nombre, const string &tlf)
{
    map<string, string>::value_compare vc = datos.value_comp(); //map<string,string>::key_compare vc=datos.key_comp()
    Guia_Tlf aux;
    pair<string, string> p(nombre, tlf);
    map<string, string>::iterator it = datos.begin();

    while (vc(*it, p))
    {
        aux.insert(*it++);
    }
    return aux;
}

Guia_Tlf Guia_Tlf::substract(const string &min, const string &max)
{
    map<string, string>::iterator it1, it2;
    Guia_Tlf aux;

    it1 = this->datos.find(min);
    it2 = this->datos.find(max);

    for (it1; it1 != it2; it1++)
        aux.datos.insert(std::pair<string, string>(it1->first, it1->second));

    return aux;
}

Guia_Tlf Guia_Tlf::posteriores(const string &nombre, const string &tlf)
{
    map<string, string>::value_compare vc = datos.value_comp(); //map<string,string>::key_compare vc=datos.key_comp()
    Guia_Tlf aux;
    pair<string, string> p(nombre, tlf);

    for (auto it = datos.begin(); it != datos.end(); ++it)
    {
        if (!vc(*it, p))
            aux.insert(*it);
    }

    return aux;
}

void Guia_Tlf::swap(Guia_Tlf &g2)
{
    this->datos.swap(g2.datos);
}

string Guia_Tlf::buscar_titular(const string num)
{
    for(auto it = datos.begin(); it != datos.end(); ++it)
    {
        if(it->second == num)
            return it->first;
    }

    return "";
}

Guia_Tlf &Guia_Tlf::operator=(const Guia_Tlf &otra)
{
    if(this != &otra)
    {
        this->datos = otra.datos;
    }

    return *this;
}

string &Guia_Tlf::operator[](const string &nombre)
{
    return datos[nombre];
}

Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf &g)
{
    Guia_Tlf aux(*this);
    map<string, string>::const_iterator it;
    for (it = g.datos.begin(); it != g.datos.end(); ++it)
    {
        aux.insert(it->first, it->second);
    }
    return aux;
}

Guia_Tlf Guia_Tlf::operator-(const Guia_Tlf &g)
{
    Guia_Tlf aux(*this);
    map<string, string>::const_iterator it;
    for (it = g.datos.begin(); it != g.datos.end(); ++it)
    {
        aux.borrar(it->first, it->second);
    }
    return aux;
}

ostream &operator<<(ostream &os, Guia_Tlf &g)
{
    map<string, string>::iterator it;
    for (it = g.datos.begin(); it != g.datos.end(); ++it)
    {
        os << it->first << "\t" << it->second << endl;
    }
    return os;
}

istream &operator>>(istream &is, Guia_Tlf &g)
{
    pair<string, string> p;

    while (is >> p)
    {
        g.insert(p);
    }

    return is;
}

Guia_Tlf::iterator &Guia_Tlf::iterator::operator++()
{
    ++it;
}

Guia_Tlf::iterator &Guia_Tlf::iterator::operator--()
{
    --it;
}
pair<const string, string> &Guia_Tlf::iterator::operator*()
{
    return *it;
}
bool Guia_Tlf::iterator::operator==(const iterator &i)
{
    return i.it == it;
}

bool Guia_Tlf::iterator::operator!=(const iterator &i)
{
    return i.it != it;
}

Guia_Tlf::iterator &Guia_Tlf::iterator::operator=(const iterator &it)
{
    if(this != &it)
    {
        this->it = it.it;
    }

    return *this;
}

Guia_Tlf::iterator Guia_Tlf::begin()
{
    iterator i;
    i.it = datos.begin();
    return i;
}

Guia_Tlf::iterator Guia_Tlf::end()
{
    iterator i;
    i.it = datos.end();
    return i;
}