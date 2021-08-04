#include "Partida.h"
#include <fstream>
#include <iostream>
using namespace std;

void Partida::inicialitza(const string& fitxer12, const string& fitxer21)
{
	ifstream fitxer;
	fitxer.open(fitxer12);

	if (fitxer.is_open())
	{
		int fila;
		int columna;
		int longitud;
		int direccio;
		
		fitxer >> fila;
		fitxer >> columna;
		fitxer >> longitud;
		fitxer >> direccio;

		while (!fitxer.eof())
		{
			m_jugador1.afegeixVaixell(fila,columna,longitud,direccio);
			fitxer >> fila;
			fitxer >> columna;
			fitxer >> longitud;
			fitxer >> direccio;
		}
		fitxer.close();
	}

	

	
	///////////////////////////////////////////////////////////////

	ifstream fitxer1;
	fitxer1.open(fitxer21);


	if (fitxer1.is_open())
	{
		int fila;
		int columna;
		int longitud;
		int direccio;

		fitxer1 >> fila;
		fitxer1 >> columna;
		fitxer1 >> longitud;
		fitxer1 >> direccio;

		while (!fitxer1.eof())
		{
			m_jugador2.afegeixVaixell(fila, columna, longitud, direccio);
			fitxer1 >> fila;
			fitxer1 >> columna;
			fitxer1 >> longitud;
			fitxer1 >> direccio;
		}
		fitxer1.close();
	}

}



void Partida::guarda(const string& fitxer13, const string& fitxer22)
{
	ofstream fitxer3;
	fitxer3.open(fitxer13);
	for (int f = 0; f < N_FILES; f++)
	{
		for (int c = 0; c < N_COLUMNES; c++)
		{

			fitxer3 << m_jugador1.getValor(f, c) << " ";
		}
	}
	fitxer3.close();


	cout << endl << endl;


	//Afegir un nou fitxer
	ofstream fitxer2;
	fitxer2.open(fitxer22);
	for (int f = 0; f < N_FILES; f++)
	{
		for (int c = 0; c < N_COLUMNES; c++)
		{

			fitxer2 << m_jugador2.getValor(f, c) << " ";
		}
	}
	fitxer2.close();




	m_tauler1.visualitza();
}


void Partida::visualitza()
{
	//visualizar parte maquina
	Sprite vaixell("data/vaixell.png");
	Sprite aigua("data/aigua.png");
	Sprite enfonsat("data/enfonsat.png");
	Sprite tocat("data/tocat.png");

	for (int f = 0; f < N_FILES; f++)
	{
		for (int c = 0; c < N_COLUMNES; c++)
		{
			if ((m_jugador1.getValor(f, c)) == 1)
			{
				vaixell.draw(c * 52, f * 52);
			}
			if ((m_jugador1.getValor(f, c)) == 0)
			{
				aigua.draw(c * 52, f * 52);
			}

		}
	}


	for (int f = 0; f < N_FILES; f++)
	{
		for (int c = 0; c < N_COLUMNES; c++)
		{
			if ((m_jugador1.getValorEnemic(f, c)) == 1)
			{
				aigua.draw(572 + c * 52, f * 52);
			}
			if ((m_jugador1.getValorEnemic(f, c)) == 2)
			{
				tocat.draw(572 + c * 52, f * 52);
			}
			if ((m_jugador1.getValorEnemic(f, c)) == 3)
			{
				enfonsat.draw(572 + c * 52, f * 52);
			}
			if ((m_jugador2.getValorEnemic(f, c)) == 2)
			{
				tocat.draw(c * 52, f * 52);
			}
			if ((m_jugador2.getValorEnemic(f, c)) == 3)
			{
				enfonsat.draw(c * 52, f * 52);
			}
		}
	}


}

bool Partida::moviment(int x, int y)
{
	// consulta atac enemig i registra resultat atac(registrar en jugador i pantalla) acabar maquina
	bool verificar=false;
	int n;
	if (m_torn == 1)
	{
		cout << endl;
		cout << "Torn jugador huma: " << endl;
		if ((y >= 0) && (y <= 572))
		{
			cout << "Moviment incorrecte" << endl;
		}
		else
		{
			int s, r;
			s = x / 52;
			r = (y - 572) / 52;
			if (n = m_jugador2.consultaAtacEnemic(s, r) == 0)
			{
				m_jugador1.registraResultatAtac(s, r, 1);
				m_tauler1.setPosicioContrari(s, r, 1);
				cout << "Has tocat aigua" << endl;
				verificar = false;
			}
			else
			{
				if (n = m_jugador2.consultaAtacEnemic(s, r) == 1)
				{
					m_jugador1.registraResultatAtac(s, r, 2);
					m_tauler1.setPosicioContrari(s, r, 2);
					cout << "Has tocat vaixell" << endl;
					verificar = true;
				}
				else
				{
					if (n = m_jugador2.consultaAtacEnemic(s, r) == 2)
					{
						m_jugador1.registraResultatAtac(s, r, 3);
						m_tauler1.setPosicioContrari(s, r, 3);
						cout << "Has enfonsat el vaixell" << endl;
						verificar = true;
					}
				}
			}
		}
	}
	
	else
	{
		cout << endl;
		cout << "Torn jugador maquina: " << endl;

		m_jugador2.generaPosicioAtac(x, y);
		int a = x;
		int d = y;
		if (n = m_jugador1.consultaAtacEnemic(a, d) == 0)
		{
			m_jugador2.registraResultatAtac(a, d, 1);
			cout << "Ha tocat aigua" << endl;
			cout << endl;
			verificar = false;

		}
		else
		{
			if (n = m_jugador1.consultaAtacEnemic(a, d) == 1)
			{
				m_jugador2.registraResultatAtac(a, d, 2);
				m_tauler1.setPosicioPropi(a, d, 2);
				m_jugador1.setValor(a, d, 2);

				cout << "Ha tocat vaixell" << endl;
				verificar = true;

			}
			else
			{
				if (n = m_jugador1.consultaAtacEnemic(a, d) == 2)
				{
					m_jugador2.registraResultatAtac(a, d, 3);
					m_tauler1.setPosicioPropi(a, d, 3);
					m_jugador1.setValor(a, d, 3);

					cout << "Ha enfonsat el vaixell" << endl;
					verificar = true;

				}
			}


		}
	}

	return verificar;
}


bool Partida::finalPartida()
{
	bool final = false;
	if (m_jugador1.getNVaixellsVius() == 0)
	{
		cout << "Has guanyat" << endl;
		final = true;
	}

	if (m_jugador2.getNVaixellsVius() == 0)
	{
		cout << "Maquina guanyadora" << endl;
		final = true;
	}
	return final;
}

