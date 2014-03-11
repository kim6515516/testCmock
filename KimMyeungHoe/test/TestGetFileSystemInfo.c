#include "unity.h"
#include "CException.h"
#include "FileSystemInfo.h"
#include "MockFilePointer.h"

char *outputDf;
struct diskSpaceStats *pdiskSpaceStats;
FILE *pMockFile;
struct filePointAndErrno fileDescript;
CEXCEPTION_T e;

void setUp(void)
{
    outputDf = "Filesystem       1B-blocks        Used   Available Use% Mounted on\n\
    /dev/sda1      52760793088 14228803584 35845013504  29% /";
    pMockFile = fmemopen(outputDf, strlen(outputDf), "rw");
    fileDescript.pOpen = pMockFile;
    fileDescript.result = 0;

    pdiskSpaceStats = (struct diskSpaceStats *)malloc(sizeof(struct diskSpaceStats));
    strcpy(pdiskSpaceStats->fileSystem[0].fileSystemName, "/dev/sda1");
    strcpy(pdiskSpaceStats->fileSystem[0].blockSize, "52760793088");
    strcpy(pdiskSpaceStats->fileSystem[0].used, "14228803584");
    strcpy(pdiskSpaceStats->fileSystem[0].avalable, "35845013504");
    strcpy(pdiskSpaceStats->fileSystem[0].usagePercent, "29%");
    strcpy(pdiskSpaceStats->fileSystem[0].mountOn, "/");
}

void tearDown(void)
{
    free(pdiskSpaceStats);
}

void test_GetFileSystemsInfo(void)
{
    GetFilePoint_ExpectAndReturn("df -B 1", fileDescript);/* make a mock for getFilePointFromPopen() */
    struct diskSpaceStats *pdiskSpaceStats = GetFileSystemInfo();/* get output of "df -B 1" using mocking */
    TEST_ASSERT_EQUAL_STRING(pdiskSpaceStats->fileSystem[0].fileSystemName, \
    pdiskSpaceStats->fileSystem[1].fileSystemName);
    free(pdiskSpaceStats);
}

void test_GetFileSystemsInfoFailedToCasePopenError(void)
{
    fileDescript.pOpen = NULL;
    fileDescript.result = 1;
    GetFilePoint_ExpectAndReturn("df -B 1", fileDescript);/* make a mock for getFilePointFromPopen() */
    struct diskSpaceStats *pdiskSpaceStats = GetFileSystemInfo();/* get output of "df -B 1" using mocking */

    Try {
        if (pdiskSpaceStats->result != 0) {
            Throw(0x00);
        }
    }
    Catch(e) {
        TEST_FAIL_MESSAGE("GetFileSystemInfo Failed : popen() error in Exception");
    }

    free(pdiskSpaceStats);
}

void test_GetFileSystemsInfoFailedToCaseWrongOutFromCommand(void)
{
    char *wrongOutput = "not foufdf dfs asdfsdf fsdf adfs sdlsdlflsd asdf";
    pMockFile = fmemopen(wrongOutput, strlen(wrongOutput), "rw");
    fileDescript.pOpen = pMockFile;
    fileDescript.result = 0;
    GetFilePoint_ExpectAndReturn("df -B 1", fileDescript);/* make a mock for getFilePointFromPopen() */

    struct diskSpaceStats *pdiskSpaceStats = GetFileSystemInfo();/* get output of "df -B 1" using mocking */
    Try {
        if (pdiskSpaceStats->result != 0) {
            Throw(0x00);
        }
    }
    Catch(e) {
        TEST_FAIL_MESSAGE("GetFileSystemInfo Failed : wrong output from command in Exception");
    }

    free(pdiskSpaceStats);
}
void test_GetFileSystemsInfoFailedToCaseNotFoundCommand(void)
{
    char *wrongOutput = "";
    pMockFile = fmemopen(wrongOutput, strlen(wrongOutput), "rw");
    if (pMockFile == NULL) {
        fileDescript.pOpen = NULL;
        fileDescript.result = 1;
    } else {
        fileDescript.pOpen = pMockFile;
        fileDescript.result = 0;
    }

    GetFilePoint_ExpectAndReturn("df -B 1", fileDescript);/* make a mock for getFilePointFromPopen() */
    struct diskSpaceStats *pdiskSpaceStats = GetFileSystemInfo();/* get output of "df -B 1" using mocking */
    Try {
        if (pdiskSpaceStats->result != 0) {
            Throw(0x00);
        }
    }
    Catch(e) {
        TEST_FAIL_MESSAGE("GetFileSystemInfo Failed : not find Command in Exception");
    }

    free(pdiskSpaceStats);
}
