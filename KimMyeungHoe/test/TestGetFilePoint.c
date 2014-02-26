#include "unity.h"
#include "GetFilePoint.h"

char *outputDf;
struct filePointAndErrno fileDescript;

void setUp(void)
{
    outputDf = "df (GNU coreutils) 8.13\n\
Copyright (C) 2011 Free Software Foundation, Inc.\n\
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\n\
This is free software: you are free to change and redistribute it.\n\
There is NO WARRANTY, to the extent permitted by law.\n\
\n\
Written by Torbjörn Granlund, David MacKenzie, and Paul Eggert.";

}

void tearDown(void)
{

}

void test_GetFilePoint_ShouldReturnDfVersion(void)
{
    char buffReadFile[2000];
    struct filePointAndErrno filePointer;
    int len;

    fileDescript.pOpen = NULL;
    fileDescript.result = 0;

    memset(buffReadFile, 0, 2000);
    filePointer = GetFilePoint("df --version");
    if (filePointer.result != 0) {
         TEST_FAIL_MESSAGE("GetFilePoint Failed : error...");
    }
    len = fread(buffReadFile, 2000, 2000, filePointer.pOpen);
    buffReadFile[strlen(buffReadFile) - 1] = '\0';
    TEST_ASSERT_EQUAL_STRING(outputDf, buffReadFile);
}

void test_GetFilePoint_failedToCmdIsNull(void)
{
    char buffReadFile[2000];
    struct filePointAndErrno filePointer;
    fileDescript.pOpen = NULL;
    fileDescript.result = 0;
    filePointer = GetFilePoint(NULL);
    if (filePointer.result != 0) {
         TEST_FAIL_MESSAGE("GetFilePoint Failed : Command is NULL");
    }
}
