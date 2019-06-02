/*
 * adc.h
 *
 * Created: 4/19/2019 9:50:13 PM
 *  Author: braso
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

/***************************************************************************************************
                             Function prototypes
***************************************************************************************************/
void ADC_Init();

uint16_t ADC_GetAdcValue(uint8_t v_adcChannel_u8);
/**************************************************************************************************/



#endif /* ADC_H_ */