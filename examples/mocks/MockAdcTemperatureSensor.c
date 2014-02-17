/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "MockAdcTemperatureSensor.h"

typedef struct _CMOCK_Adc_StartTemperatureSensorConversion_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;

} CMOCK_Adc_StartTemperatureSensorConversion_CALL_INSTANCE;

typedef struct _CMOCK_Adc_TemperatureSensorSampleReady_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  bool ReturnVal;

} CMOCK_Adc_TemperatureSensorSampleReady_CALL_INSTANCE;

typedef struct _CMOCK_Adc_ReadTemperatureSensor_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  uint16 ReturnVal;

} CMOCK_Adc_ReadTemperatureSensor_CALL_INSTANCE;

static struct MockAdcTemperatureSensorInstance
{
  CMOCK_MEM_INDEX_TYPE Adc_StartTemperatureSensorConversion_CallInstance;
  CMOCK_MEM_INDEX_TYPE Adc_TemperatureSensorSampleReady_CallInstance;
  CMOCK_MEM_INDEX_TYPE Adc_ReadTemperatureSensor_CallInstance;
} Mock;

extern jmp_buf AbortFrame;

void MockAdcTemperatureSensor_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Adc_StartTemperatureSensorConversion_CallInstance, cmock_line, "Function 'Adc_StartTemperatureSensorConversion' called less times than expected.");
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Adc_TemperatureSensorSampleReady_CallInstance, cmock_line, "Function 'Adc_TemperatureSensorSampleReady' called less times than expected.");
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Adc_ReadTemperatureSensor_CallInstance, cmock_line, "Function 'Adc_ReadTemperatureSensor' called less times than expected.");
}

void MockAdcTemperatureSensor_Init(void)
{
  MockAdcTemperatureSensor_Destroy();
}

void MockAdcTemperatureSensor_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

void Adc_StartTemperatureSensorConversion(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Adc_StartTemperatureSensorConversion_CALL_INSTANCE* cmock_call_instance = (CMOCK_Adc_StartTemperatureSensorConversion_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Adc_StartTemperatureSensorConversion_CallInstance);
  Mock.Adc_StartTemperatureSensorConversion_CallInstance = CMock_Guts_MemNext(Mock.Adc_StartTemperatureSensorConversion_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'Adc_StartTemperatureSensorConversion' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
}

void Adc_StartTemperatureSensorConversion_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Adc_StartTemperatureSensorConversion_CALL_INSTANCE));
  CMOCK_Adc_StartTemperatureSensorConversion_CALL_INSTANCE* cmock_call_instance = (CMOCK_Adc_StartTemperatureSensorConversion_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.Adc_StartTemperatureSensorConversion_CallInstance = CMock_Guts_MemChain(Mock.Adc_StartTemperatureSensorConversion_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
}

bool Adc_TemperatureSensorSampleReady(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Adc_TemperatureSensorSampleReady_CALL_INSTANCE* cmock_call_instance = (CMOCK_Adc_TemperatureSensorSampleReady_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Adc_TemperatureSensorSampleReady_CallInstance);
  Mock.Adc_TemperatureSensorSampleReady_CallInstance = CMock_Guts_MemNext(Mock.Adc_TemperatureSensorSampleReady_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'Adc_TemperatureSensorSampleReady' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  return cmock_call_instance->ReturnVal;
}

void Adc_TemperatureSensorSampleReady_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, bool cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Adc_TemperatureSensorSampleReady_CALL_INSTANCE));
  CMOCK_Adc_TemperatureSensorSampleReady_CALL_INSTANCE* cmock_call_instance = (CMOCK_Adc_TemperatureSensorSampleReady_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.Adc_TemperatureSensorSampleReady_CallInstance = CMock_Guts_MemChain(Mock.Adc_TemperatureSensorSampleReady_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

uint16 Adc_ReadTemperatureSensor(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Adc_ReadTemperatureSensor_CALL_INSTANCE* cmock_call_instance = (CMOCK_Adc_ReadTemperatureSensor_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Adc_ReadTemperatureSensor_CallInstance);
  Mock.Adc_ReadTemperatureSensor_CallInstance = CMock_Guts_MemNext(Mock.Adc_ReadTemperatureSensor_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'Adc_ReadTemperatureSensor' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  return cmock_call_instance->ReturnVal;
}

void Adc_ReadTemperatureSensor_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint16 cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Adc_ReadTemperatureSensor_CALL_INSTANCE));
  CMOCK_Adc_ReadTemperatureSensor_CALL_INSTANCE* cmock_call_instance = (CMOCK_Adc_ReadTemperatureSensor_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.Adc_ReadTemperatureSensor_CallInstance = CMock_Guts_MemChain(Mock.Adc_ReadTemperatureSensor_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

