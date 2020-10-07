/*
 * LCD.h
 *
 *  Created on: Sep 4, 2020
 *      Author: H
 */

#ifndef LCD_LCD_H_
#define LCD_LCD_H_

#include "LCD_cfg.h"
#include "MicroConfiguration.h"
#include "Macros.h"
#include "StdTypes.h"
#include "util/delay.h"

/*
 * Poplar Commands For LCD
 */

#define CLEAR_COMMAND 0X01
#define CURSOR_OFF 0X0C
#define CURSOR_ON OXOE
#define FOUR_BITS_DATA_MODE 0x02
#define SET_CURSOR_LOCATION 0X80

/*
 * Init LCD.
 */
void LCD_init();

/*
 * LCD send Command.
 */
void LCD_sendCommand(uint8_t cmd);

/*
 * LCD display Character.
 */
void LCD_displayCharacter(uint8_t character);

/*
 * Go to row column.
 */
void LCD_goToRowColumn(uint8_t row, uint8_t col);


/*
 * Display string at specific location.
 */

void LCD_displayStringRowCol(uint8_t* string, uint8_t row, uint8_t col);


/*
 * Clear Screen.
 */
void LCD_clearScreen();


/*
 * Display string.
 */
void LCD_displayString(uint8_t * string);

/*
 * Integer to ascii.
 */
void LCD_integerToString (uint16_t number);



#endif /* LCD_LCD_H_ */
