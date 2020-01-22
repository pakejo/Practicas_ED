#include <iostream>
#include <fstream>
#include "diccionario.h"

/*Recorre la lista de información asociada a una clave y la imprime*/
void EscribeSigni(const list<string> &l)
{
	list<string>::const_iterator it_s;

	for (it_s = l.begin(); it_s != l.end(); ++it_s)
	{
		cout << *it_s << endl;
	}
}

/**Lee un diccioario e imprime datos asociados a una clave. 
 * Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese fichero se escribe: 
 * ./usodiccionario < data.txt 
*/

int main(int argc, const char *argv[])
{
	Diccionario<string, string> D;

	if (argc < 2)
	{
		cout << "Falta diccionario" << endl;
		exit(-1);
	}

	ifstream f(argv[1]);

	if (!f)
	{
		cout << "Error al abrir el archivo" << endl;
		exit(-1);
	}

	f >> D;

	cout << D;

	string a;

	cout << "Introduce una palabra" << endl;
	cin >> a;

	list<string> l = D.getInfo_Asoc(a);

	if (l.size() > 0)
		EscribeSigni(l);

	cout << endl
		 << "-------------------------------------" << endl
		 << "Insertamos una nueva palabra\n"
		 << "Naranja: Fruto del naranjo." << endl;

	string clave("Naranja");
	string data("Fruto del naranjo.");
	list<string> info;
	info.push_back(data);

	D.Insertar(clave, info);

	cout << "Mostrando dicccionario" << endl;
	cout << D;

	cout << endl
		 << "-------------------------------------" << endl
		 << "Añadimos un nuevo significado a naranja: Colorante o pigmento utilizado para producir el color naranja." << endl;

	const string nuevo("Colorante o pigmento utilizado para producir el color naranja.");
	D.AddSignificado_Palabra(nuevo, clave);
	cout << D;

	cout << "----------------------------------" << endl
		 << "Prueba de borrado de un elemento y borrado por rango" << endl
		 << "Borramos el primer elemento y los dos ultimos. Solo queda la palabra naranja" << endl;

	Diccionario<string, string> D2(D);

	D2.erase(D2.begin());
	D2.erase(D2.begin()+1, D2.end());

	cout << "Resultado: " << endl
		 << D2;

	cout << "----------------------------------" << endl
		 << "Prueba de busqueda de significado" << endl
		 << "Significado a buscar: Colorante o pigmento utilizado para producir el color naranja." << endl;
	
	Diccionario<string,string>::const_iterator it = D.buscaSignificado(nuevo);

	cout << "La palabra es: " <<(*it).clave <<endl;

	cout << "----------------------------------" << endl
		<< "Buscamos en que entradas del diccionario aparece una palabra aleatoria" <<endl
		<< "Palabra: lenguaje" <<endl;
	
	Diccionario<string,string> D3 = D.buscaPalabra("lenguaje");
	cout << D3;
}
