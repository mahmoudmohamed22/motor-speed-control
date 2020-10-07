

#include "LCD.h"


static void wait(uint8_t);

static void high_to_low_pulse();

/*
 * Init LCD.
 */
void LCD_init()
{
	/*
	 * init all ports D0 .. D7 as output port.
	 * RS, RW, ENABLE pins     as output port.
	 * in 8-bit mode to init.
	 */
	//init RS, RW, ENABLE pins.
	SeTBit(LCD_CONTROL_DDR, LCD_RS);
	SeTBit(LCD_CONTROL_DDR, LCD_RW);
	SeTBit(LCD_CONTROL_DDR, LCD_ENABLE_PIN);
#if LCD_MODE == 8
	//init ports as output pins.
	LCD_DDR = LCD_DDR | 0x7F;
	LCD_sendCommand(0x38);
#elif LCD_MODE == 4
#ifdef HIGH_PINS
	LCD_DDR = LCD_DDR | 0xF0;
#else
	LCD_DDR = LCD_DDR  | 0x0F;
#endif
	LCD_sendCommand(0x33);
	LCD_sendCommand(0x32);
	LCD_sendCommand(0x28);
#else
	#error "Error Wrong mode for LCD"
#endif
	LCD_sendCommand(0x0E);
	LCD_sendCommand(0x01);
	wait(1);
}

/*
 * LCD send Command.
 */
void LCD_sendCommand(uint8_t cmd)
{
	/*
	 * To send cmd.
	 	 * RS Must be clear. (CMD)
	 	 * RW Must be clear. (Write)
	 	 * E enable bit high-to-low pulse.
	 	 * delay about 20ms.
	 	 * send cmd.
	 	 * delay about 20ms.
	 */
	ClearBit(LCD_CONTROL_PORT, LCD_RS);
	ClearBit(LCD_CONTROL_PORT, LCD_RW);
#if LCD_MODE == 8
	LCD_PORT = cmd;
	high_to_low_pulse();
#elif LCD_MODE == 4

#ifdef HIGH_PINS
	//Send high nibble.
	LCD_PORT = (LCD_PORT & 0x0F) |  (cmd  & 0xF0);
	high_to_low_pulse();
	//send low nibble.
	LCD_PORT = (LCD_PORT & 0x0F) |  (cmd << 4);
	high_to_low_pulse();
#else
	//Send high nibble.
	LCD_PORT = (LCD_PORT & 0xF0) |  (cmd >> 4);
	high_to_low_pulse();
	//send low nibble.
	LCD_PORT = (LCD_PORT & 0xF0) |  (cmd & 0x0F);
	high_to_low_pulse();
#endif

#endif
}

/*
 * LCD display Character.
 */
void LCD_displayCharacter(uint8_t character)
{
	/*
	 * RS = 1.
	 * RW = 0 Write.
	 * E High-to-low pulse.
	 * delay.
	 * Write Data.
	 * delay to latch.
	 */
	SeTBit(LCD_CONTROL_PORT,   LCD_RS);
	ClearBit(LCD_CONTROL_PORT, LCD_RW);
#if LCD_MODE == 8
	LCD_PORT = character;
	high_to_low_pulse();
#elif LCD_MODE == 4

#ifdef HIGH_PINS
	//Send high nibble.
	LCD_PORT = (LCD_PORT & 0x0F) |  (character  & 0xF0);
	high_to_low_pulse();
	//send low nibble.
	LCD_PORT = (LCD_PORT & 0x0F) |  (character << 4);
	high_to_low_pulse();
#else
	//Send high nibble.
	LCD_PORT = (LCD_PORT & 0xF0) |  (character >> 4);
	high_to_low_pulse();
	//send low nibble.
	LCD_PORT = (LCD_PORT & 0xF0) |  (character & 0x0F);
	high_to_low_pulse();

#endif

#endif
}

/*
 * Display string.
 */
void LCD_displayString(uint8_t * string)
{
	uint8_t i = 0;

	while( *(string + i) != '\0' )
	{
		LCD_displayCharacter(*(string + i));
		i++;
	}
}

/*
 * Display string at specific location.
 */

void LCD_displayStringRowCol(uint8_t * string, uint8_t row, uint8_t col)
{
	LCD_goToRowColumn( row, col );
	LCD_displayString(string);
}
/*
 * Go to row column.
 */
void LCD_goToRowColumn(uint8_t row, uint8_t col)
{
	uint8_t address;
	switch(row)
	{
		case 1:
			address = 0x80 + col;
			break;
		case 2:
			address = 0x40 + col;
			break;
		case 3:
			address =  0x10 + col;
			break;
		case 4:
			address = 0x50 + col;
			break;
	}
	LCD_sendCommand( address | 0x80 );
}


/*
 * Integer to ascii.
 */
void LCD_integerToString(uint16_t number)
{
	uint8_t buffer[16];
	itoa(number, buffer, 10);
	LCD_displayString(buffer);
}

/*
 * Clear Screen.
 */
void LCD_clearScreen()
{
	LCD_sendCommand(0x01);
}
/*
 * LCD_wait .. this function used to create a delay after sending commands or data so LCD latch information.
 */

static void wait(uint8_t time)
{
	_delay_ms(time);
}

static void high_to_low_pulse()
{
	SeTBit(LCD_CONTROL_PORT, LCD_ENABLE_PIN);
	wait(20);
	ClearBit(LCD_CONTROL_PORT, LCD_ENABLE_PIN);
	wait(1);
}
