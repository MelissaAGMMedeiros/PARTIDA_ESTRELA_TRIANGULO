/*
 * File:   main.c
 * Author: 21193460
 *
 * Created on 5 de Novembro de 2021, 08:59
 */

#include "config.h"
#include <xc.h>

#define _XTAL_FREQ 4000000

#define K1 PORTDbits.RD5
#define K2 PORTDbits.RD6
#define K3 PORTDbits.RD7
#define S0 PORTDbits.RD0
#define S1 PORTDbits.RD1

void main(void) 
{
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD0 = 1;
    TRISDbits.TRISD1 = 1;
    
    K1 = 0;
    K2 = 0;
    K3 = 0;
    S0 = 0;
    S1 = 0;
    
    while ( 1 )
    {         
        if( K1 == 0 )
        {
            if( S1 == 0 ) 
            {
                K1 = 1;
                K3 = 1;
                __delay_ms(5000);
                K2 = 1;
                K3 = 0;
            }
        }   
        if( S0 == 0 )
        {
            K1 = 0;
            K2 = 0; 
            K3 = 0;
        }
    }
}
