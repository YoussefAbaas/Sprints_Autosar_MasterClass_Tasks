/**
 *
 * \file SlideMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SlideMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 10/4/2022 09:07 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SlideMotor.h"


/**
 *
 * Runnable SlideMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideMotor_Opr_SlideMotorMove
 *
 */

void SlideMotor_Move (StepMotorStepType Step)
{
	Std_ReturnType status;

	if(Step==MOTOR_STEP_PLUS)
	status = Rte_Call_rpIoSetSlide_IOSetForward();
	else if(Step==MOTOR_STEP_MINUS)
	status = Rte_Call_rpIoSetSlide_IOSetReverse();
	
}

