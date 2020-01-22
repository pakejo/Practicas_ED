
#ifndef _DICCIONARIO_H_
#define _DICCIONARIO_H_

#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
  * @brief T.D.A. Diccionario
  *
  * \b Definición:
  * Una instancia @e c del tipo de datos abstracto @c Diccioanrio es un objeto
  * con un campo, un @c set de @c string, representando una palabra del diccionario
  * 
  * La lista contendrá una serie de @c string ordenados
  *
  * @author Francisco Ruiz Adán
  * @date Diciembre de 2019
  */
class Diccionario
{
private:
    set<string> datos;

public:
    /**
     * @brief Construye un diccionario vacío
     */
    Diccionario();

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
    friend istream &operator>>(istream &is, Diccionario &D);

    /**
     * @brief Escribe en un flujo de salida un diccionario
     * @param os: flujo de salida
     * @param D: el objeto diccionario que se escribe
     * @return el flujo de salida
     */
    friend ostream &operator<<(ostream &os, Diccionario &D);

    /**
     * @brief Clase iterador del diccionario
     */
    class iterator
    {
    private:
        set<string>::const_iterator it;

    public:
        iterator();
        string operator*();
        iterator &operator++();
        iterator &operator=(iterator &i);
        bool operator==(const iterator &i);
        bool operator!=(const iterator &i);
        friend class Diccionario;
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