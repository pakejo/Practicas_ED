#include "guiatlf.h"
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Dime el nombre del fichero con la guia" << endl;
		return 0;
	}
	ifstream f(argv[1]);
	if (!f)
	{
		cout << "No puedo abrir el fichero " << argv[1] << endl;
		return 0;
	}

	Guia_Tlf g = {
		{"Contacto 1", "123456789"},
		{"Contacto 2", "987654321"}};

	f >> g;
	cout << "La guia insertada " << g << endl;
	cin.clear();
	cout << "Dime un nombre sobre el que quieres obtener el telefono" << endl;
	string n;
	while (getline(cin, n))
	{
		cout << "Buscando " << n << "...." << endl;
		string tlf = g.getTelefono(n);
		if (tlf == "")
		{
			cout << "No existe ese nombre en la guia" << endl;
		}
		else
			cout << "El telefono es " << tlf << endl;
		cout << "[Pulse CTRL+D para finalizar] Dime un nombre sobre el que quieres obtener el telefono" << endl;
	}
	cin.clear();

	cin.clear();
	cout << "Dime el nombre que quieres borrar" << endl;

	while (getline(cin, n))
	{
		g.borrar(n);
		cout << "Ahora la guia es:" << endl;
		cout << g << endl;
		cout << "[Pulse CTRL+D para finalizar] Dime el nombre que quieres borrar" << endl;
	}

	cin.clear();
	Guia_Tlf otraguia;
	string nombre;
	cout << "Introduce otra guia ([Pulse CTRL+D para finalizar])" << endl;
	cin >> nombre;
	ifstream f2(nombre);
	f2 >> otraguia;
	cin.clear();
	Guia_Tlf un = g + otraguia;
	Guia_Tlf dif = g - otraguia;
	cout << endl
		 << "La union de las dos guias: " << un << endl;

	cout << endl
		 << "La diferencia de las dos guias:" << dif << endl;

	cout << endl
		 << "Dime un nombre para establecer los previos" << endl;
	cin >> n;
	string tlf = g.getTelefono(n);
	Guia_Tlf p = g.previos(n, tlf);
	cout << endl
		 << "Los nombre previos: " << p << endl;

	cout << "Listando la guia con iteradores:" << endl;
	Guia_Tlf::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		cout << (*it).first << '\t' << (*it).second << endl;

	cin.clear();
	getline(cin, n);
	string min, max;
	cout << endl
		 << "Extraemos una guia de otra" << endl
		 << "Introduzca el nombre a usar como minimo de la guia1" << endl;
	getline(cin, min);

	cin.clear();
	cout << "Introduzca el nombre a usar como máximo" << endl;
	getline(cin, max);

	Guia_Tlf sub = g.substract(min, max);

	cout << "La nueva guia es:" << endl
		 << sub << endl;

	cout << "Intercambiamos el contenido de dos guias: guia1 y la anterior" << endl;
	g.swap(sub);

	cout << "La guia1 ahora es:" << endl
		 << g << endl
		 << "La otra guia seria: " << endl
		 << sub << endl;

	cout << "Introduzca numero cuyo titular desea saber" << endl;
	string nom;

	cin.clear();

	while (getline(cin, n))
	{
		nom = sub.buscar_titular(n);
		cout << nom << endl;
		cout << "Introduce otro número ([Pulse CTRL+D para finalizar])" << endl;
	}
}
