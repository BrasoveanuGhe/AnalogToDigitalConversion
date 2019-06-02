/*
 * adc.c
 *
 * Created: 4/19/2019 9:50:23 PM
 *  Author: braso
 */ 

#ifndef F_CPU
#define F_CPU   7372800UL
#endif

#include "adc.h"
#include "stdutils.h"


/***************************************************************************************************
					void ADC_Init()
****************************************************************************************************
 * I/P Arguments: none.
 * Return value	: none

 * description :This function initializes the ADC module.

***************************************************************************************************/
void ADC_Init()
 {
	// Set the ADC reference voltage
	ADMUX |= (1 << REFS0);
	
	// ADC enable
	ADCSRA |= (1 << ADEN);
	
	// Set ADC prescaler to 64 - 115.2KHz
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1);                  
 }


/***************************************************************************************************
                         uint16_t ADC_GetAdcValue(uint8_t v_adcChannel_u8)
****************************************************************************************************
 * I/P Arguments: uint8_t(channel number).
 * Return value	: uint16_t(10 bit ADC result)

 * description  :This function does the ADC conversion for the Selected Channel
                 and returns the converted 10bit result
***************************************************************************************************/				 
uint16_t ADC_GetAdcValue(uint8_t v_adcChannel_u8)
 {
						/*select the corresponding channel 0~7*/
   v_adcChannel_u8 &= 0b00000111;		/* AND operation with 7*/
   ADMUX = (ADMUX & 0xF8) | v_adcChannel_u8;	/* Clears the bottom 3 bits */
   
   _delay_ms(10);				/* Wait for some time for the channel to get selected */
   util_BitSet(ADCSRA,ADSC);			/* Start single conversion*/
   
   while(ADCSRA & (1<<ADSC));			/* Wait till the conversion is over */
						/* ADIF will be set once ADC conversion is complete */
	return (ADC);				/* Return the 10-bit result */
    					
 }
