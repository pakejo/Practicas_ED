/**
  * @file PilaMax.h
  * @brief Fichero cabecera del TDA PilaMax
  */

#ifndef _PilaMax_
#define _PilaMax_

#include <cola.h>

using namespace std;

/**
 *  @brief T.D.A. Pila_Max
 *
 *
 * Una instancia @e c del tipo de dato abstracto PilaMax sobre un dominio @e T es
 * una sucesión finita de elementos del mismo con un funcionamiento @e LIFO
 * (Last In, First Out}). En una PilaMax, las operaciones de inserción tienen
 * lugar en uno de los extremos, denominado @e tope de la pila, mientras que
 * el borrado y consulta se lleva a cabo también en ese @e tope.
 * Además, en este caso guardaremos junto a cada elemento el valor máximo de la
 * pila hasta ese punto, denominado máximo
 * Una pila de longitud @e n la denotamos

 * - <a1:[a1,m],a2:[a2,m],a3:[a3,m],..,an:[an,m]<

 * En esta pila, tendremos acceso únicamente al elemento del @e tope,
 * es decir, a @e a1. El borrado o consulta de un elemento será sobre @e a1,
 * la inserción de un nuevo elemento se hará antes de
 * @e a1 (principio de la pila).
 *
 * Si n=0 diremos que la pila está vacía.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el número 
 * de elementos de la cola.
 *
 * @author Francisco Ruiz Adán
 * @date 18/10/2019
*/

template <class T>
class PilaMax
{
private:
    struct Elemento
    {
        T val;
        T max;

        /**
         * @brief Costructor pordefecto
         */
        Elemento() : val(0), max(0){}

        /**
         * @brief Costructor con parámetros
         * @param val Elemento de información
         * @param max Elemento maximo de la pila
         */
        Elemento(const T v) : val(v), max(0){}
    };

    Cola<Elemento> pila; ///< Cola con la información
    T maximo_actual;    ///< valor máximo de la pila

    /**
     * @brief Invierte la cola. En una cola se inserta por el
     * final y se accede por el frente, mientras que en un pila
     * se inserta y accede por el frente. Por esto, debemos invertir la cola
     * a la hora de guardar los elementos
     */
    void invertir_cola();

public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    PilaMax() : maximo_actual(0){}
    
    /**
     * @brief Constructor con parámetros
     */
    PilaMax(T val);

    /**
     * @brief Constructor de copia
     * @param original Pila de la que se hará la copia
     */
    PilaMax(const PilaMax<T>& original);

    // ---------------  Otras Funciones ----------------

    /**
     * @brief Comprueba si la pila está vacía
     */
    bool empty();

    /**
     * @brief Número de elementos de la pila
     */
    int size() const;

    /**
     * @brief Obtiene el tope de la pila
     * @return Valor del tope
     */
    Elemento& top();

    /**
     * @brief Obtiene el tope de la pila constante
     * @return Valor del tope
     */
    const Elemento& top() const;

    /**
     * @brief Añade un nuevo elemento al tope
     * @param nuevo Valor a añdir en el tope
     */
    void push(T &nuevo);

    /**
     * @brief Borra el tope de la pila
     */
    void pop();

    /**
     * @brief Intercambia el contenido de esta pila
     * y la pasada como argumento
     * @param otro pila con la que intercambiar el contenido
     * @post Ambas pilas quedan modiciadas
     */
    void swap(PilaMax<T> &otro);

    // ---------------  Operadores ----------------

    /**
     * @brief Oprador de asignacioón 
     * @param original la pila que se va asignar
     */
    PilaMax& operator=(const PilaMax<T>& original);

};

#include <pila_max.hpp>

#endif