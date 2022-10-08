/**
 *
 * \file SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/14/2022 01:26 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatManager.h"


/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

void SeatManager_SetHeight (void)
{
	Std_ReturnType status;
	MultuStateBtnType HeightBtnState;
	StepMotorStepType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	
	/*Software Logic*/
	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
		Step=MOTOR_STEP_MINUS;
	else if(HeightBtnState == MULTI_STATE_BTN_PLUS)
		Step=MOTOR_STEP_PLUS;
	
	/* Server Call Points */
	status = Rte_Call_rpHeightMotor_Opr_HeightMotorMove(Step);
	
}


/**
 *
 * Runnable SeatManager_SetInclice
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatManager_SetInclice (void)
{
	Std_ReturnType status;
	MultuStateBtnType InclineBtnState;
	StepMotorStepType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	
	/*Software Logic*/
	if(InclineBtnState == MULTI_STATE_BTN_MINUS)
		Step=MOTOR_STEP_MINUS;
	else if(InclineBtnState == MULTI_STATE_BTN_PLUS)
		Step=MOTOR_STEP_PLUS;
	
	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Opr_HeightMotorMove(Step);
	
}


/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */

void SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	MultuStateBtnType SlideBtnState;
	StepMotorStepType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	
	/*Software Logic*/
	if(SlideBtnState == MULTI_STATE_BTN_MINUS)
		Step=MOTOR_STEP_MINUS;
	else if(SlideBtnState == MULTI_STATE_BTN_PLUS)
		Step=MOTOR_STEP_PLUS;
	
	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Opr_SlideMotorMove(Step);
	
}

