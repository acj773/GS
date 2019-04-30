
#ifndef _MAIN_H
#define _MAIN _H


/**
  ******************************************************************************
  * @file    	main.c 
  * @author  	Alfred Lohmann
  *        	  HAW-Hamburg
  *          	Labor für technische Informatik
  *          	Berliner Tor  7
  *          	D-20099 Hamburg
  * @version V1.0
  * @date    23.05.2013
  * @brief   Main program body
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "TI_Lib.h"
#include "tft.h"
#include "FSM.h"
#include "input.h"
#include "output.h"
#include "timer.h"
#include "Auswertung.h"
#include "output.h"


//--- For GPIOs -----------------------------
//Include instead of "stm32f4xx.h" for
//compatibility between Simulation and Board
#include "TI_memory_map.h"



/**
  * @brief  Main program
  * @param  None
  */
  
	 
int8_t error = 0;            // Fehler bei error = 1


int16_t Geschwindigkeit = 0; //Die Winkelgeschwindigkeit in Winkel/Sekunde
int16_t Dreh_Winkel = 0;     //Drehwinkel des Drehgebers. -360 Grad <= Drehwinkel <= 360 Grad
	
	
int16_t pulse_count = 0;     //Zählerstand
uint8_t dg_state = 0;        //aktuelle Eingabe der Sensoren. (00, 01, 10 oder 11)
uint8_t ptr_dir = 0;         //Richtung der letzen Drehung. VW = 1 oder RW = 2 oder nicht bewegt = 0


bool s6 = 0;   //Taste S6 gedrückt
bool s7 = 0;	 //Taste S7 gedrückt


/*
FSM Automat.
Aktualisieren die Richtung und den curr_state. Überpruft ob Taste S6 und S7 gedrückt worden sind.  

@param dg_state 
@param ptr_dir        Richtung der Drehung. VW = 1 oder RW = 2 oder nicht bewegt = 0
@param pulse_counter  Anzahl der Phasen 
@param s6
@param s7

*/
int8_t (*state_table[])(uint8_t, uint8_t *, int16_t *, int8_t, int8_t) = {s_p, a_p, b_p, c_p, d_p, e_p}; 


#endif
