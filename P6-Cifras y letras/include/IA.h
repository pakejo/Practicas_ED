
#ifndef _IA_H_
#define _IA_H_

#include <iostream>
#include <AG.h>
#include <Diccionario.h>
#include <Diccionario2.h>
#include <ConjuntoLetras.h>

using namespace std;

/**
  *  @brief T.D.A IA
  *
  * \b Definición:
  * Una instancia @e c del tipo de datos abstracto @c IA es un objeto
  * con tres campos: un @c ArbolGeneral de @c pair<string,int>, que representa
  * un diccionario, un @c ConjuntoLetras y un caracter que representa el medo de juego
  * 
  * Un objeto de la clase IA permite que el ordenador pueda competir contra el usuario
  * en los diferentes modos de juego. Dependiendo del diccionario usado, el nivel de 
  * dificultad de la IA será mayor o menor.
  * 
  * @author Francisco Ruiz Adán
  * @date Diciembre de 2019
  */
class IA
{
private:
    ArbolGeneral<pair<char, int>> tree;
    ConjuntoLetras conj;
    char modo_juego;

    /**
     * @brief Comprueba que una letra esta en el vector de letras
     * @param letra: letra a buscar
     * @param vec: vector sobre el que buscar la letra
     * @param pos: posicion de la letra en el vector
     * @return True si esa letra esta en el vecotr. False en caso contrario
     * @post Si la letra esta en el vector, pos sera modificado al acabar la funcion
     */
    bool estaLetraEnVector(char letra, vector<char> vec, int &pos);

    /**
     * @brief Comprueba si una palabra es valida
     * @param rama: nodo cuyos hijos forman la palabra
     * @param vec: vector con las letras
     * @param s: string con la palabra
     * @post s estara vacio si esa palabra no es valida. 
     * Si la palabra es valida s tendra esa palabra
     */
    void palabrasValidas(ArbolGeneral<pair<char, int>>::Nodo rama, vector<char> vec, string &s);

    /**
     * @brief Convierte una palabra a un arbol
     * @param p: string con la palabra
     * @param arb: rama a la que insertar la palabra
     */
    void CrearArbolPalabra(string &p, ArbolGeneral<pair<char, int>> &arb);

    /**
     * @brief Añade la palabra guardada en la rama a su respectiva posicion en el arbol
     * @param origen: arbol al que se van añadiendo todas las palabras
     * @param rama: arbol que contiene la palabra a insertar
     */
    void Insertar(ArbolGeneral<pair<char, int>> &origen, ArbolGeneral<pair<char, int>> &rama);

    /**
     * @brief Calcula los puntos de una palabra según el modo de juego
     * @param s : palabra cuyos puntos se quieren saber
     * @retun puntos de la palabra
     */
    int calcularPuntosPalabra(string s);

public:

    /**
     * @brief Contructor por defecto
     */
    IA();

    /**
     * @brief Constructor con parametros
     * @param modo : modo de juego;
     */
    void setModoJuego(char modo);

    /**
     * @brief Crea un arbol con las palabras del diccionario
     * con una longitud menor o igual a la pasada como porametro.
     * Esta funcion se usa para el modo longitud
     * @param D: diccionario (tipo Set) con las palabras
     * @param l: longitud maxima de las palabras
     */
    void CrearArbolLongitud(Diccionario D, int l);

    /**
     * @brief Crea un arbol con las palabras del diccionario
     * con una longitud menor o igual a la pasada como porametro.
     * Esta funcion se usa para el modo longitud
     * @param D: diccionario (tipo Arbol) con las palabras
     * @param l: longitud maxima de las palabras
     */
    void CrearArbolLongitud(Diccionario2 &D, int l);

    /**
     * @brief Crea un arbol con las palabras del diccionario con 
     * una puntuacion menor o igual a la pasada como parametro
     * Esta funcion se usa para el modo puntuacion
     * @param D: diccionario (tipo Set) con las palabras
     * @param P: lista con la puntuacion de cada letra
     */
    void CrearArbolPuntuacion(Diccionario D, ConjuntoLetras P);

    /**
     * @brief Crea un arbol con las palabras del diccionario con 
     * una puntuacion menor o igual a la pasada como parametro
     * Esta funcion se usa para el modo puntuacion
     * @param D: diccionario (tipo Arbol) con las palabras
     * @param P: lista con la puntuacion de cada letra
     */
    void CrearArbolPuntuacion(Diccionario2 &D, ConjuntoLetras P);
    
    /**
     * @brief Obtiene las soluciones dado un vector de letras
     * @param letras: vector de letras aleatorias para formar palabras
     * @return vector con las soluciones
     * @note El vector solución tendra las palabras que estén en el
     * diccionario y tengan las letras del vector. Si el usuario ve una
     * solucion, pero esta funcion no la muestra, es porque esa palabra
     * no está en el diccionario
     */
    vector<string> ObtenerPalabras(vector<char> letras);
};

#endif