#include "GetFileSystemInfo.h"

void main(void)
{
	diskSpaceStatList *pDiskSpaceStatList = NULL;
	pDiskSpaceStatList = GetFileSystemInfo();
    
    if (pDiskSpaceStatList == NULL) {
        printf("failed to get a infomation of filesystem\n");
    }
    if (pDiskSpaceStatList->terrno == 1) {    	
        printf("failed to peopen() \n");
    }
    if (pDiskSpaceStatList->terrno == 2) {    	
        printf("failed to excute a commnd \n");
    }
}
