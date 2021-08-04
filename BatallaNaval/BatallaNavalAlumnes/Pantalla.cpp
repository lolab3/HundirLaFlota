#include <fstream>
#include "Pantalla.h"
using namespace std;
#include <iostream>

void Pantalla::visualitza()
{
		ifstream fitxer4;
		string primero = "tauler_huma.txt";
		fitxer4.open(primero);

		cout << "Mi tabla:" << endl;
		if (fitxer4.is_open())
		{
			int numero;
			fitxer4 >> numero;

			while (!fitxer4.eof())
			{
				for (int f = 0; f < N_FILES; f++)
				{
					for (int c = 0; c < N_COLUMNES; c++)
					{

						m_taulerMio[f][c] = numero;
						cout << m_taulerMio[f][c] << " ";
						fitxer4 >> numero;
					}
					cout << endl;
				}
				
			}
			fitxer4.close();
		}

		cout << "Tabla Rival:" << endl;
		for (int f = 0; f < N_FILES; f++)
		{
			for (int c = 0; c < N_COLUMNES; c++)
			{

				cout << m_taulerContrari[f][c] << " ";
			}
			cout << endl;
		}

}


void Pantalla::setPosicioPropi(int fila, int columna, int estat)
{
	m_taulerMio[fila][columna] = estat;
}


void Pantalla::setPosicioContrari(int fila, int columna, int estat)
{
	m_taulerContrari[fila][columna] = estat;
}


void Pantalla::getPosicio(int x, int y, int& fila, int&columna, int& tauler)
{}