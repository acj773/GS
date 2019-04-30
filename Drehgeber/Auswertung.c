#include "Auswertung.h"






int16_t alterWinkel = 0;
uint8_t eineSekunde;


/*
Die Funktion berechnet den Drehwinkel. Ueberschreitet der Winkel 360 Grad, dann beginnt der Winkel wieder von 0.
Es werden auch negative Winkel berechnet. z.B -345 Grad.

@param counter Der Zaehlerstand des Drehgebers.
@param winkel  Hier wird der neu berechnete Winkel gespeichert.

@return error  1 ist Fehler. 0 ist kein Fehler
*/

int8_t berechne_Winkel(int16_t counter, int16_t* winkel)
{
	if(counter < 0)
	{
		counter = counter * -1;
	}
	
	*winkel =  (counter * WINKEL_360_GRAD) / MAX_PULSE_COUNT;    //Winkel pro Pulse * counter
	
	
	
	/*
	Der Winkel beginnt wieder von 0, falls er sich �ber 360 Grad gesreht hat.
  */
	
	if ( (*winkel > WINKEL_360_GRAD) )
	{
		*winkel = *winkel % WINKEL_360_GRAD;
	}
	else if ( (*winkel < (WINKEL_360_GRAD * -1)) )
	{
		*winkel = *winkel % (WINKEL_360_GRAD * -1);
	}

	
	return 0;
}




/*
Die Funktion berechnet die Winkelgeschwindigkeit in Winkel/sekunde. 
Die Geschwindigkeit kann nicht negativ sein.
Nach jeder Sekunde wird der resetTime() aufgerufen, um das UIV-Flag wieder auf 0 zu setzen.

@param winkel der aktuelle Winkel des Drehgebers.
@param geschwindigkeit Hier wird die berechnete Geschwindigkeit gespeichert.

*/
void berechne_Winkelgeschwindigkeit(int16_t winkel, int16_t *geschwindigkeit)
{
	eineSekunde = checkUpdateFlag();
	
	if(eineSekunde)
	{
		
		*geschwindigkeit = winkel - alterWinkel;
	
	   if (*geschwindigkeit < 0)
	   {
	     *geschwindigkeit = *geschwindigkeit * -1;
     }
	
	  alterWinkel = winkel;

		resetTime(); 
	} 
}






