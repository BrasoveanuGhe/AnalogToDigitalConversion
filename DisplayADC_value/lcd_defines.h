/*
 * lcd_defines.h
 *
 * Created: 10/20/2018 12:34:52 PM
 *  Author: braso
 */ 


#ifndef F_CPU
#define F_CPU 7372800UL
#endif

#ifndef LCD_DEFINES_H_
#define LCD_DEFINES_H_

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>


volatile char *str;
char displayFloatNum[20];


/**************************************************************
		List of commonly used LCD Commands
**************************************************************/
#define LCD_CLEAR				0x01     
 
#define LCD_RETURN_HOME				0x02

#define LCD_INCREMENT_RIGHT			0x06
#define LCD_DECREMENT_LEFT			0x04

#define LCD_DISPLAY_ON_CURSOR_OFF		0x0C    
#define LCD_DISPLAY_ON_CURSOR_ON		0x0E     
#define LCD_DISPLAY_ON_CURSOR_BLINK		0x0F  

#define LCD_FOUR_BIT_MODE			0x28	       
#define LCD_EIGHT_BIT_MODE			0x38 // 8 bits; 2 lines; 5x8 dots (character size)

#define LCD_CURSOR_HOME_POSITION		0x80


     
typedef struct  
{
	volatile uint8_t *commandPort;
	volatile uint8_t *dataPort;
	uint8_t pin_RS;
	uint8_t pin_EN;
	uint8_t pin_RW;
	
} lcd_commandInit;

lcd_commandInit lcd_portInit;


void liquidCrystalPortInit(volatile uint8_t *dataPort, volatile  uint8_t *cmdPort, uint8_t rsPin, uint8_t rwPin, uint8_t enPin);



/***************************************************************************************************
 * \description : This function sends a command to LCD.
				  Some of the commonly used commands are defined in lcd.h.
				  For more commands refer the data sheet and send the supported command.
				
				 
 * \I/P Arguments: 8-bit command supported by LCD.
				   v_lcdCmd:		Used to enter the address of the instructions.
				  
 * \Return value:  none
****************************************************************************************************/
void lcd_cmdWrite(uint8_t v_lcdCmd); 



/*************************************************************************************************
 * \description :  This functions is used to send a byte of data to LCD. 
 
 * \I/P Arguments: uint8_t: 8-bit value to be sent to LCD.
				   dataByte:		Used to sends the data 'data' to the LCD module.
				   
 * \Return value:  none                  
**************************************************************************************************/
void lcd_dataWrite(uint8_t dataByte); 



/***************************************************************************************************
 * \description:   This function sends a character to be displayed on LCD.
				  
 * \I/P Arguments: ASCII value of the char to be displayed.
 
 * \Return value:  none
****************************************************************************************************/
void lcd_displayChar(char *str); 



/***************************************************************************************************
 * \description:  This function clears the LCD and moves the cursor to beginning of first line
 
 * \Return value: none
****************************************************************************************************/
void lcd_clear(); 



/***************************************************************************************************
 * \description:   This function displays the message sent to a specific row and position.
 
 * \I/P Arguments: uint8_t: Line number and XY position.
 
 * \Return value:  none
****************************************************************************************************/
void lcd_goToLine(unsigned char row, unsigned char position); 



/*************************************************************************************************
 * \description :  This function is used to display a floating point number
				   It supports 6digits of precision.
 
 * \I/P Arguments: float: Float Number to be displayed on the LCD.

 * \Return value:  none
***************************************************************************************************/
void lcd_displayFloatNumber(double floatNum);



#endif /* LCD_DEFINES_H_ */
