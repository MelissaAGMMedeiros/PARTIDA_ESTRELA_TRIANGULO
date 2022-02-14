/*
 * File:   main.c
 * Author: 21193460
 *
 * Created on 11 de Fevereiro de 2022, 11:53
 */


#include <xc.h>
#include "delay.h"
#include "config.h"
#include "partidav.h"

#define _XTAL_FREQ 4000000

#define K1 PORTDbits.RD5
#define K2 PORTDbits.RD6
#define K3 PORTDbits.RD7
#define S0 PORTDbits.RD0
#define S1 PORTDbits.RD1


void main(void) 
{
    TRISD = 0x0F;
    PORTD = 0;
    
    while ( 1 )
    {
        if( !K1 )
        {
            if( !bt_liga() ) 
            {
                ligar();
            }
        }
        if( !bt_desliga() )
        {
            desligar();
        }
    }
}