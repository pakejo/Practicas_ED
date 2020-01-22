
/*________________________________Funciones Auxiliares_________________________________*/
template <class T, class U>
void Diccionario<T, U>::Copiar(const Diccionario<T, U> &D)
{
	this->datos.assign(D.datos.begin(), D.datos.end());
}

template <class T, class U>
void Diccionario<T, U>::Borrar()
{
	this->datos.erase(datos.begin(), datos.end());
}

template <class T, class U>
void Diccionario<T, U>::Ordenar()
{
	this->datos.sort();
}

/*________________________________Constructores__________________________________________*/
template <class T, class U>
Diccionario<T, U>::Diccionario(const Diccionario<T, U> &D)
{
	Copiar(D);
}

/*________________________________Funciones Miembro________________________________________*/
template <class T, class U>
bool Diccionario<T, U>::Esta_Clave(const T &p, typename list<data>::iterator &it_out)
{

	if (datos.size() > 0)
	{

		typename list<data>::iterator it;

		for (it = datos.begin(); it != datos.end(); ++it)
		{
			if ((*it).clave == p)
			{
				it_out = it;
				return true;
			}
			else if ((*it).clave > p)
			{
				it_out = it;
				return false;
			}
		}

		it_out = it;
		return false;
	}
	else
	{
		it_out = datos.end();
		return false;
	}
}

template <class T, class U>
void Diccionario<T, U>::Insertar(const T &clave, const list<U> &info)
{

	typename list<data>::iterator it;

	if (!Esta_Clave(clave, it))
	{
		data p;
		p.clave = clave;
		p.info_asoci = info;

		datos.insert(it, p);

		this->Ordenar();
	}
}

template <class T, class U>
void Diccionario<T, U>::AddSignificado_Palabra(const U &s, const T &p)
{
	typename list<data>::iterator it;

	if (Esta_Clave(p, it))
		(*it).info_asoci.insert((*it).info_asoci.end(), s);
}

template <class T, class U>
list<U> Diccionario<T, U>::getInfo_Asoc(const T &p)
{
	typename list<data>::iterator it;

	if (!Esta_Clave(p, it))
	{
		return list<U>();
	}
	else
	{
		return (*it).info_asoci;
	}
}

template <class T, class U>
int Diccionario<T, U>::size() const
{
	return datos.size();
}

template <class T, class U>
bool Diccionario<T, U>::empty()
{
	return this->datos.empty();
}

template <class T, class U>
void Diccionario<T, U>::erase(typename Diccionario<T, U>::const_iterator position)
{
	typename list<Diccionario<T, U>::data>::const_iterator it = position.it;

	this->datos.erase(it);
}

template <class T, class U>
void Diccionario<T, U>::erase(typename Diccionario<T, U>::const_iterator first, typename Diccionario<T, U>::const_iterator last)
{
	typename list<Diccionario<T, U>::data>::const_iterator it_first, it_last;
	it_first = first.it;
	it_last = last.it;
	this->datos.erase(it_first, it_last);
}

template <class T, class U>
typename Diccionario<T, U>::const_iterator Diccionario<T, U>::buscaSignificado(const U &s)
{
	typename Diccionario<T, U>::const_iterator it, it_out;
	typename list<U>::iterator it2;
	bool encontrado = false;

	for (it = this->begin(); it != this->end() && !encontrado; ++it)
	{
		list<U> data = (*it).info_asoci;

		for (it2 = data.begin(); it2 != data.end() && !encontrado; ++it2)
		{
			if (*it2 == s)
			{
				it_out = it;
				encontrado = true;
			}
		}
	}

	return it_out;
}

template <class T, class U>
Diccionario<T, U> Diccionario<T, U>::buscaPalabra(const U &s)
{
	Diccionario<T, U> filtrado;
	typename list<data>::iterator it;
	typename list<U>::iterator it2;
	size_t found;

	for (it = datos.begin(); it != datos.end(); ++it)
	{
		for (it2 = (*it).info_asoci.begin(); it2 != (*it).info_asoci.end(); ++it2)
		{
			found = (*it2).find(s);

			if (found != string::npos)
				filtrado.Insertar((*it).clave, (*it).info_asoci);
		}
	}

	return filtrado;
}

/*________________________________Operadores________________________________________*/
template <class T, class U>
Diccionario<T, U> &Diccionario<T, U>::operator=(const Diccionario<T, U> &D)
{
	if (this != &D)
	{
		Borrar();
		Copiar(D);
	}
	return *this;
}

template <class T, class U>
Diccionario<T, U> Diccionario<T, U>::operator+(const Diccionario<T, U> &D)
{
	Diccionario dic(this);
	typename list<data>::iterator it, it2;

	for (it = D.datos.begin(); it != D.datos.end(); ++it)
	{
		// Si no hay un elemento con esa clave lo insertamos
		if (!Esta_Clave((*it).clave, it2))
			dic.Insertar((*it).clave, (*it).info_asoci);
	}

	return dic;
}

template <class T, class U>
bool Diccionario<T, U>::operator==(const Diccionario<T, U> &D)
{
	typename list<data>::iterator it, it2;

	if (this->size() == D.datos.size())
	{
		for (it = datos.begin(), it2 = D.datos.begin(); it != datos.end() && it2 != D.datos.end(); ++it, ++it2)
		{
			if ((*it).clave != (*it2).clave)
				return false;
		}

		return true;
	}
	else
		return false;
}

template <class T, class U>
bool Diccionario<T, U>::operator!=(const Diccionario<T, U> &D)
{
	return !(this == D);
}

template <class T, class U>
bool Diccionario<T, U>::operator<(const Diccionario<T, U> &D)
{
	return this->size() < D.size();
}

template <class T, class U>
bool Diccionario<T, U>::operator>(const Diccionario<T, U> &D)
{
	return this->size() > D.size();
}

/*________________________________Iterador________________________________________*/

template <class T, class U>
typename Diccionario<T, U>::const_iterator &Diccionario<T, U>::const_iterator::operator++()
{
	++this->it;
	return *this;
}

template <class T, class U>
typename Diccionario<T, U>::const_iterator &Diccionario<T, U>::const_iterator::operator--()
{
	--this->it;
	return *this;
}

template <class T, class U>
const typename Diccionario<T, U>::data &Diccionario<T, U>::const_iterator::operator*()
{
	return *(this->it);
}

template <class T, class U>
bool Diccionario<T, U>::const_iterator::operator==(const const_iterator &i)
{
	return this->it == i.it;
}

template <class T, class U>
bool Diccionario<T, U>::const_iterator::operator!=(const const_iterator &i)
{
	return this->it != i.it;
}

template <class T, class U>
typename Diccionario<T, U>::const_iterator &Diccionario<T, U>::const_iterator::operator=(const const_iterator &i)
{
	if (this != &i)
	{
		this->it = i.it;
	}

	return *this;
}

template <class T, class U>
typename Diccionario<T, U>::const_iterator &Diccionario<T, U>::const_iterator::operator+(int incremento)
{
	for (int i = 0; i < incremento; i++)
		it++;

	return *this;
}

template <class T, class U>
typename Diccionario<T, U>::const_iterator Diccionario<T, U>::begin()
{
	const_iterator iter;
	iter.it = datos.begin();
	return iter;
}

template <class T, class U>
typename Diccionario<T, U>::const_iterator Diccionario<T, U>::end()
{
	const_iterator iter;
	iter.it = datos.end();
	return iter;
}

template <class T, class U>
typename Diccionario<T, U>::const_iterator Diccionario<T, U>::begin() const
{
	const_iterator iter;
	iter.it = datos.begin();
	return iter;
}

template <class T, class U>
typename Diccionario<T, U>::const_iterator Diccionario<T, U>::end() const
{
	const_iterator iter;
	iter.it = datos.end();
	return iter;
}

/**
 * Operator >>. El formato de la entrada es:
 * numero de claves en la primera linea
 * clave-iésima retorno de carro
 * numero de informaciones asociadas en la siguiente linea
 * y en cada linea obviamente la informacion asociada
 */
istream &operator>>(istream &is, Diccionario<string, string> &D)
{
	int np;
	is >> np;
	is.ignore(); //quitamos \n
	Diccionario<string, string> Daux;
	for (int i = 0; i < np; i++)
	{
		string clave;

		getline(is, clave);

		int ns;
		is >> ns;
		is.ignore(); //quitamos \n
		list<string> laux;
		for (int j = 0; j < ns; j++)
		{
			string s;
			getline(is, s);

			// cout<<"Significado leido "<<s<<endl;
			laux.insert(laux.end(), s);
		}
		Daux.Insertar(clave, laux);
	}
	D = Daux;
	return is;
}

/**
 * Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre 
 * listas de listas y otro sobre listas
 */
ostream &operator<<(ostream &os, const Diccionario<string, string> &D)
{

	Diccionario<string, string>::const_iterator it;

	for (it = D.begin(); it != D.end(); ++it)
	{

		list<string>::const_iterator it_s;

		os << endl
		   << (*it).clave << endl
		   << " informacion asociada:" << endl;
		for (it_s = (*it).info_asoci.begin(); it_s != (*it).info_asoci.end(); ++it_s)
		{
			os << (*it_s) << endl;
		}
		os << "**************************************" << endl;
	}

	return os;
}