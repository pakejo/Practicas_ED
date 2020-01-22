/**
  * @file fechahistorica.cpp
  * @brief Implementación del TDA FechaHistorica
  *
  */

#include "FechaHistorica.h"

/* _________________________________________________________________________ */
FechaHistorica::FechaHistorica()
{
    this->fecha = 0;
}

/* _________________________________________________________________________ */
FechaHistorica::FechaHistorica(int year)
{
    this->fecha = year;
}
/* _________________________________________________________________________ */

FechaHistorica::FechaHistorica(const FechaHistorica &f)
{
    this->fecha = f.fecha;
    this->sucesos = f.sucesos; // Operador = de la clase vector
}
/* _________________________________________________________________________ */

int FechaHistorica::getFecha() const
{
    return this->fecha;
}
/* _________________________________________________________________________ */

int FechaHistorica::getNumSucesos() const
{
    return this->sucesos.size();
}
/* _________________________________________________________________________ */

VectorDinamico<string> FechaHistorica::getSucesos()
{
    return this->sucesos;
}
/* _________________________________________________________________________ */

void FechaHistorica::setYear(int x)
{
    this->fecha = x;
}
/* _________________________________________________________________________ */

void FechaHistorica::addSuceso(string suceso)
{
    this->sucesos.push_back(suceso);
}
/* _________________________________________________________________________ */

bool FechaHistorica::existeSuceso(string suceso) const
{
    bool encontrado = false;

    for (int i = 0; i < this->sucesos.size() && !encontrado; i++)
    {
        if (this->sucesos[i] == suceso)
            encontrado = true;
    }

    return encontrado;
}
/* _________________________________________________________________________ */

FechaHistorica &FechaHistorica::operator=(const FechaHistorica &f)
{
    if (this != &f)
    {
        this->fecha = f.fecha;
        this->sucesos = f.sucesos; // Operador = de la  clase vector
    }

    return *this;
}
/* _________________________________________________________________________ */

FechaHistorica FechaHistorica::operator+(FechaHistorica f)
{
    FechaHistorica suma(*this);

    if (f.fecha == this->fecha)
    {
        for (int i = 0; i < f.getSucesos().size(); i++)
            suma.addSuceso(f.getSucesos()[i]);
    }

    return suma;
}
/* _________________________________________________________________________ */

ostream &operator<<(ostream &os, const FechaHistorica &f)
{
    os << f.fecha << '\n';

    for (int i = 0; i < f.sucesos.size(); i++)
        os << '\t' << '#' << f.sucesos[i] << '\n';

    return os;
}
/* _________________________________________________________________________ */

istream &operator>>(istream &is, FechaHistorica &f)
{
    string aux;
    getline(is, aux, '#');
    f.fecha = atoi(aux.c_str());

    while (!is.eof())
    {
        getline(is, aux, '#');
        f.addSuceso(aux);
    }
    return is;
}