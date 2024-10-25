/*
 * File:   main.c
 * Author: Familia CS
 *
 * Created on 27 de febrero de 2024, 19:19
 */

#include <xc.h>
#include <pic16f628a.h>
#include <string.h>
#include <stdio.h>
#include "CFG_PIC16F628A.h"
#include "CFG_RS232.h"
#include "CFGDHT11.h"

//--------------------------------Interrupcion----------------------------------
void __interrupt () RX_DATO (void)
{
    if (PIR1bits.RCIF == 1)
    {
    Uart_Read_String(cadena, 20);                                               // Lee la cadena recibida y la almacena
//******************************************************************************    
            if(!strcmp(cadena, "BLE_OK"))                                        // Si la cadena es "BLE_C", ENVIENDE BLE_OK el led
            {
            /*    
            Uart_Send_String("BLUETOOH CONECTADO\r\n");                         // ENVIA TEXTO A LA APK BLUETOOH CONECTADO
            */ 
            BLE_OK = 1;                                                         // ENCIENDE LED DE BLE_OK
            BLE_NOK = 0;                                                        // APAGA LED DE BLE_NOK
            }
//******************************************************************************    
            if(!strcmp(cadena, "BLE_NOK"))                                        // Si la cadena es "BLE_C", ENVIENDE BLE_OK el led
            {
            /*
            Uart_Send_String("BLUETOOH CONECTADO\r\n");                         // ENVIA TEXTO A LA APK BLUETOOH CONECTADO
            */ 
            BLE_OK = 0;                                                         // ENCIENDE LED DE BLE_OK
            BLE_NOK = 1;                                                        // APAGA LED DE BLE_NOK
            }    
//******************************************************************************
            if(!strcmp(cadena, "SALIDA_BLE_1_ON"))                              // Si la cadena es "SALIDA_BLE_1_ON", enciende el led SALIDA_1
            {
            /*
            Uart_Send_String("Salida ON\r\n");                                  // ENVIA TEXTO A LA APK DE SALIDA ON
            */ 
            SALIDA_1 = 1;                                                       // ENCIENDE LA SALIDA 1                                                      
            }
//******************************************************************************     
            if(!strcmp(cadena, "SALIDA_BLE_1_OFF"))                             // Si la cadena es "SALIDA_BLE_1_OFF", apaga el led SALIDA_1
            {
            /*
            Uart_Send_String("Salida OFF\r\n");                                 // ENVIA TEXTO A LA APK DE SALIDA OFF
            */ 
            SALIDA_1 = 0;                                                       // APAGA LA SALIDA 1
            }    
    }
    PIR1bits.RCIF = 0;
} 
//------------------------------------------------------------------------------

void main(void)
{
    TRISA = 0;                                                                  //Puertos A como salidas
    TRISB = 0x12;                                                               //Puertos B como salidas
    PORTA = 0, PORTB = 0;                                                       //Puerto A,B,C,D y E a cero todos los pines
    CMCON = 0x07;                                                               //DESACTIVA LOS COMPARADORES
    OPTION_REGbits.PSA = 0, OPTION_REGbits.PS0 = 0,OPTION_REGbits.PS1 = 0,OPTION_REGbits.PS2 = 0; 
    Uart_Init(9600);
    BLE_OK = 1;
    BLE_NOK = 0;
    SALIDA_1 = 0;
    SALIDA_CTRL = 0;
    __delay_ms(500);
    BLE_OK = 0;
    BLE_NOK = 1;
    SALIDA_1 = 0;
    SALIDA_CTRL = 0;
    __delay_ms(500);
    BLE_OK = 0;
    BLE_NOK = 0;
    SALIDA_1 = 1;
    SALIDA_CTRL = 0;
    __delay_ms(500);
    BLE_OK = 0;
    BLE_NOK = 0;
    SALIDA_1 = 0;
    SALIDA_CTRL = 1;
    __delay_ms(500);
    BLE_OK = 0;
    BLE_NOK = 0;
    SALIDA_1 = 0;
    SALIDA_CTRL = 0;
    __delay_ms(500);
    X = 1;
    B = 1;
    C = 1;
//-------------------------------Programa principal-----------------------------    
    while (1)
    {
    DHT11_READ_CLOCK();
    CONVERTIDOR__HEX_ASCII(H1);
    Uart_Send_Char(unidadM);
    Uart_Send_Char(centena);   
    Uart_Send_Char('.');
    CONVERTIDOR__HEX_ASCII(H2);
    Uart_Send_Char(decena);
    Uart_Send_Char(unidad);
    Uart_Send_String("\r\n");
//******************************************************************************    
    CONVERTIDOR__HEX_ASCII(T1);
    Uart_Send_Char(unidadM);
    Uart_Send_Char(centena);
    Uart_Send_Char('.');
    CONVERTIDOR__HEX_ASCII(T2);
    Uart_Send_Char(decena);
    Uart_Send_Char(unidad);
    Uart_Send_String("\r\n"); 
//******************************************************************************
    __delay_ms(2000);
    } 
}