/**
  * @file FechaHistorica.h
  * @brief Fichero cabecera del TDA FechaHistorica
  *
  */

#ifndef _FECHAHISTORICA_
#define _FECHAHISTORICA_

#include "vector_dinamico.h"
#include <string>
#include <iostream>

using namespace std;

  /**
    * @brief T.D.A. Fecha Historica
    * 
    * Una instancia @e c del TDA @c Fecha_Historica es un objeto
    * que almacena acontecimientos ocurridos a lo largo de un año.
    * Está compuesto por un valor entero que representa el año y
    * un vector de string para representar los diferentes acontecimientos
    * Lo representamos:
    * fecha#evento#evento...
    *
    * @author Francisco Ruiz Adán
    * @date 17/10/2019
    */

class FechaHistorica
{
private:
  /**
    * @page repConjunto Rep del TDA Fecha_Historica
    *
    * @section invConjunto Invariante de la representación
    *
    * Para fechas anteriores al año 0 se utilizarán enteros negativos
    * Cada evento debe incluir # como primer caracter
    *
    * @section faConjunto Función de abstracción
    *
    * Un objeto válido @e rep del TDA Fecha_Historica representa al objeto
    *
    * rep.fecha#rep.eventos[0]#rep.eventos[n-1]
    */
  int fecha;                      /**< año en el que ocurrieron los eventos */
  VectorDinamico<string> sucesos; /**< vector de eventos */
  int n_elementos;

public:
  // ---------------  Constructores ----------------
  /**
    * @brief Constructor por defecto
    * @return Crea uuna fecha con año 0 y sin hechos
    */
  FechaHistorica();

  /**
    * @brief Constructor con un parámetro de la clase. El usuario puede crear una fecha indicando solo el año.
    * @param y año del evento a construir
    * @return Crea el evento con los datos de y, el vector de eventos quedará vacío
    */
  FechaHistorica(int year);

  /**
    *
    * @brief Constructor copia
    * @param f FechaHistorica que se quiere copiar
    * @return Crea el objeto con los datos de f
    */
  FechaHistorica(const FechaHistorica &f);

  // ---------------  Otras funciones ----------------

  /**
     * @brief Método de acceso al año de la FechaHistorica
     * @return int con el valor del campo year
     */
  int getFecha() const;

  /**
    * @brief Método de acceso a la cantidad de eventos almacenados en el vector dinámico
    * @return int con el número de eventos almacenados en el vector dinámico
    */
  int getNumSucesos() const;

  /**
    * @brief Método que devuelve los acontecimientos
    * @return vector<string> con los hechos
    */
  VectorDinamico<string> getSucesos();

  /**
    * @brief Modifica el año
    * @param x año de los eventos a construir
    */
  void setYear(int x);

  /**
    * @brief Añade un evento
    * @param suceso string con evento a añadir
    */
  void addSuceso(string suceso);

  /**
    * @brief Consulta si existe un evento
    * @param s evento que se desea saber si está
    * @return bool con verdadero si está, false si no se existe
    */
  bool existeSuceso(string suceso) const;

  /**
    * @brief Sobrecarga del operador =. Permite igualar una fecha a otra
    * @param nuevo FechaHistorica a la que se quiere igualar
    */
  FechaHistorica &operator=(const FechaHistorica &nuevo);

  /**
    * @brief Sobrecarga del operador +. Permite sumar dos fechas
    * @param f FechaHistorica que se quiere sumar
    */
  FechaHistorica operator+(FechaHistorica f);

  /**
    *@brief Sobrecarga del operador <<
    *@param os Flujo al que queremos volcar nuestra cronología
    *@param c Cronología que queremos volcar
    */
  friend ostream &operator<<(ostream &os, const FechaHistorica &f);

  /**
    *@brief Sobrecarga del operador >>. Comprueba si hay saltos de línea vacíos en el fichero para evitar que lo tome como una fecha.
    *@param is Flujo del que queremos cargar la cronología
    *@param c Cronología donde queremos cargar el Flujo
    */
  friend istream &operator>>(istream &is, FechaHistorica &f);
};
#endif