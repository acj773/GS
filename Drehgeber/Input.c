/**
  ******************************************************************************
  * @file    	input.c
  * @author  	Faissal Farid, Ehsan Sajadi ; Isam Karrar , Martin Sazgar
  * @version V1.0
  * @date    27.03.2019
  ******************************************************************************
  */
  

#include "input.h"

bool A;
bool B;

void givePinA(void)
{
	bool gpioe_Pin_0 = IDR_MASK_PIN_0 != (GPIOE -> IDR & IDR_MASK_PIN_0);
	A = gpioe_Pin_0;   
}

void givePinB(void)
{
    bool gpioe_Pin_1 = IDR_MASK_PIN_1 != (GPIOE -> IDR & IDR_MASK_PIN_1);
    B =  gpioe_Pin_1;
}


int8_t signalLesen (uint8_t *dg_state)
{
	
	givePinA();
	givePinB();
	
	if (A == 0 && B == 0)    // 00, Phase A,  (!A && !B)
	{
		*dg_state = 0 ;        // Phase a, A_P
	}
  if (A == 0 && B == 1 )   // 01, Phase D,	(!A && B )
	{
		*dg_state = 1 ;        // Phase b, D_P
	}
  if ( A == 1 && B == 0)   // 10, Phase B,	( A && !B)
	{
		*dg_state = 2;         // Phase c
	}
  if ( A == 1 && B == 1 )  // 11, Phase C,  ( A && B )
	{
		*dg_state = 3 ;        //Phase d,  C_P
	}
	return E_P;

}

bool pin6_Pressed(void)
{
	return (IDR_MASK_PIN_6 != (GPIOE->IDR & IDR_MASK_PIN_6));
}

bool pin7_Pressed(void)
{
	return (IDR_MASK_PIN_7 != (GPIOE->IDR & IDR_MASK_PIN_7));
}





//int8_t signalLesen (void);
