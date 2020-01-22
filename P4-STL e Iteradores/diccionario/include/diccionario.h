#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

/**
  *  @brief T.D.A Diccioanrio
  *
  * Una instancia @e c del tipo de datos abstracto @c Diccioanrio es un objeto
  * con un campo, una @c lista de @c data , formada por una clave y su informacion
  * asociada
  * La lista contendrá una serie de @c data ordenadas por la clave de cada una
  *
  * @author Francisco Ruiz Adán
  * @date 31/10/2019
  */
template <class T, class U>
class Diccionario
{
private:
	/**
    * @page repConjunto Rep del TDA Diccioanrio
    *
    * @section invConjunto Invariante de la representación
    *
    * No puede haber dos entradas con la misma clave
    *
    * @section faConjunto Función de abstracción
    *
    * Un objeto válido @e rep del TDA Diccionario con @e n tamaño representa al objeto
    *
    * 
    * rep[0].data#clave#rep[0].eventos[t-1]
    * rep[1].data#clave#rep[1].eventos[t-1]
    * rep[n-1].data#clave#rep[n-1].eventos[t-1]
    *
    */
	struct data
	{
		T clave;
		list<U> info_asoci;

		/**
		 * @brief Construcotor por defecto
		 */
		data() {}

		bool operator<(const data &d2)
		{
			bool resultado = (clave[0] < d2.clave[0]) ? true : false;
			return resultado;
		}
	};

	list<data> datos; //<diccionario>

	/**
	 * @brief Copia un diccionario a otro
	 * @param D diccionario desde el que se copia
	 */
	void Copiar(const Diccionario<T, U> &D);

	/**
	 * @brief Borra el diccionario
	 */
	void Borrar();

	/**
	 * @brief Ordena la lista
	 */
	void Ordenar();

public:
	/*______________________Constructores_____________________*/

	/**
	 * @brief Constructor por defecto
	 */
	Diccionario() : datos(list<data>()) {}

	/**
	 * @brief Constructor de copia
	 * @param D diccionario desde que que se copia
	 */
	Diccionario(const Diccionario &D);

	/*______________________Destructor_____________________*/

	/**
	 * @brief Destructor
	 */
	~Diccionario() {}

	/*______________________Funciones Miembro_____________________*/

	/** 
	 * @brief Busca la clave p en el diccionario. Si está devuelve un iterador a 
	 * dónde está clave. Si no está, devuelve end() y deja el iterador de salida
	 * apuntando al sitio dónde debería estar la clave
	 * @param p clave que se quiere buscar
	 * @param it_out iterador que guarda la posicion de la clave
	 * @return true si encuentra la clave, flase en caso contrario
	 */
	bool Esta_Clave(const T &p, typename list<data>::iterator &it_out);

	/**
	 * @brief Inserta un nuevo registro en el diccionario. Lo hace a través de la clave
	 * e inserta la lista con toda la información asociada a esa clave. Si el 
	 * diccionario no estuviera ordenado habría que usar la función sort()
	 * @param clave del registro
	 * @param info lista con la información de ese registro
	 */
	void Insertar(const T &clave, const list<U> &info);

	/**
	 * @brief Añade una nueva informacion asocida a una clave que está en el diccionario.
	 * la nueva información se inserta al final de la lista de información.
	 * Si no esta la clave la inserta y añade la informacion asociada. 
	 * @param s nueva información a añadir
	 * @param p clave a la que se añade la información
	 */
	void AddSignificado_Palabra(const U &s, const T &p);

	/**
	 * @brief Devuelve la información (una lista) asociada a una clave p.
	 * @param p clave de la que se obtiene información
	 * @return lista con la información de p
	 */
	list<U> getInfo_Asoc(const T &p);

	/**
	 * @brief Tamaño del diccionario
	 * @return Devuelve un entero con el tamaño del diccionario
	 */
	int size() const;

	/**
	 * @brief Comprueba que el diccionario esta vacío o no
	 * @return True si el diccionario está vacío, false en caso contrario
	 */
	bool empty();

	/**
	 * @brief Borra un elemento del diccionario
	 * @param position iterador en la posición del elemento a eliminar
	 */
	void erase(typename Diccionario<T, U>::const_iterator position);

	/**
	 * @brief Borra un rango de elementos del diccionario
	 * @param first principio del rango a borrar
	 * @param last final del rango a borrar
	 */
	void erase(typename Diccionario<T, U>::const_iterator first, typename Diccionario<T, U>::const_iterator last);

	/**
	 * @brief Busca a que clave pertenece una definición
	 * @param s string con la definicion
	 * @return Si la palabra está en el diccionario devuelve
	 * un iterador a esa palabra. En caso contrario devuelve
	 * un iterador a end().
	 */
	typename Diccionario<T, U>::const_iterator buscaSignificado(const U &s);

	/**
	 * @brief Busca aquellas claves en la que aparece la palabra
	 * pasada como argumento
	 * @param s información a buscar en el diccionario
	 * @return nuevo diccionario con las clave y su información, 
	 * en las que aparece s
	 */
	Diccionario<T, U> buscaPalabra(const U &s);

	/*______________________Operadores_____________________*/

	/**
	 * @brief Sobrecarga operador de asignacion
	 * @param D diccionario desde el que se copia
	 */
	Diccionario<T, U> &operator=(const Diccionario<T, U> &D);

	/**
	 * @brief Sobrecarga operador +
	 * @param D Diccionario a sumar
	 * @return Devuelve un diccionario suma de este y dic
	 */
	Diccionario<T, U> operator+(const Diccionario<T, U> &D);

	/**
	 * @brief Sobrecarga operador ==
	 * @param D Diccionario a comparar
	 * @return Devuelve true si el contenido de ambos
	 * diccionarios es igual, o false en caso contrario
	 */
	bool operator==(const Diccionario<T, U> &D);

	/**
	 * @brief Sobrecarga operador !=
	 * @param D Diccionario a comparar
	 * @return Devuelve true si el contenido de ambos
	 * diccionarios es igual, o false en caso contrario
	 */
	bool operator!=(const Diccionario<T, U> &D);

	/**
	 * @brief Sobrecarga operador <
	 * @param D diccionario a comparar
	 * @return Devuelve true si el tamaño del diccionario
	 * es menor al tamaño de D
	 */
	bool operator<(const Diccionario<T, U> &D);

	/**
	 * @brief Sobrecarga operador >
	 * @param D diccionario a comparar
	 * @return Devuelve true si el tamaño del diccionario
	 * es menor al tamaño de D
	 */
	bool operator>(const Diccionario<T, U> &D);

	/*______________________Iterador_____________________*/

	/**
	 * @brief T.D.A const_iterator
	 */
	class const_iterator
	{
	private:
		/**
		 * @page repConjunto Rep del TDA Diccionario<T,U>::const_iterator
		 * 
		 * @section invConjunto Invariante de la representación
		 * 
		 * El iterador debe apuntar a una posición válida del diccionario
		 * 
		 *  @section faConjunto Función de abstracción
		 * 
		 * Un objeto válido @e rep del TDA Diccionario<T,U>::const_iterator
		 * representa al objeto
		 * 
		 * rep.data#clave#rep[0].eventos[t-1]
		 * 
		 */
		typename list<Diccionario<T, U>::data>::const_iterator it;

	public:
		/**
		 * @brief Sobrecarga operador++
		 * El iterdaor apuntará a la siguiente posición del diccionario
		 */
		const_iterator &operator++();

		/**
		 * @brief Sobrecarga operador--
		 * El iterador apuntará a la posición anterior del diccionario
		 */
		const_iterator &operator--();

		/**
		 * @brief Sobrecarga del operador*
		 * Devuelve el contenido de la posición actual del iterador
		 */
		const Diccionario<T, U>::data &operator*();

		/**
		 * @brief Sobrecarga operador==
		 * Devuelve true si amobos iteradores apuntan al
		 * mismo elemento del diccionario, false en caso contrario
		 * 
		 * @param i iterador a comparar 
		 */
		bool operator==(const const_iterator &i);

		/**
		 * @brief Sobrecarga operador!=
		 * Devuelve false si amobos iteradores apuntan al
		 * mismo elemento del diccionario, true en caso contrario
		 * 
		 * @param i iterador a comparar
		 */
		bool operator!=(const const_iterator &i);

		/**
		 * @brief Sobrecarga operador de asignacion
		 * Copia el contenido de i a éste
		 * 
		 * @param i iterador a copiar
		 */
		const_iterator &operator=(const const_iterator &i);

		/**
		 * @brief Sobrecarga operador+
		 * Permite sumar al iterdor un entero de manera que
		 * este avanza incremento posiciones
		 * 
		 * @param incremento número de posiciones a avanzar el iterador
		 */
		const_iterator &operator+(int incremento);

		friend class Diccionario;
	};

	/**
	 * @brief Iterador al inicio del diccionario
	 */
	const_iterator begin();

	/**
	 * @brief Iterador al final del diccionario
	 */
	const_iterator end();

	/**
	 * @brief Iterador costante al inicio del diccionario
	 */
	const_iterator begin() const;

	/**
	 * @brief Iterador constante al final del diccionario
	 */
	const_iterator end() const;

	/*______________________Funciones Amigas_____________________*/

	friend ostream &operator<<(ostream &os, const Diccionario<string, string> &D);

	friend istream &operator>>(istream &is, Diccionario<string, string> &D);
};

#include "diccionario.hpp"

#endif
