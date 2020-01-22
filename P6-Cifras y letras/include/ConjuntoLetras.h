
#ifndef _CONJUNTO_LETRAS_H_
#define _CONJUNTO_LETRAS_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <Letra.h>

using namespace std;

/**
 * @brief T.D.A. ConjuntoLetras
 * 
 * \b Definición:
 * Una instancia \e a del tipo de dato abstracto ConjuntoLetras se puede construir como
 * un vector de @c Letra.
 * 
 * Un objeto ConjuntoLetras se usará para crear el archivo "ficheroLetras" con la frecuencia
 * y puntos de cada letra. Además, tambien permite leer archivos del tipo "ficheroLetras"   
 * 
 * @author Francisco Ruiz Adán
 * @date Diciembre de 2019
*/
class ConjuntoLetras
{
private:
    vector<Letra> conjunto;
    
public:
    /**
     * @brief Crea un conjunto letras vacío.
     */
    ConjuntoLetras();

    /**
     * @brief Carga un fichero de letras ordenado en memoria 
     * @param filename nombre del fichero de litras
     */
    void CargarFicheroLetras(const char *filename);

    /**
     * @brief Calcula los puntos de una palabra
     * @param palabra: palabra cuyos puntos se quieren saber
     * @return puntos de esa palabra
     */
    int CalcularPuntosPalabra(string palabra);

    /**
     * @brief Comprueba si el conjunto de letras está vacío
     * @return True si está vacío. False en caso contrario
     */
    bool empty();

    /**
     * @brief Clase iterador del conjunto
     */
    class iterator
    {
    private:
        vector<Letra>::const_iterator it;

    public:
        iterator();
        Letra operator*();
        iterator &operator++();
        iterator &operator=(const iterator &i);
        bool operator==(const iterator &i);
        bool operator!=(const iterator &i);
        friend class ConjuntoLetras;
    };

    /**
     * @brief Devuelve un iterador al inicio del conjunto de letras
     * @return Iterador al inicio del conjunto
     */
    iterator begin();

    /**
     * @brief Devuelve un iterador al final del conjunto de letras
     * @return Iterador al final del conjunto
     */
    iterator end();
};

#endif