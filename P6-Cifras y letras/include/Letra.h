#ifndef _LETRA_H_
#define _LETRA_H_

using namespace std;

/**
  *  @brief T.D.A. Letra
  *
  * \b Definición:
  * Una instancia @e c del tipo de datos abstracto @c Letra es un objeto
  * con tres campos, un caracter que representa la letra a guardar, un entero
  * que guardará la frecuencia de aparición en un diccionario y otro entero que 
  * serán los puntos correspondientes a esa letra
  * 
  * @author Francisco Ruiz Adán
  * @date Diciembre de 2019
  */
class Letra
{
private:
    char letra;
    int frecuencia;
    int puntos;

public:

    /**
     * @brief Contruye una letra vacia
     */
    Letra();

    /**
     * @brief Contruye una letra 
     * @param letra: caracter de la letra
     * @param frec: frecuencia de la letra
     * @param puntos: puntos de la letra
     */
    Letra(char letra, int frec, int puntos);

    /**
     * @brief Establece la letra que representa el objeto
     * @param letra: caracter de la letra a guardar
     */
    void setLetra(char letra);

    /**
     * @brief Establece la frecuencia de apariciones de la letra
     * @param frec frecuencia de aparición de la letra
     */
    void setFrec(int frec);

    /**
     * @brief Establece la puntuación de la letra
     * @param puntos: puntuación de la letra
     */
    void setPuntos(int puntos);

    /**
     * @brief Devuelve la letra del objeto
     * @return caracter con la letra
     */
    char getLetra() const;

    /**
     * @brief Devuelve la frecuencia de la letra
     * @return frecuencia de la letra
     */
    int getFrecuencia() const;

    /**
     * @brief Devuelve los puntos de la letra
     * @return Puntución de la letra
     */
    int getPuntos() const;

    /**
     * @brief Sobrecarga del operador <
     * @param l: letra a comparar
     * @return True si el caracter es
     * alfabeticamente anterior al de l.
     * False en caso contrario
     */
    bool operator<(const Letra &l) const;
};

#endif