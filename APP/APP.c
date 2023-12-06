/*
 * APP.c
 *
 *  Created on: ١٠‏/١١‏/٢٠٢٣
  *      Author: Mohamed Yousef
 *      Email:  my612641@gmail.com
 */

#include  "../lib/std.h"
#include  <util/delay.h>
#include  "../MCAL/interfacing.h"
#include  "../MCAL/private.h"
#include  "../lib/mymath.h"
#include  "../HAL/Sw_interfacing.h"
void puch_buttom()
{
	Set_value value=0;

		DIO_Set_pin_direction(PORTC, Pin5, Input);
		DIO_Set_pin_direction(PORTC, Pin6, Output);





		 value = DIO_Get_pin_value(PORTC, Pin5);
			if(value == HIGH)
				  	{
				  		DIO_Set_pin_value(PORTC, Pin6, HIGH);
				  	}

				  	else{
				  		DIO_Set_pin_value(PORTC, Pin6, LOW);

				  	}

		  DIO_Set_Port_value (PORTB, 0XFF);
          _delay_ms(1000);
          DIO_Set_Port_value (PORTB, 0X00);


		  //DIO_Set_Port_Dirction(PORTC, Input);


		  DIO_Set_pin_value(PORTD, Pin0, HIGH);
		  _delay_ms(1000);
		  DIO_Set_pin_value(PORTD, Pin0, LOW);







}

void blink_leds()
{
	 DIO_Set_Port_Dirction(PORTB, Output);
		    DIO_Set_pin_direction(PORTD, Pin0, Output);



		    	          DIO_Set_Port_value (PORTB, 0XFF);
		    	          DIO_Set_Port_value (PORTB, 0X00);
		    			  DIO_Set_pin_value(PORTD, Pin0, HIGH);
		    			  DIO_Set_pin_value(PORTD, Pin0, LOW);


}
void delay_function(){
	_delay_ms(5000);
}
