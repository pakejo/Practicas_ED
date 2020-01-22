
#include <IA.h>

IA::IA()
{
    this->modo_juego = 'L';
}

void IA::setModoJuego(char modo)
{
    this->modo_juego = modo;
}

void IA::Insertar(ArbolGeneral<pair<char, int>> &origen, ArbolGeneral<pair<char, int>> &rama)
{
    ArbolGeneral<pair<char, int>>::Nodo n = origen.raiz()->izqda;
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
            ArbolGeneral<pair<char, int>> rama_sin_incial;
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
            ArbolGeneral<pair<char, int>> rama_sin_incial;
            rama_sin_incial.asignar_subarbol(rama, rama.raiz()->izqda);
            origen.insertar_hermanoderecha(n, rama_sin_incial);
        }
    }
}

void IA::CrearArbolPalabra(string &p, ArbolGeneral<pair<char, int>> &arb)
{

    if (arb.empty())
    {
        arb.AsignaRaiz(make_pair(*(p.begin()), calcularPuntosPalabra(p)));
    }
    else
    {
        ArbolGeneral<pair<char, int>> temp;
        ArbolGeneral<pair<char, int>>::Nodo n = arb.raiz();

        temp.AsignaRaiz(make_pair(p[0], arb.raiz()->etiqueta.second));

        while ((*n).izqda != 0)
            n = (*n).izqda;

        arb.insertar_hijomasizquierda(n, temp);
    }

    p.erase(p.begin());

    if (!p.empty())
        CrearArbolPalabra(p, arb);
}

void IA::CrearArbolLongitud(Diccionario D, int l)
{
    ArbolGeneral<pair<char, int>> palabra;
    string p;

    for (auto it = D.begin(); it != D.end(); ++it)
    {
        p = *it;
        palabra.clear();

        if (p.size() < l)
        {
            // Pasamos la palabra a un arbol
            CrearArbolPalabra(p, palabra);

            // Lo insertamos a su inicial
            Insertar(this->tree, palabra);
        }
    }
}

void IA::CrearArbolLongitud(Diccionario2 &D, int l)
{
    ArbolGeneral<pair<char, int>> palabra;
    string p;

    for (auto it = D.begin(); it != D.end(); ++it)
    {
        p = *it;
        palabra.clear();

        if (p.size() < l)
        {
            // Pasamos la palabra a un arbol
            CrearArbolPalabra(p, palabra);

            // Lo insertamos a su inicial
            Insertar(this->tree, palabra);
        }
    }
}

void IA::CrearArbolPuntuacion(Diccionario D, ConjuntoLetras P)
{
    ArbolGeneral<pair<char, int>> palabra;
    string p;

    this->conj = P;

    for (auto it = D.begin(); it != D.end(); ++it)
    {
        p = *it;
        palabra.clear();

        // Pasamos la palabra a un arbol
        CrearArbolPalabra(p, palabra);

        // Lo insertamos a su inicial
        Insertar(this->tree, palabra);
    }
}

void IA::CrearArbolPuntuacion(Diccionario2 &D, ConjuntoLetras P)
{
    ArbolGeneral<pair<char, int>> palabra;
    string p;

    this->conj = P;

    for (auto it = D.begin(); it != D.end(); ++it)
    {
        p = *it;
        palabra.clear();

        // Pasamos la palabra a un arbol
        CrearArbolPalabra(p, palabra);

        // Lo insertamos a su inicial
        Insertar(this->tree, palabra);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

bool IA::estaLetraEnVector(char letra, vector<char> vec, int &pos)
{
    bool para = false;

    for (int i = 0; i < vec.size() && !para; ++i)
    {
        if (vec[i] == letra)
        {
            para = true;
            pos = i;
            return true;
        }
    }

    return false;
}

void IA::palabrasValidas(ArbolGeneral<pair<char, int>>::Nodo rama, vector<char> vec, string &s)
{
    int it = 0;
    bool para = false;

    while (rama != 0 && !para)
    {
        if (estaLetraEnVector((*rama).etiqueta.first, vec, it))
        {
            s.push_back((*rama).etiqueta.first);
            vec.erase(vec.begin() + it);
            rama = (*rama).izqda;
        }
        else
        {
            para = true;
            s.clear();
        }
    }
}

vector<string> IA::ObtenerPalabras(vector<char> letras)
{
    int long_max = 0;           // Longitud / puntuacion maxima actual
    int it;                     // Posicion sobre el vector letras
    string posible_solucion;    // Palabra del diccionario que es solucion
    vector<char> temp = letras; // Vector temporal
    vector<string> soluciones;  // Vector con las soluciones
    char inicial;
    int puntos;

    // Inicializamos n al hijo más a la izquierda
    ArbolGeneral<pair<char, int>>::Nodo n = this->tree.raiz()->izqda;

    while (n != 0)
    {
        // Comprobamos si la letra de ese nodo está en el vector
        bool esta_letra = this->estaLetraEnVector((*n).etiqueta.first, temp, it);

        // Si la letra no está nos saltamos ese nodo y pasamos al siguiente (1º nivel)
        if (!esta_letra)
        {
            n = (*n).drcha;
        }
        // Si la letra tiene una posible solucion pero es de menor longitud a la actual la pasamos
        else if ((*n).etiqueta.second < calcularPuntosPalabra(posible_solucion))
        {
            n = (*n).drcha;
        }
        // Si la letra si está en el vector exploramos esa rama (2º nivel)
        else
        {
            ArbolGeneral<pair<char, int>>::Nodo n2 = (*n).izqda;
            inicial = (*n).etiqueta.first;

            while (n2 != 0)
            {
                // Si la longitud de esa palabra es menor al limite actual la saltamos
                if ((*n2).etiqueta.second < long_max)
                {
                    n2 = (*n2).drcha;
                }
                else // Comprobamos si es palabra valida
                {
                    posible_solucion = *(temp.begin() + it); // añadir la inicial
                    temp.erase(temp.begin() + it);
                    this->palabrasValidas(n2, temp, posible_solucion);

                    // Si la palabra no esta vacia
                    if (!posible_solucion.empty())
                    {
                        // Si el vector de soluciones no está vacio
                        if (!soluciones.empty())
                        {
                            // Si la solucion actual es mejor borramos el vector y la añadimos
                            if (calcularPuntosPalabra(posible_solucion) > calcularPuntosPalabra(soluciones[0]))
                            {
                                soluciones.clear();
                                soluciones.push_back(posible_solucion);
                                long_max = calcularPuntosPalabra(posible_solucion);
                            }
                            else if(calcularPuntosPalabra(posible_solucion) == calcularPuntosPalabra(soluciones[0]))
                                soluciones.push_back(posible_solucion);
                        }
                        else
                            soluciones.push_back(posible_solucion);
                    }
                    n2 = (*n2).drcha;
                }
                temp = letras;
            }
            n = (*n).drcha;
        }
    }
    return soluciones;
}

int IA::calcularPuntosPalabra(string s)
{
    if (this->modo_juego == 'L')
        return s.size();
    else
        return this->conj.CalcularPuntosPalabra(s);
}