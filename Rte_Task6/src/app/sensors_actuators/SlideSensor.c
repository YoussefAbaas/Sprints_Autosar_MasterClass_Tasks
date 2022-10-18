/**
 *
 * \file SlideSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SlideSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 10/4/2022 09:07 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SlideSensor.h"


/**
 *
 * Runnable SlideSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideSensor_GetPosition
 *
 */

void SlideSensor_GetPosition (SensorPositionType* position)
{
	Std_ReturnType status;
	IoPositionSensorReadingType Position;

	/* Server Call Points */
	status = Rte_Call_rpIOGetSlide_IOGet(&Position);

	if(Position==0)*position=SENSOR_POSITION_STEP_0;
	else if(Position>0&&Position<=64)*position=SENSOR_POSITION_STEP_1;
	else if(Position>64&&Position<=192)*position=SENSOR_POSITION_STEP_2;
	else if(Position>192&&Position<=255)*position=SENSOR_POSITION_STEP_3;
	
	
}

