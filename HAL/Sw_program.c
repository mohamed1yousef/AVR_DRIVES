/*
 * Sw_program.c
 *
 *  Created on: ١٤‏/١١‏/٢٠٢٣
 *      Author: Administrator
 */

#include "Sw_interfacing.h"
#include "../lib/std.h"
#include "../MCAL/interfacing.h"
#include "../MCAL/private.h"
#include "../lib/mymath.h"

void mo (DIO_Port_ID Port_ID, PIN_ID pin, DIO_direction Direction, Set_value value)
{
	          DIO_Set_pin_direction(Port_ID, pin, Direction);
		      DIO_Set_pin_value(Port_ID, pin, value);

}
