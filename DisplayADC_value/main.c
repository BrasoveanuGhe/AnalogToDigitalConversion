/*
 * waterLevel_detection.c
 *
 * Created: 4/18/2019 9:48:34 PM
 * Author : braso
 */ 

#ifndef F_CPU
#define F_CPU   7372800UL
#endif

#include <avr/io.h>
#include <stdlib.h>
#include <stdbool.h>
#include <avr/interrupt.h>

#include "lcd_defines.h"
#include "adc.h"


uint16_t adc_result1 = 0;
uint16_t adc_result2 = 0;
uint16_t adc_result3 = 0;
char string[10];


//void adc_init()
//{
	// Set the ADC reference voltage
	//ADMUX |= (1 << REFS0) | (1 << MUX0) | (1  << MUX1) | (1 << MUX2);
		
	// ADC enable
	//ADCSRA |= (1 << ADEN);
	
	// Set ADC prescaler to 64 - 115.2KHz
	//ADCSRA |= (1 << ADPS2) | (1 << ADPS1);
	
//}

// uint16_t adc_read(uint8_t ch)
// {
// 	ch &= 0b00000111;				// AND operation with 7
// 	ADMUX = (ADMUX & 0xF8) | ch;	// clears the bottom 3 bits before ORing
// 		
// 	// start single convertion
// 	// write ’1? to ADSC
// 	ADCSRA |= (1<<ADSC);
// 	
// 	 // wait for conversion to complete
// 	 // ADSC becomes ’0? again
// 	 // till then, run loop continuously
// 	 while(ADCSRA & (1<<ADSC));
// 	 
// 	return (ADC);
// }

int main(void)
{
	
	liquidCrystalPortInit(&PORTA,&PORTC,PORTC0,PORTC1,PORTC2);
	lcd_clear();
	
	lcd_goToLine(1,1);
	lcd_displayChar("ADC1 = ");
	lcd_goToLine(2,1);
	lcd_displayChar("ADC2 = ");
	lcd_goToLine(3,1);
	lcd_displayChar("ADC3 = ");
	
	// Initialize ADC
	ADC_Init();
	
   do 
   {
	  adc_result1 = ADC_GetAdcValue(MUX0);
	  adc_result2 = ADC_GetAdcValue(MUX1);
	  adc_result3 = ADC_GetAdcValue(MUX2);
	   
	   if(adc_result1 > 111)
	   {
		   lcd_goToLine(1,7);
		   lcd_displayFloatNumber(adc_result1);
		   
	   } else {   
			lcd_goToLine(1,7);
			lcd_displayFloatNumber(adc_result1);				
		}
		   
		if(adc_result2 > 111)
		{
			 lcd_goToLine(2,7);
			 lcd_displayFloatNumber(adc_result2);
			 
			 } else {
			 lcd_goToLine(2,7);
			 lcd_displayFloatNumber(adc_result2);			 
		} 
		 
		if(adc_result3 > 111)
		{
			 lcd_goToLine(3,7);
			 lcd_displayFloatNumber(adc_result3);
		 
		 } else {
			 lcd_goToLine(3,7);
			 lcd_displayFloatNumber(adc_result3);;			  
		}  
	   	   
   } while (1);
}

