/**
 * ***************************************************************
 *  @file      EXTI_program.c			
 *  @author    Eslam Shahin (eslamshahin552000@gmail.com)                          
 *  @version   v1.0                                            
 *  @date      5 oct 2020		                                   
 *  @brief     This file have the implementation of External
 *             interrupts APIs for ATMEGA32             	                                 
 *
 *  @note      This program is distributed in the hope  that it  
 * 	           will be useful,but WITHOUT ANY WARRANTY; without     
 *	           even the implied warranty of  MERCHANTABILITY or     
 *	           FITNESS FOR A PARTICULAR PURPOSE.  
 *                                                      
 * ***************************************************************                                                                
 */
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "../../Mem_Map32.h"

#include "EXTI_interface.h"

/* Functions to pointers to call app from mcal */
static void (*INT0_Fptr)(void) = NULLPTR;
static void (*INT1_Fptr)(void) = NULLPTR;
static void (*INT2_Fptr)(void) = NULLPTR;

/**
 * 
 * @fn      void EXTI_voidEnable(ExInterruptSource InterruptPin)
 * @brief   Enable specific interrupt pin
 * @param   InterruptPin pin number  
 * @return  void
 * 	  
 */
void EXTI_voidEnable(ExInterruptSource InterruptPin) 
{
	/* Set the interrupt enable bit */
	switch (InterruptPin) {
	case EXTI0:
		SET_BIT(GICR,INT0);
		break;
	case EXTI1:
		SET_BIT(GICR,INT1);
		break;
	case EXTI2:
		SET_BIT(GICR,INT2);
		break;
	default :
	/* Do nothing  */
	break ;
	}
}

/**
 * 
 * @fn      void EXTI_voidDisable(ExInterruptSource InterruptPin)
 * @brief   Disable specific interrupt pin
 * @param   InterruptPin pin number  
 * @return  void
 * 	  
 */
void EXTI_voidDisable(ExInterruptSource InterruptPin)
{
	/* disable the interrupt enable bit  */
	switch (InterruptPin) {
	case EXTI0:
		CLEAR_BIT(GICR, INT0);
		break;
	case EXTI1:
		CLEAR_BIT(GICR, INT1);
		break;
	case EXTI2:
		CLEAR_BIT(GICR, INT2);
		break;
	default :
	/* Do noting */
	break;
	}
}

/**
 * 
 * @fn      void EXTI_voidTriggerEdge(ExInterruptSource InterruptPin, TriggerEdge Edge)
 * @brief   Select trigger edge for specific interrupt pin 
 * @param   InterruptPin pin number  
 * @param   Edge         trigger edge  
 * @return  void
 * 	  
 */
void EXTI_voidTriggerEdge(ExInterruptSource InterruptPin, TriggerEdge Edge) 
{

	switch (InterruptPin) {
	case EXTI0:
		/* Select the interrupt mode  */
		switch (Edge) {
		case LOW_LEVEL:
			CLEAR_BIT(MCUCR, ISC00);
			CLEAR_BIT(MCUCR, ISC01);
			break;
		case LOGIC_CHANGE:
			SET_BIT(MCUCR, ISC00);
			CLEAR_BIT(MCUCR, ISC01);
			break;
		case FALLING_EDGE:
			CLEAR_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
		default:
		/* Do nothing */
		break ;

		}
	break;

	case EXTI1:
		switch (Edge) {
		case LOW_LEVEL:
			CLEAR_BIT(MCUCR, ISC10);
			CLEAR_BIT(MCUCR, ISC11);
			break;
		case LOGIC_CHANGE:
			SET_BIT(MCUCR, ISC10);
			CLEAR_BIT(MCUCR, ISC11);
			break;
		case FALLING_EDGE:
			CLEAR_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
			break;
		default:
		/* Do nothing */
		break ;
		}
	break;
		
	case EXTI2:
		switch (Edge) {
		case FALLING_EDGE:
			CLEAR_BIT(MCUCSR, ISC2);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCSR, ISC2);
			break;
		default:
			SET_BIT(MCUCSR, ISC2);
		}
	break;
	
	default:
		/* Do nothing */
	break ;
	}
}

/**
 * 
 * @fn      u8 EXTI_u8GetFlag(ExInterruptSource InterruptPin)
 * @brief   Check if the interrupt flag is enabled or not  
 * @param   InterruptPin pin number   
 * @return  True or False
 * 	  
 */
u8 EXTI_u8GetFlag(ExInterruptSource InterruptPin) 
{

	u8 Local_u8Result = 0;
	//check if  specific interrupt flag is up
	if (InterruptPin == EXTI0) {
		Local_u8Result = GET_BIT(GIFR, INTF0);
	}
	else if(InterruptPin==EXTI1)
	{
		Local_u8Result= GET_BIT(GIFR,INTF1);
	}
	else if(InterruptPin==EXTI2)
	{
		Local_u8Result= GET_BIT(GIFR,INTF2);
	}

	return Local_u8Result;
}

/**
 * 
 * @fn      void EXTI_u8SetFlag(ExInterruptSource InterruptPin) 
 * @brief   Enable the interrupt flag bit of external interrupt pin  
 * @param   InterruptPin pin number   
 * @return  void
 * 	  
 */
void EXTI_u8SetFlag(ExInterruptSource InterruptPin) 
{

	switch (InterruptPin) {

	case EXTI0:		SET_BIT(GIFR,INTF0);	break;
	case EXTI1:		SET_BIT(GIFR,INTF1);	break;
	case EXTI2:		SET_BIT(GIFR,INTF2);	break;
	}

}

/**
 * 
 * @fn      void EXTI_u8ClearFlag(ExInterruptSource InterruptPin) 
 * @brief   Clear the interrupt flag bit of external interrupt pin  
 * @param   InterruptPin pin number   
 * @return  void
 * 	  
 */
void EXTI_u8ClearFlag(ExInterruptSource InterruptPin) 
{

		/* The flag is cleared by writing logic one */
	switch (InterruptPin) {

	case EXTI0:		SET_BIT(GIFR,INTF0);	break;
	case EXTI1:		SET_BIT(GIFR,INTF1);	break;
	case EXTI2:		SET_BIT(GIFR,INTF2);	break;
	}

}

/**
 * 
 * @fn      void EXTI_voidSetCallBack(ExInterruptSource InterruptPin, void (*LocalPtr)(void))
 * @brief   Send the function that you want excute to ISR   
 * @param   InterruptPin pin number  
 * @param   LocalPtr     Pointer to the function (its name)   
 * @return  void
 * 	  
 */
void EXTI_voidSetCallBack(ExInterruptSource InterruptPin, void (*LocalPtr)(void)) 
{

	switch (InterruptPin) {
	case EXTI0:
		INT0_Fptr = LocalPtr;
		break;
	case EXTI1:
		INT1_Fptr = LocalPtr;
		break;
	case EXTI2:
		INT2_Fptr = LocalPtr;
		break;
	}
}

/**************ISR***************/

ISR(INT0_vect) {
	/* Check if user put a function */
	if (INT0_Fptr != NULLPTR) {

		INT0_Fptr();
	}
}

ISR(INT1_vect) {
	/* Check if user put a function */
	if (INT1_Fptr != NULLPTR) {

		INT1_Fptr();
	}
}

ISR(INT2_vect)
{
	/* Check if user put a function */
	if (INT2_Fptr != NULLPTR) {

		INT2_Fptr();
	}
}
