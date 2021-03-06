/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "MockAdcHardwareConfigurator.h"

typedef struct _CMOCK_Adc_Reset_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;

} CMOCK_Adc_Reset_CALL_INSTANCE;

typedef struct _CMOCK_Adc_ConfigureMode_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;

} CMOCK_Adc_ConfigureMode_CALL_INSTANCE;

typedef struct _CMOCK_Adc_EnableTemperatureChannel_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;

} CMOCK_Adc_EnableTemperatureChannel_CALL_INSTANCE;

static struct MockAdcHardwareConfiguratorInstance
{
  CMOCK_MEM_INDEX_TYPE Adc_Reset_CallInstance;
  CMOCK_MEM_INDEX_TYPE Adc_ConfigureMode_CallInstance;
  CMOCK_MEM_INDEX_TYPE Adc_EnableTemperatureChannel_CallInstance;
} Mock;

extern jmp_buf AbortFrame;

void MockAdcHardwareConfigurator_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Adc_Reset_CallInstance, cmock_line, "Function 'Adc_Reset' called less times than expected.");
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Adc_ConfigureMode_CallInstance, cmock_line, "Function 'Adc_ConfigureMode' called less times than expected.");
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Adc_EnableTemperatureChannel_CallInstance, cmock_line, "Function 'Adc_EnableTemperatureChannel' called less times than expected.");
}

void MockAdcHardwareConfigurator_Init(void)
{
  MockAdcHardwareConfigurator_Destroy();
}

void MockAdcHardwareConfigurator_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

void Adc_Reset(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Adc_Reset_CALL_INSTANCE* cmock_call_instance = (CMOCK_Adc_Reset_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Adc_Reset_CallInstance);
  Mock.Adc_Reset_CallInstance = CMock_Guts_MemNext(Mock.Adc_Reset_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'Adc_Reset' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
}

void Adc_Reset_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Adc_Reset_CALL_INSTANCE));
  CMOCK_Adc_Reset_CALL_INSTANCE* cmock_call_instance = (CMOCK_Adc_Reset_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.Adc_Reset_CallInstance = CMock_Guts_MemChain(Mock.Adc_Reset_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
}

void Adc_ConfigureMode(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Adc_ConfigureMode_CALL_INSTANCE* cmock_call_instance = (CMOCK_Adc_ConfigureMode_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Adc_ConfigureMode_CallInstance);
  Mock.Adc_ConfigureMode_CallInstance = CMock_Guts_MemNext(Mock.Adc_ConfigureMode_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'Adc_ConfigureMode' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
}

void Adc_ConfigureMode_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Adc_ConfigureMode_CALL_INSTANCE));
  CMOCK_Adc_ConfigureMode_CALL_INSTANCE* cmock_call_instance = (CMOCK_Adc_ConfigureMode_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.Adc_ConfigureMode_CallInstance = CMock_Guts_MemChain(Mock.Adc_ConfigureMode_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
}

void Adc_EnableTemperatureChannel(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Adc_EnableTemperatureChannel_CALL_INSTANCE* cmock_call_instance = (CMOCK_Adc_EnableTemperatureChannel_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Adc_EnableTemperatureChannel_CallInstance);
  Mock.Adc_EnableTemperatureChannel_CallInstance = CMock_Guts_MemNext(Mock.Adc_EnableTemperatureChannel_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'Adc_EnableTemperatureChannel' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
}

void Adc_EnableTemperatureChannel_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Adc_EnableTemperatureChannel_CALL_INSTANCE));
  CMOCK_Adc_EnableTemperatureChannel_CALL_INSTANCE* cmock_call_instance = (CMOCK_Adc_EnableTemperatureChannel_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.Adc_EnableTemperatureChannel_CallInstance = CMock_Guts_MemChain(Mock.Adc_EnableTemperatureChannel_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
}

