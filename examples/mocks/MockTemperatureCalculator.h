/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCKTEMPERATURECALCULATOR_H
#define _MOCKTEMPERATURECALCULATOR_H

#include "Types.h"
#include "TemperatureCalculator.h"

void MockTemperatureCalculator_Init(void);
void MockTemperatureCalculator_Destroy(void);
void MockTemperatureCalculator_Verify(void);




#define TemperatureCalculator_Calculate_ExpectAndReturn(millivolts, cmock_retval) TemperatureCalculator_Calculate_CMockExpectAndReturn(__LINE__, millivolts, cmock_retval)
void TemperatureCalculator_Calculate_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint16 millivolts, float cmock_to_return);

#endif