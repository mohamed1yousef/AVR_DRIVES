/*
 * defentio.c
 *
 *  Created on: ١٠‏/١١‏/٢٠٢٣
  *      Author: Mohamed Yousef
 *      Email:  my612641@gmail.com
 */
#include "../lib/std.h"
#include "interfacing.h"
#include "private.h"
#include "../lib/mymath.h"
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
						   case PORTA: Set_Bit(PORTA_REG , pin); break;
						   case PORTB: Set_Bit(PORTB_REG , pin); break;
						   case PORTC: Set_Bit(PORTC_REG , pin); break;
						   case PORTD: Set_Bit(PORTD_REG , pin); break;
				}
			}
			else
			{
				switch(Port_ID)
				{
				 case PORTA: Set_Bit(PORTA_REG , pin); break;
						   case PORTB: Clear_Bit(PORTB_REG , pin); break;
						   case PORTC: Clear_Bit(PORTC_REG , pin); break;
						   case PORTD: Clear_Bit(PORTD_REG , pin); break;
				}
			}

		}
		else
		{

		}
}


Set_value DIO_Get_pin_value (DIO_Port_ID Port_ID , PIN_ID pin)
{
	Set_value value=0;
	if((Port_ID <= PORTD) && (pin <= Pin7))
			{
	        	switch(Port_ID)
				{
					 case PORTA: value = Get_Bit(PINA_REG, pin); break;
					 case PORTB: value = Get_Bit (PINB_REG, pin); break;
				     case PORTC: value = Get_Bit (PINC_REG, pin); break;
					 case PORTD: value = Get_Bit (PIND_REG, pin); break;
				}


			}
			else
			{

			}
	return value;
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

}


