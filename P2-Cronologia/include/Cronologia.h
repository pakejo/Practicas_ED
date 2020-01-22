/**
  * @file cronologia.h
  * @brief Fichero cabecera del TDA cronologia
  *
  */

#ifndef _CRONOLOGIA_
#define _CRONOLOGIA_

#include "FechaHistorica.h"
#include <sstream>

using namespace std;

/**
  *  @brief T.D.A Cronologia
  *
  * Una instancia @e c del tipo de datos abstracto @c Cronologia es un objeto
  * con un campo, un @c VectorDinamico de @c FechaHistorica
  * El vector contendrá una serie de @c FechaHistorica ordenadas por el
  * año de cada una
  *
  * @author Francisco Ruiz Adán
  * @date 17/10/2019
  */

class Cronologia
{
private:
  /**
    * @page repConjunto Rep del TDA Cronologia
    *
    * @section invConjunto Invariante de la representación
    *
    * Para fechas anteriores al año 0 se utilizarán enteros negativos
    * Cada evento debe incluir # como primer caracter
    * No puede haber dos fechas históricas con el mismo año
    *
    * @section faConjunto Función de abstracción
    *
    * Un objeto válido @e rep del TDA Cronologia con @e n tamaño representa al objeto
    *
    * 
    * rep[0].fecha#rep[0].eventos[0]#rep[0].eventos[t-1]
    * rep[1].fecha#rep[1].eventos[0]#rep[1].eventos[t-1]
    * rep[n-1].fecha#rep[n-1].eventos[0]#rep[n-1].eventos[t-1]
    *
    */
  VectorDinamico<FechaHistorica> cronologia; /**< Lista de fechas historicas */

  /**
     * @brief Ordenad la cronologia cuando se añade una fecha
     */
  inline void ordenar();

  /**
     * @brief Busca una fecha en el vector
     * @return Indice de la fecha en el vector
     */
  inline int buscar(int x);

public:
  // ---------------  Constructores ----------------
  /**
     * @brief Constructor por defecto. Crea una cronologia vacía
     * @return Crea una cronologia sin eventos
     */
  Cronologia();

  /**
     * @brief Constructor de copia de la clase
     * @param original cronologia que se qiere copiar
     * @return crea el objeto con los datos de original
     */
  Cronologia(const Cronologia &original);

  // ---------------  Otras funciones ----------------
  /**
     * @brief Tamaño de la cronologia
     * @return Número de fechas guardadas en la cronologia
     */
  int size() const;

  /**
     * @brief Obtiene la información de una fecha dado su año
     * @param i año en el que ocurren los eventos
     * @return fecha historica con año @c i
     * Si no se encuentra una fecha con ese año se devuelve una 
     * fecha historica vacia con año i
     */
  FechaHistorica getFecha(int i);

  /**
     * @brief Obtiene la información de una fecha segun su indice
     * @param i indice en el vector
     * @return fecha historica con indice @c i
     * Si no se encuentra una fecha con ese año se devuelve una 
     * fecha historica vacia con año i
     * @pre i debe ser mayor que 0
     */
  FechaHistorica getIndex(int i);

  /**
     * @brief Sobreescribe una fecha
     * @param f es la nueva FechaHistorica a sobreescribir
     * @post si f no existe en la cronologia no se hace nada
     */
  void setFecha(FechaHistorica f);

  /**
     * @brief Añade una nueva fecha a la cronologia
     * @param f nueva fecha a añadir
     * @post si f ya existe no se añade
     */
  void add(FechaHistorica f);

  /**
     * @brief Obtiene los eventos que ocurrieron un año
     * @param i añosen el que ocurrierons los eventos
     * @return vector<string> con los eventos de esa fecha
     * @post si no existe la fecha i devuelve un vector vacío
     */
  VectorDinamico<string> getEventosFecha(int i);

  /**
     * @brief Obtiene una nueva cronologia con las fechas cuyos
     * años están entre x e y
     * @param x fecha mínima de búsqueda
     * @param y fecha máxima de búsqueda
     * @return Nueva cronologia con las fechas entre x e y
     */
  Cronologia getEventosEntre(int x, int y);

  /**
     * @brief Busca la fecha en la que ocurrio un evento
     * @param s evento cualquiera
     * @return año en el que sucedió el evento o -1 si no existe
     */
  int buscarEvento(string s);

  /**
     * @brief Filtra la cronologia por una palabra
     * @param s palabra a filtrar
     * @return nueva cronologia con las fechas cuyos eventos
     * contiene esa palabra
     */
  Cronologia filtrarPalabra(string& s);

  // ---------------  Operadores ----------------
  /**
     * @brief Sobrecarga operador = Permite igualar
     * una cronologia a otra
     * @param c cronologia a igualar
     */
  Cronologia &operator=(const Cronologia &c);

  /**
     * @brief Sobrecarga operador + Permite sumar dos cronologias
     * @param c cronologia a sumar
     * @return nueva cronologia resultado de la suma de esta cronologia
     * y la pasada como parametro
     */
  Cronologia operator+(Cronologia c);

  /**
    *@brief Sobrecarga del operador <<
    *@param os Flujo al que queremos volcar nuestra cronología
    *@param c Cronología que queremos volcar
    */

  friend ostream &operator<<(ostream &os, const Cronologia &c);

  /**
    *@brief Sobrecarga del operador >>. Comprueba si hay saltos de línea vacíos en el fichero para evitar que lo tome como una fecha.
    *@param is Flujo del que queremos cargar la cronología
    *@param c Cronología donde queremos cargar el Flujo
    */
  friend istream &operator>>(istream &is, Cronologia &c);
};

#endif