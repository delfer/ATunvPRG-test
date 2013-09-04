/*
 * ATunvPRG_test.c
 *
 * Created: 04.09.2013 16:34:08
 *  Author: Delfer
 */ 

//CPU Speed = quartz freq = 16MHz
#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//Start CPU on quartz freq
	//Tern off prescaler
	CLKPR = (1<<CLKPCE); //Enable editing CLKPS
	CLKPR = 0; //Set prescaler to 1
	
	unsigned char i; //Counter (number of bit in byte)
	
	//Make all 21 pins as outputs
	DDRC = 0b11110100;
	DDRB = 0B11111111;
	DDRD = 0B11111111;
	
    while(1)
    {
		//PORTC 2,4,5,6,7,8
        for (i = 0; i < 8; i++)
		{
			if ((i < 2) || (i == 3))
				continue;
			PORTC = 1 << i;
			_delay_ms(1000); 
		}
		PORTC = 0;
		
		//PORTB 0,1,2,3,4,5,6,7,8
		for (i = 0; i < 8; i++)
		{
			PORTB = 1 << i;
			_delay_ms(1000);
		}
		PORTB = 0;
		
		//PORTD 0,1,2,3,4,5,6,7,8
		for (i = 0; i < 8; i++)
		{
			PORTD = 1 << i;
			_delay_ms(1000);
		}
		PORTD = 0;
    }
}