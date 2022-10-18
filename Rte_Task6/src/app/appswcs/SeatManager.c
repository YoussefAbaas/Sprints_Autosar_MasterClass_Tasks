/**
 *
 * \file SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 10/4/2022 02:59 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatManager.h"


/**
 *
 * Runnable SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
 *
 */

void SeatManager_AutoHeight (void)
{
	Std_ReturnType status;
	StepMotorStepType Step;
	SensorPositionType position;
	SensorWeightType weight;
	boolean adjust_motor = FALSE;

	/* Server Call Points */
	status = Rte_Call_rpHeightSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);

	switch(position)
	{
		case SENSOR_POSITION_STEP_0:
		     if(weight>60)
			 {
				Step=MOTOR_STEP_PLUS;
				adjust_motor = TRUE;
			 }
			 break;
	    case SENSOR_POSITION_STEP_1:
		     if(weight>80)
			 {
				Step=MOTOR_STEP_PLUS;
				adjust_motor = TRUE;
			 }
			 else if(weight>=60&&weight<=80)
			 {
				/*Position OK*/
			 }
			 else
			 {
			    Step=MOTOR_STEP_MINUS;
				adjust_motor = TRUE;
			 }
			 break;
		case SENSOR_POSITION_STEP_2:
		     if(weight>100)
			 {
				Step=MOTOR_STEP_PLUS;
				adjust_motor = TRUE;
			 }
			 else if(weight>=80&&weight<=100)
			 {
				/*Position OK*/
			 }
			 else
			 {
			    Step=MOTOR_STEP_MINUS;	
				adjust_motor = TRUE;
			 }
			 break;
		case SENSOR_POSITION_STEP_3:
		     if(weight<100)
			 {
				Step=MOTOR_STEP_MINUS;
				adjust_motor = TRUE;
			 }
			 break;
		default:
			break;
		}

	if(adjust_motor)
	status = Rte_Call_rpHeightMotor_Move(Step);
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *
 */

void SeatManager_AutoIncline (void)
{
	Std_ReturnType status;
	StepMotorStepType Step;
	SensorPositionType position;
	SensorWeightType weight;
	boolean adjust_motor = FALSE;

	/* Server Call Points */
	
	status = Rte_Call_rpInclineSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);

	switch(position)
	{
		case SENSOR_POSITION_STEP_0:
		     if(weight>60)
			 {
				Step=MOTOR_STEP_PLUS;
				adjust_motor = TRUE;
			 }
			 break;
	    case SENSOR_POSITION_STEP_1:
		     if(weight>80)
			 {
				Step=MOTOR_STEP_PLUS;
				adjust_motor = TRUE;
			 }
			 else if(weight>=60&&weight<=80)
			 {
				/*Position OK*/
			 }
			 else
			 {
			    Step=MOTOR_STEP_MINUS;
				adjust_motor = TRUE;
			 }
			 break;
		case SENSOR_POSITION_STEP_2:
		     if(weight>100)
			 {
				Step=MOTOR_STEP_PLUS;
				adjust_motor = TRUE;
			 }
			 else if(weight>=80&&weight<=100)
			 {
				/*Position OK*/
			 }
			 else
			 {
			    Step=MOTOR_STEP_MINUS;
				adjust_motor = TRUE;
			 }
			 break;
		case SENSOR_POSITION_STEP_3:
		     if(weight<100)
			 {
				Step=MOTOR_STEP_MINUS;
				adjust_motor = TRUE;
			 }
			 break;
		default:
			break;
		}
	    if(adjust_motor)
		status = Rte_Call_rpInclineMotor_Move(Step);
	
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *
 */

void SeatManager_AutoSlide (void)
{
	Std_ReturnType status;
	StepMotorStepType Step;
	SensorPositionType position;
	SensorWeightType weight;
	boolean adjust_motor = FALSE;

	/* Server Call Points */
	
	status = Rte_Call_rpSlideSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);

	switch(position)
	{
		case SENSOR_POSITION_STEP_0:
		     if(weight>60)
			 {
				Step=MOTOR_STEP_PLUS;
				adjust_motor = TRUE;
			 }
			 break;
	    case SENSOR_POSITION_STEP_1:
		     if(weight>80)
			 {
				Step=MOTOR_STEP_PLUS;
				adjust_motor = TRUE;
			 }
			 else if(weight>=60&&weight<=80)
			 {
				/*Position OK*/
			 }
			 else
			 {
			    Step=MOTOR_STEP_MINUS;	
				adjust_motor = TRUE;
			 }
			 break;
		case SENSOR_POSITION_STEP_2:
		     if(weight>100)
			 {
				Step=MOTOR_STEP_PLUS;
				adjust_motor = TRUE;
			 }
			 else if(weight>=80&&weight<=100)
			 {
				/*Position OK*/
			 }
			 else
			 {
			    Step=MOTOR_STEP_MINUS;	
				adjust_motor = TRUE;
			 }
			 break;
		case SENSOR_POSITION_STEP_3:
		     if(weight<100)
			 {
				Step=MOTOR_STEP_MINUS;
				adjust_motor = TRUE;
			 }
			 break;
		default:
			break;
		}
	    
	    if(adjust_motor)
		status = Rte_Call_rpSlideMotor_Move(Step);
	
}


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
	MultiStateBtnType HeightBtnState;
	StepMotorStepType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	
	/*Software Logic*/
	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
		Step=MOTOR_STEP_MINUS;
	else if(HeightBtnState == MULTI_STATE_BTN_PLUS)
		Step=MOTOR_STEP_PLUS;
	
	/* Server Call Points */
	status = Rte_Call_rpHeightMotor_Move(Step);
	
}


/**
 *
 * Runnable SeatManager_SetInclice
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatManager_SetIncline (void)
{
	Std_ReturnType status;
	MultiStateBtnType InclineBtnState;
	StepMotorStepType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	
	/*Software Logic*/
	if(InclineBtnState == MULTI_STATE_BTN_MINUS)
		Step=MOTOR_STEP_MINUS;
	else if(InclineBtnState == MULTI_STATE_BTN_PLUS)
		Step=MOTOR_STEP_PLUS;
	
	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Move(Step);
	
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
	MultiStateBtnType SlideBtnState;
	StepMotorStepType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	
	/*Software Logic*/
	if(SlideBtnState == MULTI_STATE_BTN_MINUS)
		Step=MOTOR_STEP_MINUS;
	else if(SlideBtnState == MULTI_STATE_BTN_PLUS)
		Step=MOTOR_STEP_PLUS;
	
	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Move(Step);
	
}

