/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCKTIMERCONDUCTOR_H
#define _MOCKTIMERCONDUCTOR_H

#include "Types.h"
#include "TimerConductor.h"

void MockTimerConductor_Init(void);
void MockTimerConductor_Destroy(void);
void MockTimerConductor_Verify(void);




#define TimerConductor_Init_Expect() TimerConductor_Init_CMockExpect(__LINE__)
void TimerConductor_Init_CMockExpect(UNITY_LINE_TYPE cmock_line);
#define TimerConductor_Run_Expect() TimerConductor_Run_CMockExpect(__LINE__)
void TimerConductor_Run_CMockExpect(UNITY_LINE_TYPE cmock_line);

#endif