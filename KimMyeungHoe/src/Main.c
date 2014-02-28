#include "FileSystemInfo.h"

void main(void)
{
    struct diskSpaceStats *pDiskSpaceStats = NULL;
    pDiskSpaceStats = GetFileSystemInfo();

    if (pDiskSpaceStats == NULL)
        printf("failed to get a infomation of filesystem\n");
    if (pDiskSpaceStats->result == 1)
        printf("failed to peopen()\n");
    if (pDiskSpaceStats->result == 2)
        printf("failed to excute a commnd n");

}
