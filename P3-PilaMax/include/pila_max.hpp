/**
  * @file pila_max.hpp
  * @brief Implementación del TDA pila_max
  */

/* _________________________________________________________________________ */
template <class T>
void PilaMax<T>::invertir_cola()
{
  int tam = this->pila.num_elementos();

  if (tam >= 1)
  {
    Elemento *v = new Elemento[tam];

    for (int i = 0; i < tam; i++)
    {
      v[i] = this->pila.frente();
      this->pila.quitar();
    }

    for (int i = tam - 1; i >= 0; i--)
      this->pila.poner(v[i]);
    
    delete [] v;
  }
}

/* _________________________________________________________________________ */
template <class T>
PilaMax<T>::PilaMax(T val)
{
  this->maximo_actual = val;
  Elemento nuevo(val,this->maximo_actual);
  this->pila.poner(nuevo);
}

/* _________________________________________________________________________ */
template <class T>
PilaMax<T>::PilaMax(const PilaMax &original)
{

  this->pila = original.pila;
  this->maximo_actual = original.maximo_actual;
}

/* _________________________________________________________________________ */
template <class T>
bool PilaMax<T>::empty()
{
  return this->pila.vacia();
}

/* _________________________________________________________________________ */
template <class T>
int PilaMax<T>::size() const
{
  return this->pila.num_elementos();
}

/* _________________________________________________________________________ */
template <class T>
typename PilaMax<T>::Elemento &PilaMax<T>::top()
{
  return this->pila.frente();
}

/* _________________________________________________________________________ */

template <class T>
const typename PilaMax<T>::Elemento &PilaMax<T>::top() const
{
  return this->pila.frente();
}

/* _________________________________________________________________________ */
template <class T>
void PilaMax<T>::push(T &nuevo)
{
  this->invertir_cola();

  if (nuevo > this->maximo_actual)
    this->maximo_actual = nuevo;

  Elemento nuevo_el(nuevo);
  nuevo_el.max = this->maximo_actual;

  this->pila.poner(nuevo_el);

  this->invertir_cola();
}

/* _________________________________________________________________________ */
template <class T>
void PilaMax<T>::pop()
{
  this->pila.quitar();

  if(!this->empty())
    this->maximo_actual = this->pila.frente().max;
  else
    this->maximo_actual = 0;
}

/* _________________________________________________________________________ */
template <class T>
void PilaMax<T>::swap(PilaMax<T> &otro)
{
  PilaMax<T> temp = otro;
  otro = this;
  this = otro;
}

/* _________________________________________________________________________ */
template <class T>
PilaMax<T> &PilaMax<T>::operator=(const PilaMax<T> &original)
{
  if (this != &original)
  {
    this->pila = original.pila;
    this->maximo_actual = original.maximo_actual;
  }

  return *this;
}