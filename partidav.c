/*
 * File:   partidav.c
 * Author: 21193460
 *
 * Created on 14 de Fevereiro de 2022, 09:39
 */


#include <xc.h>
#include "partida.h"
#include "delay.h"
#include "partidav.h"

#define TIMEOUT 10000

#define _XTAL_FREQ 4000000

#define K1 PORTDbits.RD5
#define K2 PORTDbits.RD6
#define K3 PORTDbits.RD7
#define S0 PORTDbits.RD0
#define S1 PORTDbits.RD1
#define ATRASO(n) __delay_ms(n)

void initial(void)
{
    TRISD = 0x0F;
    PORTD = 0;
}

void ligar(void)
{
    K1 = 1;
    K3 = 1;
    block();
    K2 = 1;
    K3 = 0;
}

void desligar(void)
{
    K1 = 0;
    K2 = 0; 
    K3 = 0;
}

char bt_liga(void)
{
    return(S1);
}

char bt_desliga(void)
{ 
    return(S0);
}

char timeout(void)
{
    unsigned int t = TIMEOUT;
    while(t)
    {
        ATRASO(1);
        --t;
        if( bt_desliga() )
        {
            break;
        }
    }
    return( 1 );
}

void block ( void)
{
    char d;
    for (d=0; d<30; d++)
    {
        __delay_ms(100);
        if(!bt_desliga())
            break;
    }
}