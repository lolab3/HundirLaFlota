#include <fstream>
#include "Jugador.h"

void Jugador::setTipus()
{}


void Jugador::afegeixVaixell(int fila, int columna, int longitud, int direccio)
{
		int i, j;
		i = fila - 1;
		j = columna - 1;

		m_taulerPropi[i][j] = 1;
		if (direccio == 0) //vertical
		{
			for (int k = 1; k < longitud; k++)
			{
				m_taulerPropi[i][j + 1] = 1;
				j++;
			}
		}
		else //horitzontal
		{
			for (int l = 1; l < longitud; l++)
			{
				m_taulerPropi[i + 1][j] = 1;
				i++;
			}
		}

		m_llistaVaixells[m_nVaixellsVius].setFila(fila);
		m_llistaVaixells[m_nVaixellsVius].setColumna(columna);
		m_llistaVaixells[m_nVaixellsVius].setLongitud(longitud);
		m_llistaVaixells[m_nVaixellsVius].setDireccio(direccio);

		
		for (int a = 0; a < m_llistaVaixells[m_nVaixellsVius].getLongitud(); a++)
		{
			m_llistaVaixells[m_nVaixellsVius].setEstat(a, true);
		}

		m_nVaixellsVius++;


		//////////////////////////////////////////////////////////////////
	
}



int Jugador::getNVaixellsVius() const
{
	return m_nVaixellsVius;
}


int Jugador::consultaAtacEnemic(int fila, int columna)
{
	int a=0,i=0;
	bool trobat=false;
	while ((!trobat) && (i < 10))
	{
		if (m_llistaVaixells[i].getDireccio() == 0)
		{
			for (int x = 0; x < m_llistaVaixells[i].getLongitud(); x++)
			{
				if ((m_llistaVaixells[i].getFila() == fila + 1) && (m_llistaVaixells[i].getColumna() + x == columna + 1))
				{
					a = m_llistaVaixells[i].registraAtac(fila, m_llistaVaixells[i].getColumna() + x);
					trobat = true;

					if ((m_llistaVaixells[i].getEstat(0) == false) && (m_llistaVaixells[i].getEstat(1) == false) && (m_llistaVaixells[i].getEstat(2) == false) && (m_llistaVaixells[i].getEstat(3) == false))
					{
						a = 2;
						m_nVaixellsVius--;
					}
				}
			}
			
		}
		if (m_llistaVaixells[i].getDireccio() == 1)
		{
			for (int x = 0; x < m_llistaVaixells[i].getLongitud(); x++)
			{
				if ((m_llistaVaixells[i].getColumna() == columna + 1) && (m_llistaVaixells[i].getFila() + x == fila + 1))
				{
					a = m_llistaVaixells[i].registraAtac(m_llistaVaixells[i].getFila() + x, columna);
					trobat = true;

					if ((m_llistaVaixells[i].getEstat(0) == false) && (m_llistaVaixells[i].getEstat(1) == false) && (m_llistaVaixells[i].getEstat(2) == false) && (m_llistaVaixells[i].getEstat(3) == false))
					{
						a = 2;
						m_nVaixellsVius--;
					}
				}
			}

			
		}
		i++;
	}
	//while trobar if direccio for longitud 
	//si la fila y columna toca barco, registra ataque
	//si la array de estados es todo 0 hundido
	return a;

}


void Jugador::registraResultatAtac(int fila, int columna, int resultat)
{
	m_taulerContrari[fila][columna] = resultat;
}


void Jugador::generaPosicioAtac(int& fila, int& columna)
{
	int x, y;
	x = 0 + (rand() % (9 - 0 + 1));


	y = 0 + (rand() % (9 - 0 + 1));

	while (m_taulerContrari[x][y] != 0)
	{
		x = 0 + (rand() % (9 - 0 + 1));
		y = 0 + (rand() % (9 - 0 + 1));
	}

	fila = x;
	columna = y;
}

