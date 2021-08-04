#include <iostream>
using namespace std;


class Vaixells
{
public:
	Vaixells() {}
	~Vaixells() {}
	int registraAtac(int fila, int columna);

	void setFila(int fila) { m_fila = fila; }
	void setColumna(int columna) { m_columna = columna; }
	void setLongitud(int longitud) { m_longitud = longitud; }
	void setDireccio(int direccio) { m_direccio = direccio; }
	void setEstat(int i, bool estat) { m_estat[i] = estat; }

	int getFila() { return m_fila; }
	int getColumna() { return m_columna; }
	int getLongitud() { return m_longitud; }
	int getDireccio() { return m_direccio; }
	int getEstat(int i) { return m_estat[i]; }

private:
	static const int MAX_CASELLES = 4;
	bool m_estat[MAX_CASELLES];
	int m_fila;
	int m_columna;
	int m_direccio;
	int m_longitud;
	int m_nCasellesVives;
};
