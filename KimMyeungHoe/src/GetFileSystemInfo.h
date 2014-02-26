#include <stdio.h>
#include <string.h>
#include "errno.h"

#define BUFF_SIZE 1024
#define STR_SIZE 100
#define STRUCT_LIST_SIZE 200

struct diskSpaceStat{
    char fileSystemName[STR_SIZE];
    char blockSize[STR_SIZE];
    char used[STR_SIZE];
    char avalable[STR_SIZE];
    char usagePercent[STR_SIZE];
    char mountOn[STR_SIZE];
};

struct diskSpaceStats {
    int listCount; /* count of dfPrintFormat list */
    int result;/* erron for result */
    struct diskSpaceStat fileSystem[STRUCT_LIST_SIZE];
};

struct diskSpaceStats *GetFileSystemInfo(void);/* saved result screen of "df -B 1" */

