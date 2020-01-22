#include <ConjuntoLetras.h>
#include <BolsaLetras.h>
#include <IA.h>
#include <assert.h>

#ifdef SET
    #include <Diccionario.h>
#endif

#ifdef ARB
    #include <Diccionario2.h>
#endif

using namespace std;

void mostrarLetrasUsuario(vector<char> letras)
{
    cout << "Las letras son: ";

    for (int i = 0; i < letras.size(); i++)
        cout << letras[i] << " ";

    cout << endl;
}

void mostrarPalabraUsuario(string palabra, char modo, ConjuntoLetras C)
{
    int puntos_palabra;

    if (modo == 'L' || modo == 'l')
        puntos_palabra = palabra.size();
    else
        puntos_palabra = C.CalcularPuntosPalabra(palabra);

    cout << palabra << "\t"
         << "Puntuación: " << puntos_palabra << endl;
}

void mostrarPalabrasIA(vector<string> palabras, char modo, ConjuntoLetras C)
{
    int puntos_palabra;

    for (auto it = palabras.begin(); it != palabras.end(); ++it)
    {
        if (modo == 'L' || modo == 'l')
            puntos_palabra = (*it).size();
        else
            puntos_palabra = C.CalcularPuntosPalabra((*it));

        cout << *it << "\t"
             << "Puntuación: " << puntos_palabra << endl;
    }
}

int main(int argc, char *argv[])
{
    #ifdef SET
        Diccionario dic;
    #endif
    #ifdef ARB
        Diccionario2 dic;
    #endif

    BolsaLetras bolsa;
    ConjuntoLetras conjunto;
    IA ia;
    int num_letras = 0;
    char modo;
    bool fin_juego = false;
    char seguir_jugando;
    string palabra_usuario;
    int puntos_palabra;
    vector<char> letras_usuario;
    vector<string> soluciones_IA;

    if (argc < 5)
    {
        cout << "Formato: ./letras diccionario FicheroLetras numero_letras, modo(L -> longitud, P -> puntuacion)" << endl;
        return -1;
    }

    // Cargamos el diccionario en memoria
    ifstream f(argv[1]);
    f >> dic;

    // Cargamos el FicheroLetras
    conjunto.CargarFicheroLetras(argv[2]);

    // Creamos la bolsa de letras
    bolsa.CrearBolsa(conjunto);

    // Establecemos numero de letras
    num_letras = atoi(argv[3]);

    // Seleccionamos modo juego
    modo = *argv[4];
    assert(modo == 'L' || modo == 'l' || modo == 'P' || modo == 'p');

    // Contruimos la IA
    ia.setModoJuego(modo);

    if (modo == 'L' || modo == 'l')
        ia.CrearArbolLongitud(dic, num_letras);
    else
        ia.CrearArbolPuntuacion(dic, conjunto);

    // Bucle principal del juego
    while (!fin_juego)
    {
        // Sacamos 8 letras de la bolsa
        letras_usuario = bolsa.sacarLetras(num_letras);

        // Las mostramos por pantalla
        mostrarLetrasUsuario(letras_usuario);

        // Pedimos solucion al usuario
        cout << "Dime tu solución: ";
        cin >> palabra_usuario;

        // Calcular puntuacion palabra usuario
        if (modo == 'L' || modo == 'l')
            puntos_palabra = palabra_usuario.size();
        else
            puntos_palabra = conjunto.CalcularPuntosPalabra(palabra_usuario);

        // Mostrar su puntuacion al usuario
        mostrarPalabraUsuario(palabra_usuario, modo, conjunto);

        // Mostrar soluciones de la IA
        soluciones_IA = ia.ObtenerPalabras(letras_usuario);

        if (soluciones_IA.empty())
            cout << "Yo no he encontrado nada :(" << endl;
        else
        {
            cout << endl
                 << "Mis soluciones son: " << endl;

            mostrarPalabrasIA(soluciones_IA, modo, conjunto);
        }

        cout << "Seguir jugando [s/n]" << endl;
        cin >> seguir_jugando;

        if (seguir_jugando == 'n')
            fin_juego = true;
    }

    return 0;
}
