
#ifndef _BOLSA_LETRAS_H_
#define _BOLSA_LETRAS_H_

#include <algorithm>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ConjuntoLetras.h>

using namespace std;

/**
 * @brief T.D.A. BolsaLetras
 * 
 * \b Definición:
 * Una instancia \e a del tipo de dato abstracto BolsaLetras se puede construir como
 * una lista de letras repetidas n veces cada una y ordenado aleatoriamente.
 * 
 * @author Francisco Ruiz Adán
 * @date Diciembre de 2019
*/
class BolsaLetras
{
private:
    vector<char> bolsa;

    /**
     * @brief Añade la letra a la bolsa tantas
     * veces como su frecuencia
     * @param l: letra a añadir
     */
    void addLetra(Letra l);

public:

    /**
     * @brief Crea una bolsa de letras vacía
     */
    BolsaLetras();

    /**
     * @brief Crea una bolsa de letras a partir
     * de un conjuto de letras específico
     * @param conjunto: conjunto de letras
     */
    BolsaLetras(ConjuntoLetras conjunto);

    /**
     * @brief Crea una bolsa de letras a partir
     * de un conjuto de letras específico
     * @param conjunto: conjunto de letras
     */
    void CrearBolsa(ConjuntoLetras conjunto);

    /**
     * @brief Obtiene un número de letras de la bolsa
     * @param n: número de letras a sacar de la bolsa
     * @return vector de tamaño n con las letras.
     * Su contenido es aleatorio 
     */
    vector<char> sacarLetras(int n);
};

#endif