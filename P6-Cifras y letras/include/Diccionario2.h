
#ifndef _DICCIONARIO_2_H_
#define _DICCIONARIO_2_H_

#include <Diccionario.h>
#include <AG.h>
#include <string>
#include <iostream>

/**
 * @brief T.D.A. Diccionario2
 * 
 * \b Definición:
 * Una instancia @e c del tipo de datos abstracto @c Diccioanrio2 es un objeto
 * con un campo, un @c ArbolGeneral de @c pair<string,int>, una letra y un valor
 * 
 * Esta clase permite cargar un diccionario en memoria utilizan un árbol
 * 
 * @author Francisco Ruiz Adán
 * @date Diciembre de 2019
 */
class Diccionario2
{
private:
    typedef typename std::pair<string, int> tBase;

    ArbolGeneral<tBase> arbol;
    int n_elementos;

    string reconstruirPalabra(ArbolGeneral<tBase>::Nodo n2);
    void Insertar(ArbolGeneral<tBase> &origen, ArbolGeneral<tBase> &rama);
    void CrearArbolPalabra(string &p, ArbolGeneral<tBase> &arb);

public:
    /**
     * @brief Construye un diccionario vacío
     */
    Diccionario2();

    /**
     * Devuelve el numero de palabras en el diccionario
     */
    int size() const;

    /**
     * @brief Obtiene todas las palabras en el diccionario de longitud dada
     * @param longitud: la longitud de las palabras de salida
     * @return un vector con las palabras de longitud específica en el parámetro de entrada
     */
    vector<string> PalabrasLongitud(unsigned int longitud);

    /**
     * @brief Indica si una palabra esta en el dicccionario
     * @param palabra: la palabra que se quiere buscar
     * @return true si la palabra está en el diccionario. False en caso contrario
     */
    bool Esta(string palabra);

    /**
     * @brief Lee un flujo de entrada un diccionario
     * @param is: flujo de entrada
     * @param D: el objeto donde se realiza la lectura
     * @return fljo de entrada
     */
    friend istream &operator>>(istream &is, Diccionario2 &D);

    /**
     * @brief Escribe en un flujo de salida un diccionario
     * @param os: flujo de salida
     * @param D: el objeto diccionario que se escribe
     * @return el flujo de salida
     */
    friend ostream &operator<<(ostream &os, Diccionario2 &D);

    /**
     * @brief Clase iterador del diccionario
     */
    class iterator
    {
    private:
        Diccionario2 *dic;
        ArbolGeneral<pair<string, int>>::Nodo n2;

    public:
        iterator();
        string operator*();
        iterator &operator++();
        iterator &operator=(iterator &i);
        bool operator==(const iterator &i);
        bool operator!=(const iterator &i);
        friend class Diccionario2;
    };

    /**
     * @brief Iterador al inicio del diccionario
     * @return Iterador al inicio del diccionario
     */
    iterator begin();

    /**
     * @brief Iterador al final del diccionario
     * @return Iterador al final del diccionario
     */
    iterator end();
};

#endif