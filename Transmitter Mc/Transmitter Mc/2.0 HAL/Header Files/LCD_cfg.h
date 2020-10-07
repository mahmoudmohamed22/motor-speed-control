/*
 * LCD_cfg.h
 *
 *  Created on: Sep 4, 2020
 *      Author: H
 */

#ifndef LCD_LCD_CFG_H_
#define LCD_LCD_CFG_H_
/*
 * Pin mode
 	 * 8 for 8-bit mode.
 	 * 4 for 4-bit mode.
 */
#define LCD_MODE 4


#if LCD_MODE == 4
//By Default in 4-bit mode .. we use high nibble of connected PORT .. remove definition to let low nibble.
#define HIGH_PINS
#endif

/*
 * Configure Data Port
 */

#define LCD_DDR  DDRA
#define LCD_PORT PORTA
#define LCD_PIN  PINA


/*
 * Pins
 */

#define LCD_CONTROL_DDR DDRA
#define LCD_CONTROL_PORT PORTA
#define LCD_RS         PD0
#define LCD_RW         PD1
#define LCD_ENABLE_PIN PD2

#define PD0 0
#define PD1 1
#define PD2 2





#endif /* LCD_LCD_CFG_H_ */
