//Llibreria grafica
#include "lib/libreria.h"

class Pantalla
{
public:
	Pantalla() {}
	~Pantalla() {}
	void visualitza();
	void setPosicioPropi(int fila, int columna, int estat);
	void setPosicioContrari(int fila, int columna, int estat);
	void getPosicio(int x, int y, int& fila, int&columna, int& tauler);	int getValor(int i, int j) { return m_taulerMio[i][j]; }
	
private:
	static const int N_FILES = 10;
	static const int N_COLUMNES = 10;
	int m_taulerMio[N_FILES][N_COLUMNES];
	int m_taulerContrari[N_FILES][N_COLUMNES];
	Sprite m_vaixell;
	Sprite m_tauler;
	Sprite m_aigua;
	Sprite m_tocat;
	Sprite m_enfonsat;

};

