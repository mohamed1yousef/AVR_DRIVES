/*
 * mymath.h
 *
 *  Created on: ١٤‏/١١‏/٢٠٢٣
 *      Author: Mohamed Yousef
 *      Email:  my612641@gmail.com
 */

#ifndef LIB_MYMATH_H_
#define LIB_MYMATH_H_

#define Set_Bit(Reg , pin)      Reg |= (1<<pin)
#define Clear_Bit(Reg ,pin)     Reg &= ~(1<<pin)
#define Toggle_Bit(Reg , pin)   Reg ^= (1<<pin)
#define Get_Bit(Reg , pin)     ((Reg>>pin) & 0X01)

#endif /* LIB_MYMATH_H_ */
