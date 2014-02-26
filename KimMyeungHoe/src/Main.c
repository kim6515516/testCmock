#include "GetFileSystemInfo.h"

void main(void)
{
	diskSpaceStats *pDiskSpaceStats = NULL;
	pDiskSpaceStats = GetFileSystemInfo();
    
    if (pDiskSpaceStats == NULL) {
        printf("failed to get a infomation of filesystem\n");
    }
    if (pDiskSpaceStats->terrno == 1) {    	
        printf("failed to peopen() \n");
    }
    if (pDiskSpaceStats->terrno == 2) {    	
        printf("failed to excute a commnd \n");
    }
}
