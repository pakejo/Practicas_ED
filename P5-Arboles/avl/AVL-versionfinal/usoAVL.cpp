#include <iostream>
#include "AVL.hpp"
using namespace std;

void intersecta(AVL<int> &a, AVL<int> &b, AVL<int> &ret)
{
  AVL<int>::iterator it;

  // Solo hay que añadir aquellos elementos comunes a los dos
  for (it = b.begin(); it != b.end(); ++it)
  {
    if (a.existe(*it))
      ret.insertar(*it);
  }
}

int main()
{
  AVL<int> avl1;
  AVL<int> avl2;
  AVL<int> inter;
  AVL<int>::iterator it;
  int e;

  cout << "INSERCIÓN DE DATOS AVL 1" << endl;

  cout << "Introduce un entero (<0 para terminar) ";
  cin >> e;
  while (e >= 0)
  {
    avl1.insertar(e);
    for (it = avl1.begin(); it != avl1.end(); ++it)
      cout << *it << " ";
    cout << endl;
    avl1.Esquema();

    cout << "Introduce un entero (<0 para terminar) ";
    cin >> e;
  }

  cout << "INSERCIÓN DE DATOS AVL 2" << endl;

  cout << "Introduce un entero (<0 para terminar) ";
  cin >> e;
  while (e >= 0)
  {
    avl2.insertar(e);
    for (it = avl2.begin(); it != avl2.end(); ++it)
      cout << *it << " ";
    cout << endl;
    avl2.Esquema();

    cout << "Introduce un entero (<0 para terminar) ";
    cin >> e;
  }

  cout <<"\nInterseccion: " <<endl;

  intersecta(avl1,avl2,inter);
  inter.Esquema();


  //  const int N = 50;
  //  const float max = 100.0;
  //  srand(time(NULL));
  //  for(int i=0; i<N; i++)
  //    avl.insertar((int) (max*rand()/RAND_MAX));
  //
  //
  //  for(it = avl.begin(); it!=avl.end(); ++it)
  //    cout << *it << " ";
  //  cout << endl;
  //
  //  avl.Esquema();
  /*
  cout << "BÚSQUEDA DE DATOS" << endl;
  cout << "Introduce un entero (< 0 para terminar) ";
  cin >> e;
  while (e >= 0)
  {
    cout << e << (avl.existe(e) ? " SÍ" : " NO") << " está en el AVL" << endl;
    cout << "Introduce un entero (< 0 para terminar) ";
    cin >> e;
  }

  avl.Esquema();
  cout << "BORRADO DE DATOS" << endl;
  cout << "Introduce un entero (< 0 para terminar) ";
  cin >> e;
  while (e >= 0)
  {
    avl.borrar(e);
    for (it = avl.begin(); it != avl.end(); ++it)
      cout << *it << " ";
    cout << endl;
    avl.Esquema();

    cout << "Introduce un entero (< 0 para terminar) ";
    cin >> e;
  }*/

  return 0;
}
