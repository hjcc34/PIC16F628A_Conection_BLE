/* 
 * File:   CFGDHT11.h
 * Author: Familia CS
 *
 * Created on 30 de junio de 2023, 23:09
 */

#ifndef CFGDHT11_H
#define	CFGDHT11_H

#include <xc.h>
#include "CFG_PIC16F628A.h"
#include "CFG_RS232.h"

unsigned char H1,T1,T2,variable2,H2,DHT11,bit0,bit1,bit2,bit3,bit4,bit5,bit6,bit7,variable,DATO_LSB,DATO_MSB,DATO_MSB_1,DATO_MSB_2,DATO_LSB_1,DATO_LSB_2,DATO,X,unidad,decena,centena,unidadM,B,C;

#define DATA    PORTBbits.RB4

#ifdef	__cplusplus
extern "C" {
#endif

void DHT11_Inicio(void);
void DHT11_Res(void);
void DHT11_READ(unsigned char variable);
void DHT11_READ_STAR(void);
void DHT11_READ_CLOCK(void);
void CONVER_BIN_BCD_v (void);
void CONVERTIDOR__HEX_ASCII(unsigned char CONVER_DATO);

#endif	/* CFGDHT11_H */

