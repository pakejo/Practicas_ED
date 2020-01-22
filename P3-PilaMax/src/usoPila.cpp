#include <iostream>
#include <pila_max.h>

using namespace std;

int main(int argc, char *argv[])
{
    PilaMax<int> pila;
    int n = 0, val = 0;

    cout << "Indique tamaño de la pila" << endl;
    cin >> n;

    cout << "Introduzca los valores" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        pila.push(val);
    }

    cout << "\n" <<"Contenido de la pila:" <<"\n";

    while (!pila.empty())
    {
        cout << pila.top().val << " max: " << pila.top().max << endl;
        pila.pop();
    }
    
}
