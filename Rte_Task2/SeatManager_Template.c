/**
 *
 * \file SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 10/1/2022 07:11 PM
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

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	
	/*Software Logic*/
	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	else if(HeightBtnState == MULTI_STATE_BTN_PLUS)
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
		
	
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

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	
	/*Software Logic*/
	if(InclineBtnState == MULTI_STATE_BTN_MINUS)
		Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS);
	else if(InclineBtnState == MULTI_STATE_BTN_PLUS)
		Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);
	
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

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	
	if(SlideBtnState == MULTI_STATE_BTN_MINUS)
		Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
	else if(SlideBtnState == MULTI_STATE_BTN_PLUS)
		Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
	
}

