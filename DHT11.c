#include "CFGDHT11.h"
#include "CFG_PIC16F628A.h"

//------------------------------------------------------------------------------
void DHT11_Inicio(void)
{
    TRISBbits.TRISB4 = 0;
    DATA = 0;
    __delay_ms(25);                                                             //25 ms de bajo del micro
    TRISBbits.TRISB4 = 1;
    while (DATA == 1)
    {
    }
}
//------------------------------------------------------------------------------
void DHT11_Res(void)
{
    while (DATA == 0)           // verificar la respuesta baja del sensor 80us
    {
    }
    while (DATA == 1)           // verificar la respuesta alta del sensor 80us
    {
    }
}
//------------------------------------------------------------------------------
void DHT11_READ_STAR(void)
{
    while (DATA == 0)           // verifico los 50us del bit de inicio transmision
    {
    }
}
//------------------------------------------------------------------------------
void DHT11_READ(unsigned char variable)
{ 
//************************************BIT 7*************************************    
    __delay_us(30);
    if (DATA == 1)
    {
        variable = 1;
    }
    if (DATA == 0)
    {
        variable = 0;
    }
            while (DATA == 1)
        {
        }
//************************************BIT 6*************************************
    DHT11_READ_STAR();
    __delay_us(30);
    if (DATA == 1)
    {
        bit6 = variable <<1;
        variable = bit6 +1;
    }
    if (DATA == 0)
    {
        bit6 = variable <<1;
        variable = bit6;
    }
                while (DATA == 1)
        {
        }
//************************************BIT 5*************************************
    DHT11_READ_STAR();
    __delay_us(30);
    if (DATA == 1)
    {
        bit5 = variable <<1;
        variable = bit5 +1;
    }
    if (DATA == 0)
    {
        bit5 = variable <<1;
        variable = bit5;
    }
                while (DATA == 1)
        {
        }
//************************************BIT 4*************************************
    DHT11_READ_STAR();
    __delay_us(30);
    if (DATA == 1)
    {
        bit4 = variable <<1;
        variable = bit4 +1;
    }
    if (DATA == 0)
    {
        bit4 = variable <<1;
        variable = bit4;
    }
                while (DATA == 1)
        {
        }
//************************************BIT 3*************************************
    DHT11_READ_STAR();
    __delay_us(30);
    if (DATA == 1)
    {
        bit3 = variable <<1;
        variable = bit3 +1;
    }
    if (DATA == 0)
    {
        bit3 = variable <<1;
        variable = bit3;
    }
                while (DATA == 1)
        {
        }
//************************************BIT 2*************************************
    DHT11_READ_STAR();
    __delay_us(30);
    if (DATA == 1)
    {
        bit2 = variable <<1;
        variable = bit2 +1;
    }
    if (DATA == 0)
    {
        bit2 = variable <<1;
        variable = bit2;
    }
                while (DATA == 1)
        {
        }
//************************************BIT 1*************************************
    DHT11_READ_STAR();
    __delay_us(30);
    if (DATA == 1)
    {
        bit1 = variable <<1;
        variable = bit1 +1;
    }
    if (DATA == 0)
    {
        bit1 = variable <<1;
        variable = bit1;
    }
                while (DATA == 1)
        {
        }
//************************************BIT 0*************************************
    DHT11_READ_STAR();
    __delay_us(30);
    if (DATA == 1)
    {
        bit0 = variable <<1;
        variable = bit0 +1;
    }
    if (DATA == 0)
    {
        bit0 = variable <<1;
        variable = bit0;
    }
                while (DATA == 1)
        {
        }
    variable2 = variable;
    DHT11_READ_STAR();
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void DHT11_READ_CLOCK(void)
{
   H1 = 0;
   H2 = 0;
   T1 = 0;
   T2 = 0;
   DHT11_Inicio();
   DHT11_Res();
   DHT11_READ_STAR();
//*****************************Humedad 1***************************************   
   DHT11_READ(H1);
   H1 = variable2;
//*****************************Humedad 2***************************************   
   DHT11_READ(H2);
   H2 = variable2;
//***************************Temperatura 1*************************************   
   DHT11_READ(T1);
   T1 = variable2;
//***************************Temperatura 2*************************************   
   DHT11_READ(T2);
   T2 = variable2;
}
//******************************Humedad LCD*************************************
//------------------------------------------------------------------------------
//-----------------------Conversor Hex to ASCII---------------------------------
void CONVERTIDOR__HEX_ASCII(unsigned char CONVER_DATO)
{
    DATO_MSB   = CONVER_DATO;
    DATO_LSB   = CONVER_DATO;   
    DATO       = CONVER_DATO;
//******************************************************************************
    DATO_MSB /= 0x0A;
    unidadM = DATO_MSB;
    unidadM += 0x30;    
//******************************************************************************
    DATO_MSB /= 0x0A;
    decena = DATO_MSB;
    decena += 0x30;    
//******************************************************************************    
    if (DATO <= 9)
    {
        centena = DATO_LSB;
        centena += 0x30;
//******************************************************************************        
        unidad = DATO_LSB;
        unidad += 0x30;        
    }
//------------------------------------------------------------------------------
        if (DATO >= 0x0A && DATO <= 0xFF)
        {
        DATO_LSB -= (0x0A * X);
            if (DATO_LSB <= 9 && C == 1)
            {   
                centena = DATO_LSB;
                centena += 0x30;
                B = 1;
                X = 1;
            }
        if (DATO_LSB >= 0x0A && B == 1)
        {
            X++;
            B = 0;
            C = 1;
        }
        }
//******************************************************************************    
}
//------------------------------------------------------------------------------
//******************************************************************************