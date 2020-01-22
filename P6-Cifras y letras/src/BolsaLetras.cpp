
#include <BolsaLetras.h>
#include <cstdlib>
#include <time.h>

void BolsaLetras::addLetra(Letra l)
{
    for (int i = 0; i < l.getFrecuencia(); i++)
        this->bolsa.push_back(l.getLetra());
}

BolsaLetras::BolsaLetras() {}

BolsaLetras::BolsaLetras(ConjuntoLetras conjunto)
{
    this->CrearBolsa(conjunto);
}

void BolsaLetras::CrearBolsa(ConjuntoLetras conjunto)
{
    for (auto it = conjunto.begin(); it != conjunto.end(); ++it)
        this->addLetra(*it);
}

vector<char> BolsaLetras::sacarLetras(int n)
{

    srand(time(NULL));
    int r = 0;
    vector<char> nuevaBolsa;

    for (int i = 0; i < n; ++i)
    {
        r = rand() % this->bolsa.size();
        nuevaBolsa.push_back(this->bolsa[r]);
    }

    return nuevaBolsa;
}
