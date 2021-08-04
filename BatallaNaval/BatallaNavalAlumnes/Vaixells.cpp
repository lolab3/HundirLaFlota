#include "Vaixells.h"


int Vaixells::registraAtac(int fila, int columna)
{
	int x=0;
	if (m_direccio == 0)
	{
		m_estat[columna - m_columna] = false;
		x = 1;
	}
	if (m_direccio == 1)
	{
		m_estat[fila - m_fila] = false;
		x = 1;
	}
	return x;
}