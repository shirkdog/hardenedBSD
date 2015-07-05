/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_PositiveInteger(void);
extern void test_NegativeInteger(void);
extern void test_PositiveFraction(void);
extern void test_NegativeFraction(void);
extern void test_PositiveMsFraction(void);
extern void test_NegativeMsFraction(void);
extern void test_InvalidChars(void);


//=======Test Reset Option=====
void resetTest()
{
  tearDown();
  setUp();
}

char *progname;


//=======MAIN=====
int main(int argc, char *argv[])
{
  progname = argv[0];
  Unity.TestFile = "strtolfp.c";
  UnityBegin("strtolfp.c");
  RUN_TEST(test_PositiveInteger, 11);
  RUN_TEST(test_NegativeInteger, 25);
  RUN_TEST(test_PositiveFraction, 42);
  RUN_TEST(test_NegativeFraction, 56);
  RUN_TEST(test_PositiveMsFraction, 73);
  RUN_TEST(test_NegativeMsFraction, 89);
  RUN_TEST(test_InvalidChars, 107);

  return (UnityEnd());
}
