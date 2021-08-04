#include "Vaixells.h"
#include <iostream>
using namespace std;


class Jugador
{
public:
	Jugador() {}
	~Jugador() {}
	void setTipus();
	void afegeixVaixell(int fila, int columna, int longitud, int direccio);
	int getNVaixellsVius() const;
	int consultaAtacEnemic(int fila, int columna);
	void registraResultatAtac(int fila, int columna, int resultat);
	void generaPosicioAtac(int& fila, int& columna);
	void setValor(int fila, int columna, int valor) { m_taulerPropi[fila][columna] = valor; }
	int getValor(int fila, int columna) { return m_taulerPropi[fila][columna]; }
	int getValorEnemic(int fila, int columna) { return m_taulerContrari[fila][columna]; }
	int getTipus() { return m_tipusJugador; }

private:
	static const int N_FILES = 10;
	static const int N_COLUMNES = 10;
	static const int N_VAIXELLS = 10;
	Vaixells m_llistaVaixells[N_VAIXELLS];
	int m_taulerContrari[N_FILES][N_COLUMNES];
	int m_nVaixellsVius;
	bool m_tipusJugador;
	int m_taulerPropi[N_FILES][N_COLUMNES];
};
