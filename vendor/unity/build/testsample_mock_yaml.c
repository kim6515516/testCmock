/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
    CEXCEPTION_T e; \
    Try { \
      CMock_Init(); \
      setUp(); \
      TestFunc(); \
      CMock_Verify(); \
    } Catch(e) { TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!"); } \
  } \
  CMock_Destroy(); \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include "cmock.h"
#include "two.h"
#include "three.h"
#include <four.h>
#include <setjmp.h>
#include <stdio.h>
#include "CException.h"
#include "funky.h"
#include <setjmp.h>
#include "Mockstanky.h"

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_TheFirstThingToTest(void);
extern void test_TheSecondThingToTest(void);


//=======Mock Management=====
static void CMock_Init(void)
{
  Mockstanky_Init();
}
static void CMock_Verify(void)
{
  Mockstanky_Verify();
}
static void CMock_Destroy(void)
{
  Mockstanky_Destroy();
}

//=======Suite Setup=====
static int suite_setup(void)
{
a_yaml_setup();
}

//=======Test Reset Option=====
void resetTest()
{
  CMock_Verify();
  CMock_Destroy();
  tearDown();
  CMock_Init();
  setUp();
}


//=======MAIN=====
int main(void)
{
  suite_setup();
  Unity.TestFile = "test/testdata/mocksample.c";
  UnityBegin();
  RUN_TEST(test_TheFirstThingToTest, 21);
  RUN_TEST(test_TheSecondThingToTest, 43);

  return (UnityEnd());
}
