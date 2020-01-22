/**
 * @file : guiatlf.h
 * @brief: TDA guia de telefonos
 * */

#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <map>
#include <iostream>
#include <string>

using namespace std;

/**
 * 
 * @brief T.D.A. Guia_Tlf
 * Una instancia @e c del tipo de datos abstracto @c Guia_Tlf es un objeto
 * formado por una colección de pares {(e11,e21),(e12,e22),(e13,e23),...,(e1n-1,e2n-1)}
 * ordenados por la el primer elemento del par denominado clave o key. No existen
 * elementos repetidos.
 * 
 * @author Francisco Ruiz Adán
 * @date 31/10/2019
 */

class Guia_Tlf
{
	/**
	 * @page repGuia_Tlf Rep del TDA Guia_Tlf
	 * 
	 * @section invGuia_Tlf Invariante de la representación
	 * 
	 * El invariante es \e para todo \e i y \e j tal que i<j entonces \e e1i y e1j son distintos
	 * 
	 * @section faGuia_Tlf Función de abstracción
	 * 
	 * Un objeto válido @e rep del TDA Guia_Tlf representa al valor
	 * 
	 * {(rep.begin().first,rep.begin().second),(rep.begin()+1.first,rep.begin()+1.second),....,(rep.begin()+n-1.first,rep.begin()+n-1.second)}
	 * 
	 */
private:
	map<string, string> datos;

public:

	/*----------------Constructores----------------*/

	/**
	 * @brief Constructor por defecto
	 */
	Guia_Tlf() {}

	/**
	 * @brief Constructor con parametros
	 * @param name titular del número
	 * @param tlf número de tlf.
	 */
	Guia_Tlf(string name, string tlf);

	/**
	 * @brief Constructor con parametros
	 * @param l initializer_list
	 */
	Guia_Tlf(std::initializer_list<map<string, string>::value_type> l);


	/*----------------Funciones Miembro----------------*/

	/**
	 * @brief  Numero de telefonos 
	 * @return el numero de telefonos asociados
	 */
	int size() const;

	/**
	 * @brief Comprueba si la guía está vacía
	 * @return true si la guía está vacía,
	 * false en caso contrario
	 */
	bool empty();

	/**
	 * @brief Limpia la guia
	 */
	void clear();

	/**
	 * @brief Obtiene el tlf de un nombre
	 * @param nombre clave a buscar
	 * @return tlf asociado a ese nombre
	 */
	string getTelefono(const string &nombre);

	/**
	 * @brief Insert un nuevo telefono 
	 * @param nombre: nombre clave del nuevo telefono
	 * @param tlf: numero de telefono
	 * @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o 
	 * o false en caso contrario
	 **/
	pair<map<string, string>::iterator, bool> insert(string nombre, string tlf);

	/**
	 * @brief Inserta un nuevo telefono 
	 * @param p: pair con el nombre y el telefono asociado
	 * @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o 
	 * o false en caso contrario
	 */
	pair<map<string, string>::iterator, bool> insert(pair<string, string> p);

	/**
	 * @brief Borrar un telefono
	 * @param nombre: nombre que se quiere borrar
	 */
	void borrar(const string &nombre);

	/**
	 * @brief Borrar un telefono
	 * @param nombre: nombre que se quiere borrar
	 * @param tlf telefono asociado a ese nombre
	 * @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
	 */
	void borrar(const string &nombre, const string &tlf);

	/**
	 * @brief  Obtiene una guia con los nombre previos a uno dado
	 * @param nombre: nombre delimitador
	 * @param tlf: telefono asociado a nombre
	 * @return nueva guia sin nombres mayores que \a  nombre
	 */
	Guia_Tlf previos(const string &nombre, const string &tlf);

	/**
	 * @brief Extrae un nuevo diccionario del actual
	 * @param min: valor minimo del nuevo diccionario
	 * @param max: valor máximo del nuevo diccionario
	 * @return nueva guia comenzando en min y acabando en max
	 */
	Guia_Tlf substract(const string &min, const string &max);

	/**
	 * @brief  Obtiene una guia con los nombre posteriores a uno dado
	 * @param nombre: nombre delimitador
	 * @param tlf: telefono asociado a nombre
	 * @return nueva guia sin nombres menores que \a  nombre
	 */
	Guia_Tlf posteriores(const string &nombre, const string &tlf);

	/**
	 * @brief Intercambia el contenido de dos guias
	 * @param g2 guia con la que intercambiar el contenido
	 */
	void swap(Guia_Tlf &g2);

	/**
	 * @brief Devuelve el nombre al que está asociado un número
	 * @param num: numero de teléfono
	 * @return titular del numero o string vacío si no existe
	 */
	string buscar_titular(const string num);

	/*----------------Operadores----------------*/

	/**
	 * @brief Operador de asignacion
	 * @param otra: guia a copiar
	 * @return devuelve una referenca a this
	 */
	Guia_Tlf &operator=(const Guia_Tlf &otra);

	/**
	 * @brief Acceso a un elemento
	 * @param nombre: nombre del elemento  elemento acceder
	 * @return devuelve el valor asociado a un nombre, es decir el teléfono
	 */
	string &operator[](const string &nombre);

	/**
	 * @brief Union de guias de telefonos
	 * @param g: guia que se une
	 * @return: una nueva guia resultado de unir el objeto al que apunta this y g
	 */
	Guia_Tlf operator+(const Guia_Tlf &g);

	/**
	 * @brief Diferencia de guias de telefonos
	 * @param g: guia a restar
	 * @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
	 */
	Guia_Tlf operator-(const Guia_Tlf &g);

	/**
	 * @brief Escritura de la guia de telefonos
	 * @param os: flujo de salida. Es MODIFICADO
	 * @param g: guia de telefonos que se escribe
	 * @return el flujo de salida
	 */
	friend ostream &operator<<(ostream &os, Guia_Tlf &g);

	/**
	 * @brief Lectura de  la guia de telefonos
	 * @param is: flujo de entrada. ES MODIFICADO
	 * @param g: guia de telefonos. ES MODIFICADO
	 * @return el flujo de entrada
	 */
	friend istream &operator>>(istream &is, Guia_Tlf &g);

	/*----------------Iterador----------------*/

	/**
	 * @brief clase para iterar sobre la guia
	 */
	class iterator
	{
	private:
		map<string, string>::iterator it;

	public:
		/**
		 * @brief Operador de asignacion
		 * @param it iterador a copiar
		 * @return referencia al objeto con el contenido de it
		 * @post El iterador queda modificado
		 */
		iterator &operator=(const iterator &it);

		/**
		 * @brief Sobrecarga del oeprador ++
		 * @return Iterador al siguiente objeto
		 */
		iterator &operator++();

		/**
		 * @brief Sobrecarga operador --
		 * @return Iterador al anterior objeto a iterar
		 */
		iterator &operator--();

		/**
		 * @brief Sobrecarga del operador *
		 * @return pareja de strings. El primer elemento es el usuario.
		 * El segundo elemento es el número de teléfono
		 */
		pair<const string, string> &operator*();

		/**
		 * @brief Sobrecarga del operador ==
		 * @param i iterador a comparar
		 * @return True si el contenido del iterador es igual al de 
		 * i. False en caso contrario
		 */
		bool operator==(const iterator &i);

		/**
		 * @brief Sobrecarga del operador !=
		 * @param i iterador a comparar
		 * @return True si el contenido del iterador es distinto al de
		 * i. False en caso contrario
		 */
		bool operator!=(const iterator &i);

		friend class Guia_Tlf;
	};

	/**
	 * @brief Inicializa un iterator al comienzo de la guia
	 */
	iterator begin();

	/**
	 * @brief Inicializa un iterator al final de la guia
	 */
	iterator end();
};
#endif
