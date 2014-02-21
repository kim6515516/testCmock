#include "GetFileSystemInfo.h"
#include "GetFilePoint.h"


diskSpaceStatList *GetFileSystemInfo(void)
{
    diskSpaceStatList *pDiskSpaceStatList = (diskSpaceStatList *)malloc(sizeof(diskSpaceStatList));
    char outputFromDfCommandBuffer[BUFF_SIZE] = {}; /* temp buffer for fgets() */
    char *pStrtok = NULL;  /* pointer of strtok() */
    char *pCmd = "df -B 1";
    FILE *pfPopen = NULL; /* File pointer of popen(); */
    filePointAndErrno filePointer = {NULL, 0};
    pDiskSpaceStatList->terrno = 0;

    filePointer = GetFilePoint(pCmd);
    if (filePointer.terrno != 0) {
        pDiskSpaceStatList->terrno = 1;
        return pDiskSpaceStatList;
    }

    pfPopen = filePointer.pOpen;
    while (fgets(outputFromDfCommandBuffer, BUFF_SIZE, pfPopen)) { /* read from fpPopen and save it as buffer */
        pStrtok = strtok(outputFromDfCommandBuffer, " ");
        if (pStrtok == NULL)
            break;
        strcpy(pDiskSpaceStatList->fileSystem[pDiskSpaceStatList->listCount].fileSystemName, pStrtok);
        pStrtok = strtok(NULL, " ");
        if (pStrtok == NULL)
            break;
        strcpy(pDiskSpaceStatList->fileSystem[pDiskSpaceStatList->listCount].blockSize, pStrtok);
        pStrtok = strtok(NULL, " ");
        if (pStrtok == NULL)
            break;
        strcpy(pDiskSpaceStatList->fileSystem[pDiskSpaceStatList->listCount].used, pStrtok);
        pStrtok = strtok(NULL, " ");
        if (pStrtok == NULL)
            break;
        strcpy(pDiskSpaceStatList->fileSystem[pDiskSpaceStatList->listCount].avalable, pStrtok);
        pStrtok = strtok(NULL, " ");
        if (pStrtok == NULL)
            break;
        strcpy(pDiskSpaceStatList->fileSystem[pDiskSpaceStatList->listCount].usagePercent, pStrtok);
        pStrtok = strtok(NULL, " ");
        if (pStrtok == NULL)
            break;
        strcpy(pDiskSpaceStatList->fileSystem[pDiskSpaceStatList->listCount].mountOn, pStrtok);
        pDiskSpaceStatList->listCount++;
    }

    if (pDiskSpaceStatList->listCount == 0) {  /* if exucte a invaild command */
        pDiskSpaceStatList->terrno = 2;
        return pDiskSpaceStatList;
    }

    if (strcmp(pDiskSpaceStatList->fileSystem[0].fileSystemName, "Filesystem") != 0) { /* if get a wrong output from command */
        pDiskSpaceStatList->terrno = 3;
        return pDiskSpaceStatList;
    }

    pclose(pfPopen);
    return pDiskSpaceStatList;
}

