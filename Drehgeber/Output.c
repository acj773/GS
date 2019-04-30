/**
  ******************************************************************************
  * @file    	output.c
  * @author  	Faissal Farid, Ehsan Sajadi ; Isam Karrar , Martin Sazgar
  * @version V1.0
  * @date    27.03.2019
  ******************************************************************************
  */
  

#include "output.h"
#include "Input.h"

char buffer[12];
void init_display(void)
{
	TFT_set_window(FONT, INPUTXI, INPUTYI, WIDTHI, ROWSI);
	TFT_cls();
	TFT_puts("Drehgeschwindigkeit:       Grad/s");
	TFT_puts("                    Winkel:       Grad");
	
	TFT_gotoxy(1,4);
	TFT_puts("S7: Counter Reset\n");
	TFT_gotoxy(1,5);
	TFT_puts("S6: Error Reset\n");
	TFT_cursor_off();
	
	
	TFT_set_window( FONT, INPUTX, INPUTYI, WIDTH, ROWS);
	TFT_set_font_color(3);
}



void LEDs_Richtung(uint8_t dir) //(richtung)
{
	if(dir == LEFT)
	{
		GPIOG->BSRRL = MASK_PIN_7;
		GPIOG->BSRRH = MASK_PIN_6;
	}
	else if(dir == RIGHT)
	{
		GPIOG->BSRRL = MASK_PIN_6;
		GPIOG->BSRRH = MASK_PIN_7;
	}
}

void counter_LED_8_15(int16_t counter)
{
	GPIOG->BSRRH = MASK_PIN_8_15; // LEDs off
	GPIOG->BSRRL = counter << 8; 	// LEDs on
}

void printausgabe(float wert,float wert2){
	snprintf(buffer, 12, "%.1f\n\r ,%.1f", wert,wert2);
	
}
