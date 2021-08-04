#include "Partida.h"
#include "joc.h"
#include <time.h>
#include <math.h>

//-----------------------------------------
// joc: porta el control de tot el joc
//-----------------------------------------
void joc(bool modeGrafic)
{
	
	//Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
	Screen pantalla(MIDA_X, MIDA_Y);

	//Mostrem la finestra grafica
	
	if (modeGrafic == true)
		pantalla.show();

	Sprite vaixell("data/vaixell.png");
	Sprite caselles("data/caselles.png");
	// ********************************************
	// AFEGIR CODI: Crear tots els grafics del joc
	//				Inicialitzar variables posicio vaixell
	string test1 = "vaixells_jugador_huma.txt";
	string test2 = "vaixells_jugador_ordinador.txt";

	Partida P;
	P.inicialitza(test1,test2);

	string tauler_jugador = "tauler_huma.txt";
	string tauler_jugador2 = "tauler_ordinador.txt";

	P.guarda(tauler_jugador, tauler_jugador2);
	P.setTorn(1);


	// ********************************************
	int x = 0, y = 0;
	
	do
	{
		// Captura tots els events de ratolí i teclat de l'ultim cicle
		pantalla.processEvents();

		

			// *****************************************************************************
			// AFEGIR CODI:	Capturar si s'ha fet clic amb el ratolí
			//				Si s'ha fet clic amb el ratolí modificar posició (fila i columna del tauler) 
			//				del vaixell en funció de la posició del ratolí
			// *****************************************************************************
		if (P.getTorn() == 1)
		{
			if (Mouse_getButLeft())
			{
				int columna = Mouse_getX();
				int fila = Mouse_getY();


				if (P.getTorn() == 1)
					if (P.moviment(fila, columna) == false)
					{
						P.setTorn(0);
						P.guarda(tauler_jugador, tauler_jugador2);
					}
					else
					{

						P.guarda(tauler_jugador, tauler_jugador2);
					}


			}
		}
		else
		{

			int x = 0, y = 0;
			if (P.getTorn() == 0)
				if (P.moviment(x, y) == false)
				{
					P.setTorn(1);
					P.guarda(tauler_jugador, tauler_jugador2);
				}
				else
				{

					P.guarda(tauler_jugador, tauler_jugador2);
				}
		}


		caselles.draw(0, 0);
		caselles.draw(572, 0);

			// *****************************************************************************
			// AFEGIR CODI: Redibuixar tauler 
			//				Dibuixar el vaixell a la posició (fila i columna) que toqui						
			// *****************************************************************************
		P.visualitza();


			// Actualitza la pantalla
		pantalla.update();

	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));
		// Sortim del bucle si pressionem ESC
		
	

}
