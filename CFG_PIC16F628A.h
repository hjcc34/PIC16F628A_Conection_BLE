/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.

#ifndef CFG_PIC16F628A_H
#define	CFG_PIC16F628A_H

#pragma config FOSC = INTOSCIO                                                  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF                                                       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON                                                       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON                                                       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = ON                                                       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = OFF                                                        // Low-Voltage Programming Enable bit (RB4/PGM pin has PGM function, low-voltage programming enabled)
#pragma config CPD = OFF                                                        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF                                                         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>

#define _XTAL_FREQ 4000000

#define BLE_OK          PORTAbits.RA7
#define BLE_NOK         PORTAbits.RA6
#define SALIDA_1        PORTBbits.RB5
#define SALIDA_CTRL     PORTBbits.RB3

char i;

char P = 84;

#endif	/* CFG_PIC16F628A_H */