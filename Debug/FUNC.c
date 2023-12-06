/*
 * FUNC.c
 *
 *  Created on: ١٠‏/١١‏/٢٠٢٣
 *      Author: Administrator
 */


#include "../MCAL/interfacing.h"
#include "../MCAL/private.h"
#include "std.h"

void DIO_Set_Port_Dirction (DIO_Port_ID Port_ID, DIO_direction Direction )
{
	if( Output == Direction)
{
    switch (Port_ID)
    {
        case PORTA :  DDRA_REG =0XFF;   break;
        case PORTB :  DDRB_REG  =0XFF;  break;
        case PORTC :  DDRC_REG  =0XFF;  break;
        case PORTD :  DDRD_REG  =0XFF;  break;

    }
}
	else
	{
		switch (Port_ID)
		{
        case PORTA :  PORTA_REG =0XFF;   break;
        case PORTB :  DDRB_REG  =0X00;  break;
        case PORTC :  DDRC_REG  =0X00;  break;
        case PORTD :  DDRD_REG  =0XFF;  break;
	}

}

void DIO_Set_Port_value (DIO_Port_ID Port_ID , unsigned char value)
{
	switch (Port_ID)
	{
    	case PORTA : PORTA_REG = value;  break;
    	case PORTB : PORTB_REG = value;  break;
    	case PORTC : PORTC_REG = value;  break;
    	case PORTD : PORTD_REG = value;  break;

	}

}

void DIO_Set_pin_direction (DIO_Port_ID Port_ID, PIN_ID pin, DIO_direction  Direction)
{
	if((Port_ID <= PORTD) && (pin <= Pin7))
	{
		if(Output == Direction)
		{
			switch(Port_ID)
			{
					   case PORTA: DDRA_REG |= (1<<pin); break;
					   case PORTB: DDRB_REG |= (1<<pin); break;
					   case PORTC: DDRC_REG |= (1<<pin); break;
					   case PORTD: DDRD_REG |= (1<<pin); break;
			}
		}
		else
		{
			switch(Port_ID)
						{
								   case PORTA: DDRA_REG &=~ (1<<pin); break;
								   case PORTB: DDRB_REG &=~ (1<<pin); break;
								   case PORTC: DDRC_REG &=~ (1<<pin); break;
								   case PORTD: DDRD_REG &=~ (1<<pin); break;
						}
		}

	}
	else
	{

	}
}


void DIO_Set_pin_value (DIO_Port_ID Port_ID , PIN_ID pin, Set_value value)
{
	if((Port_ID <= PORTD) && (pin <= Pin7))
		{
			if(HIGH == value)
			{
				switch(Port_ID)
				{
						   case PORTA: PORTA_REG |= (1<<pin); break;
						   case PORTB: PORTB_REG |= (1<<pin); break;
						   case PORTC: PORTC_REG |= (1<<pin); break;
						   case PORTD: PORTD_REG |= (1<<pin); break;
				}
			}
			else
			{
				switch(Port_ID)
				{
						   case PORTA: PORTA_REG &=~ (1<<pin); break;
						   case PORTB: PORTB_REG &=~ (1<<pin); break;
						   case PORTC: PORTC_REG &=~ (1<<pin); break;
						   case PORTD: PORTD_REG &=~ (1<<pin); break;
				}
			}

		}
		else
		{

		}
}


Set_value DIO_Get_pin_value (DIO_Port_ID Port_ID , PIN_ID pin)
{
	Set_value value;
	if((Port_ID <= PORTD) && (pin <= Pin7))
			{
	        	switch(Port_ID)
				{
					 case PORTA: value = ((PINA_REG>>pin) & 0X01); break;
					 case PORTB: value = ((PINB_REG>>pin) & 0X01); break;
				     case PORTC: value = ((PINC_REG>>pin) & 0X01); break;
					 case PORTD: value = ((PIND_REG>>pin) & 0X01); break;
				}


			}
			else
			{

			}

	     return value;
}

}
