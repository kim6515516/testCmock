#include "unity.h"
#include "GetFileSystemInfo.h"
#include "MockGetFilePoint.h"

char *outputDf;
diskSpaceStatList *ptDiskSpaceStatList;
FILE *pMockFile;
filePointAndErrno filePointer;

void setUp(void)
{
    outputDf = "Filesystem       1B-blocks        Used   Available Use% Mounted on\n\
    /dev/sda1      52760793088 14228803584 35845013504  29% /";
    pMockFile = fmemopen(outputDf, strlen(outputDf), "rw");
    filePointer.pOpen = pMockFile;
    filePointer.terrno = 0;

    ptDiskSpaceStatList = (diskSpaceStatList *)malloc(sizeof(diskSpaceStatList));
    strcpy(ptDiskSpaceStatList->fileSystem[0].fileSystemName, "/dev/sda1");
    strcpy(ptDiskSpaceStatList->fileSystem[0].blockSize, "52760793088");
    strcpy(ptDiskSpaceStatList->fileSystem[0].used, "14228803584");
    strcpy(ptDiskSpaceStatList->fileSystem[0].avalable, "35845013504");
    strcpy(ptDiskSpaceStatList->fileSystem[0].usagePercent, "29%");
    strcpy(ptDiskSpaceStatList->fileSystem[0].mountOn, "/");
}

void tearDown(void)
{
    free(ptDiskSpaceStatList);
}

void test_GetFileSystemsInfo(void)
{
    GetFilePoint_ExpectAndReturn("df -B 1", filePointer);  /* make a mock for getFilePointFromPopen(); */
    diskSpaceStatList *pDiskSpaceStatList = GetFileSystemInfo();  /* get output of "df -B 1" using mocking ; */
    TEST_ASSERT_EQUAL_STRING(ptDiskSpaceStatList->fileSystem[0].fileSystemName, pDiskSpaceStatList->fileSystem[1].fileSystemName);
    free(pDiskSpaceStatList);
}

void test_GetFileSystemsInfoFailedToCasePopenError(void)
{
    filePointer.pOpen = NULL;
    filePointer.terrno = 1;
    GetFilePoint_ExpectAndReturn("df -B 1", filePointer);  /* make a mock for getFilePointFromPopen(); */
    diskSpaceStatList *pDiskSpaceStatList = GetFileSystemInfo();  /* get output of "df -B 1" using mocking ; */

    if (pDiskSpaceStatList->terrno != 0) {
         TEST_FAIL_MESSAGE("GetFileSystemInfo Failed : popen() error");
    }
    free(pDiskSpaceStatList);
}

void test_GetFileSystemsInfoFailedToCaseWrongOutFromCommand(void)
{
    char *wrongOutput = "not foufdf dfs asdfsdf fsdf adfs sdlsdlflsd asdf";
    pMockFile = fmemopen(wrongOutput, strlen(wrongOutput), "rw");
    filePointer.pOpen = pMockFile;
    filePointer.terrno = 0;
    GetFilePoint_ExpectAndReturn("df -B 1", filePointer);  /* make a mock for getFilePointFromPopen(); */
    diskSpaceStatList *pDiskSpaceStatList = GetFileSystemInfo();  /* get output of "df -B 1" using mocking ; */
    if (pDiskSpaceStatList->terrno != 0) {
         TEST_FAIL_MESSAGE("GetFileSystemInfo Failed : wrong output from command");
    }
    free(pDiskSpaceStatList);
}
void test_GetFileSystemsInfoFailedToCaseNotFoundCommand(void)
{
    char *wrongOutput = "";
    pMockFile = fmemopen(wrongOutput, strlen(wrongOutput), "rw");
    if (pMockFile == NULL) {
        filePointer.pOpen = NULL;
        filePointer.terrno = 1;
    } else {
        filePointer.pOpen = pMockFile;
        filePointer.terrno = 0;
    }
    GetFilePoint_ExpectAndReturn("df -B 1", filePointer);  /* make a mock for getFilePointFromPopen(); */
    diskSpaceStatList *pDiskSpaceStatList = GetFileSystemInfo();  /* get output of "df -B 1" using mocking ; */
    if (pDiskSpaceStatList->terrno != 0) {
         TEST_FAIL_MESSAGE("GetFileSystemInfo Failed : not find Command");
    }
    free(pDiskSpaceStatList);
}
