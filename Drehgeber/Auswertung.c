#include "Auswertung.h"
#include "timer.h"

int16_t alterWinkel = 0;

int8_t berechneWinkel(uint8_t counter, float* winkel)
{
	if(counter < 0)
	{
		counter = counter * -1;
	}
	*winkel = Winkel_pro_Puls * counter;
	return 0;
}

int8_t gibWinkelgeschwindigkeit(float winkel, float *geschwindigkeit)
{
//		int newTime = getTimeStamp();
//		int timeDiff = newTime -_time;
//		   _time = timeDiff;
	
	*geschwindigkeit = winkel - alterWinkel;
	if (*geschwindigkeit < 0)
	{
		*geschwindigkeit = *geschwindigkeit * -1;
	}
	alterWinkel = winkel;
}
