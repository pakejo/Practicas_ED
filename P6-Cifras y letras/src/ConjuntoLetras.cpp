
#include <ConjuntoLetras.h>

ConjuntoLetras::ConjuntoLetras() {}

void ConjuntoLetras::CargarFicheroLetras(const char *filename)
{
    ifstream f(filename);
    string entrada;
    Letra l;
    int cont = 0, frec, puntos;

    if (!f)
    {
        cout << "Error al abrir el Fichero Letras" << endl;
    }

    getline(f, entrada); // ignorar la primera linea

    while (getline(f, entrada, '\t'))
    {
        if (!entrada.empty())
        {
            switch (cont)
            {
            case 0:
                l.setLetra(entrada[0]);
                cont++;
                break;
            case 1:
                frec = stoi(entrada);
                l.setFrec(frec);
                cont++;
                break;

            case 2:
                puntos = stoi(entrada);
                l.setPuntos(puntos);
                this->conjunto.push_back(l);
                cont = 0;
                break;
            }
        }
    }
}

int ConjuntoLetras::CalcularPuntosPalabra(string palabra)
{
    int offset = 97;
    int puntos = 0;

    for (auto it = palabra.begin(); it != palabra.end(); ++it)
    {
        puntos += this->conjunto[(*it) - offset].getPuntos();
    }

    return puntos;
}

bool ConjuntoLetras::empty()
{
    return this->conjunto.empty();
}

ConjuntoLetras::iterator::iterator() {}

Letra ConjuntoLetras::iterator::operator*()
{
    return *it;
}

ConjuntoLetras::iterator &ConjuntoLetras::iterator::operator++()
{
    ++this->it;
    return *this;
}

ConjuntoLetras::iterator &ConjuntoLetras::iterator::operator=(const ConjuntoLetras::iterator &i)
{
    if (this != &i)
    {
        this->it = i.it;
    }

    return *this;
}

bool ConjuntoLetras::iterator::operator==(const ConjuntoLetras::iterator &i)
{
    return this->it == i.it;
}

bool ConjuntoLetras::iterator::operator!=(const ConjuntoLetras::iterator &i)
{
    return this->it != i.it;
}

ConjuntoLetras::iterator ConjuntoLetras::begin()
{
    iterator it;
    it.it = this->conjunto.begin();
    return it;
}

ConjuntoLetras::iterator ConjuntoLetras::end()
{
    iterator it;
    it.it = this->conjunto.end();
    return it;
}