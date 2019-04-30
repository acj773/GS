#include "main.h"





// DDC Modell
// INITIALISIERUNG -> INPUT -> Auswertung im FSM -> AKTUALISIERUNG -> OUTPUT


int main(void)
{
	/*----------------------INITIALISIERUNG----------------------------------*/
	Init_TI_Board();
	init_display();
	timerinit();
	State_Type curr_state = START; //Anfangs-Zustand des Automaten
	
	while(1)
	{
		do
		{
        /*-----------------INPUT------------------------------------------*/
        //Input lesen fuer dg_state, Taste S6 und Taste S7
			  signalLesen(&dg_state, &s6, &s7);			  
			
			

        /*-----------------Auswerung im FSM AUTOMATEN---------------------*/
			  
        error = state_table[curr_state](dg_state, &ptr_dir, &pulse_count, s6, s7);
		    
			  //wenn error == 1 dann fehler!
		    if(error == 1) 
				{
			     GPIOG->BSRRL = MASK_PIN_5;
		    }
				
		}while (error == 1);
	    
	
		
		/*--------------------AKTUALISIERUNG---------------------------------*/     
		
		//LEDs aktualisert
		counter_LED_8_15(pulse_count);
		LEDs_Richtung(ptr_dir);
	  
		//Winkel und Geschwindigkeit aktualisieren
		berechne_Winkel(pulse_count, &Dreh_Winkel);			
		berechne_Winkelgeschwindigkeit(Dreh_Winkel, &Geschwindigkeit);
		
		
		
		 /*-------------------OUTPUT--------------------------------------------*/
		printausgabe(Dreh_Winkel,Geschwindigkeit);
	}

}
// EOF
