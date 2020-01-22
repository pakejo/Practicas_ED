#include <Letra.h>

Letra::Letra() 
{
    this->letra = '\0';
    this->frecuencia = 0;
    this->puntos = 0;
}

Letra::Letra(char letra, int frec, int puntos)
{
    this->letra = letra;
    this->frecuencia = frec;
    this->puntos = puntos;
}

void Letra::setLetra(char letra) { this->letra = letra; }

void Letra::setFrec(int frec) { this->frecuencia = frec; }

void Letra::setPuntos(int puntos) { this->puntos = puntos; }

char Letra::getLetra() const { return this->letra; }

int Letra::getFrecuencia() const { return this->frecuencia; }

int Letra::getPuntos() const { return this->puntos; }

bool Letra::operator<(const Letra &l) const
{
    return this->letra < l.letra;
}