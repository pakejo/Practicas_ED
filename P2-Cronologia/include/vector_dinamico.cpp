/**
  * @file vectordinamico.cpp
  * @brief Implementaci�n del TDA VectorDin�mico
  *
  */
#include <cassert>
#include "vector_dinamico.h"
/* _________________________________________________________________________ */

template <class T>
VectorDinamico<T>::VectorDinamico(int n)
{
  assert(n >= 0);
  if (n > 0)
    datos = new T[n];
  nelementos = n;
}
/* _________________________________________________________________________ */

template <class T>
VectorDinamico<T>::VectorDinamico(const VectorDinamico<T> &original)
{
  nelementos = original.nelementos;
  if (nelementos > 0)
  {
    datos = new T[nelementos];
    for (int i = 0; i < nelementos; ++i)
      datos[i] = original.datos[i];
  }
  else
    datos = 0;
}
/* _________________________________________________________________________ */

template <class T>
VectorDinamico<T>::~VectorDinamico()
{
  if (nelementos > 0)
    delete[] this->datos;
}
/* _________________________________________________________________________ */

template <class T>
int VectorDinamico<T>::size() const
{
  return nelementos;
}
/* _________________________________________________________________________ */

template <class T>
T &VectorDinamico<T>::operator[](int i)
{

  assert(0 <= i && i < nelementos);
  return datos[i];
}
/* _________________________________________________________________________ */

template <class T>
const T &VectorDinamico<T>::operator[](int i) const
{
  assert(0 <= i && i < nelementos);
  return datos[i];
}
/* _________________________________________________________________________ */

template <class T>
void VectorDinamico<T>::resize(int n)
{
  assert(n >= 0);
  if (n != nelementos)
  {
    if (n != 0)
    {
      T *nuevos_datos;
      nuevos_datos = new T[n];
      if (nelementos > 0)
      {
        int minimo;
        minimo = nelementos < n ? nelementos : n;
        for (int i = 0; i < minimo; ++i)
          nuevos_datos[i] = datos[i];
        delete[] datos;
      }
      nelementos = n;
      datos = nuevos_datos;
    }
    else
    {
      if (nelementos > 0)
        delete[] datos;
      datos = 0;
      nelementos = 0;
    }
  }
}
/* _________________________________________________________________________ */

template <class T>
VectorDinamico<T> &VectorDinamico<T>::operator=(const VectorDinamico<T> &original)
{
  if (this != &original)
  {
    if (nelementos > 0)
      delete[] datos;
    nelementos = original.nelementos;
    datos = new T[nelementos];
    for (int i = 0; i < nelementos; ++i)
      datos[i] = original.datos[i];
  }
  return *this;
}
/* _________________________________________________________________________ */

template <class T>
void VectorDinamico<T>::push_back(T &s)
{
  this->resize(this->nelementos + 1);
  this->datos[this->nelementos - 1] = s;
}