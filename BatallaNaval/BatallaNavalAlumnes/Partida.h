#include "Jugador.h"
#include "Pantalla.h"

class Partida
{
public:
	Partida() {}
	~Partida() {}
	void inicialitza(const string& fitxer1, const string& fitxer2);
	void guarda(const string& fitxer1, const string& fitxer2);
	void visualitza();
	bool moviment(int x, int y);
	bool finalPartida();
	void setTorn(int valor) { m_torn = valor; }
	int getTorn() { return m_torn; }

private:
	static const int N_FILES = 10;
	static const int N_COLUMNES = 10;
	Pantalla m_tauler1;
	Jugador m_jugador1;
	Jugador m_jugador2;
	int m_torn;
};
