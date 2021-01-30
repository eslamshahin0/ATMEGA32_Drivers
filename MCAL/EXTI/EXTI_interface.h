/**
 * ***************************************************************
 *  @file      EXTI_interface.h				
 *  @author    Eslam Shahin (eslamshahin552000@gmail.com)                          
 *  @version   v1.0                                            
 *  @date      5 oct 2020		                                   
 *  @brief     This file has the  APIs functions of External
 *             interrupts for ATMEGA32             	                                 
 *
 *  @note      This program is distributed in the hope  that it  
 * 	           will be useful,but WITHOUT ANY WARRANTY; without     
 *	           even the implied warranty of  MERCHANTABILITY or     
 *	           FITNESS FOR A PARTICULAR PURPOSE.  
 *                                                      
 * ***************************************************************                                                                
 */
 
#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

/*!< @typedef TriggerEdge this typedef has the choises for the trigger source */
typedef enum{
	LOW_LEVEL=0,
	LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
}TriggerEdge;
	
/*!< @typedef ExInterruptSource this typedef has the choises for interrupts pins */
typedef enum{
	EXTI0=0,
	EXTI1,
	EXTI2
}ExInterruptSource;

void EXTI_voidEnable(ExInterruptSource InterruptPin);
void EXTI_voidDisable(ExInterruptSource InterruptPin);

void EXTI_voidTriggerEdge(ExInterruptSource InterruptPin,TriggerEdge Edge);	

u8   EXTI_u8GetFlag(ExInterruptSource InterruptPin) ;
void EXTI_u8SetFlag(ExInterruptSource InterruptPin) ;
void EXTI_u8ClearFlag(ExInterruptSource InterruptPin) ;

void EXTI_voidSetCallBack(ExInterruptSource InterruptPin,void(*LocalPtr)(void));



#endif
