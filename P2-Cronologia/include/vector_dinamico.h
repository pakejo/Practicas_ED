/**
  * @file vectordinamico.h
  * @brief Fichero cabecera del TDA Vector Dinamico
  *
  * Se crea un vector con capacidad de crecer y decrecer
  * 
  */
#ifndef _VectorDinamico_
#define _VectorDinamico_

using namespace std;

/**
 *  @brief T.D.A. VectorDinamico
 *
 *
 * Una instancia @e v del tipo de datos abstracto @c VectorDinamico sobre el
 * tipo @c T es un array 1-dimensional de un determinado tamaño @e n, que
 * puede crecer y decrecer a petici�n del usuario. Lo podemos representar como
 *
 *  {v[0],v[1],...,v[n-1]} 
 *
 * donde  v[i] es el valor almacenado en la posición  i del vector
 *
 * La eficiencia en espacio es @e O(n).
 *
 */
template <class T>
class VectorDinamico
{
private:
  /**
       * @page repVectorDinamico Rep del TDA VectorDinamico
       *
       * @section invVectorDinamico Invariante de la representación
       *
       * Un objeto válido @e v del TDA VectorDinamico debe cumplir 
       * - @c v.nelementos>= 0 
       * - @c v.datos apunta a una zona de memoria con capacidad para albergar
       *   @c nelementos valores de tipo @c T
       *
       * @section faVectorDinamico  Función de abstracción
       *
       * Un objeto vólido @e rep del TDA VectorDinamico representa al vector de
       * tamaño @e n
       *
       * {v.datos[0],v.datos[1],...,v.datos[v.nelementos-1]}
       *
    */
  T *datos;       /**< Apunta a los elementos del vector */
  int nelementos; /**< Indica el número de elementos en @c datos */

public:
  // ---------------  Constructores ----------------
  /**
     * @brief Constructor por defecto
     * @param n indica el número de componentes inicial reservados
     *          para el vector
     * @note
     *   Este constructor también corresponde al de por defecto
     */
  VectorDinamico(int n = 0);
  VectorDinamico(const VectorDinamico<T> &original);
  // ------------------ Destructor ------------------
  ~VectorDinamico();
  // --------------- Otras funciones ---------------
  /**
     * @brief Número de componentes del vector
     * @return Devuelve el número de componentes que puede almacenar en este
     * instante el vector
     * @see resize()
     */
  int size() const;
  /**
     * @brief Acceso a un elemento
     * @param i la posición del vector donde está el componente. 0<=i<size()
     * @return La referencia al elemento. Por tanto, se puede usar para almacenar
     *     un valor en esa posición.
     */
  T &operator[](int i);
  /**
     * @brief Acceso a un elemento de un vector constante
     * @param i la posición del vector donde está el componente. 0<=i<size()
     * @return La referencia al elemento. Se supone que el vector no se puede
        modificar y por tanto es acceso de sólo lectura
     */
  const T &operator[](int i) const;
  /**
     * @brief Redimensión del vector
     * @param n El nuevo tamaño del vector. n>=0
     * @post Los valores almacenados antes de la redimensión no se pierden
     *  (excepto los que se salen del nuevo rango de índices)
     */
  void resize(int n);

  /**
   * @brief Añade un elemento al final del vector
   * @param s El nuevo valor a añadir
   */
  void push_back(T &s);

  /**
   * @brief Sobrecarga del operador de asignacion
   * @param original Vector desde el que se quiere copiar
   */
  VectorDinamico<T> &operator=(const VectorDinamico<T> &original);
};

#include "vector_dinamico.cpp"

#endif /* _vectorDinamico_h */
