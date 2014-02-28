#include "FileSystemInfo.h"
#include "FilePointer.h"

struct diskSpaceStats *GetFileSystemInfo(void)
{
    struct diskSpaceStats *pDiskSpaceStats = (struct diskSpaceStats *)malloc(sizeof(struct diskSpaceStats));
    char outputFromDfCommandBuffer[BUFF_SIZE] = {};/* temp buffer for fgets() */
    char *pStrtok = NULL;/* pointer of strtok() */
    char *pCommand = "df -B 1";
    FILE *pFilePointer = NULL;/* File pointer of popen(); */
    struct filePointAndErrno fileDescription = {NULL, 0};
    pDiskSpaceStats->result = 0;

    fileDescription = GetFilePoint(pCommand);
    if (fileDescription.result != 0) {
        pDiskSpaceStats->result = 1;
        return pDiskSpaceStats;
    }

    pFilePointer = fileDescription.pOpen;
    while (fgets(outputFromDfCommandBuffer, BUFF_SIZE, pFilePointer)) {/* read from fpPopen and save it as buffer */
        pStrtok = strtok(outputFromDfCommandBuffer, " ");
        if (pStrtok == NULL)
            break;
        strcpy(pDiskSpaceStats->fileSystem[pDiskSpaceStats->listCount].fileSystemName, pStrtok);
        pStrtok = strtok(NULL, " ");
        if (pStrtok == NULL)
            break;
        strcpy(pDiskSpaceStats->fileSystem[pDiskSpaceStats->listCount].blockSize, pStrtok);
        pStrtok = strtok(NULL, " ");
        if (pStrtok == NULL)
            break;
        strcpy(pDiskSpaceStats->fileSystem[pDiskSpaceStats->listCount].used, pStrtok);
        pStrtok = strtok(NULL, " ");
        if (pStrtok == NULL)
            break;
        strcpy(pDiskSpaceStats->fileSystem[pDiskSpaceStats->listCount].avalable, pStrtok);
        pStrtok = strtok(NULL, " ");
        if (pStrtok == NULL)
            break;
        strcpy(pDiskSpaceStats->fileSystem[pDiskSpaceStats->listCount].usagePercent, pStrtok);
        pStrtok = strtok(NULL, " ");
        if (pStrtok == NULL)
            break;
        strcpy(pDiskSpaceStats->fileSystem[pDiskSpaceStats->listCount].mountOn, pStrtok);
        pDiskSpaceStats->listCount++;
    }
    if (pDiskSpaceStats->listCount == 0) {/* if command is invaild */
        pDiskSpaceStats->result = 2;
        return pDiskSpaceStats;
    }
    /* if command has wrong output */
    if (strcmp(pDiskSpaceStats->fileSystem[0].fileSystemName, "Filesystem") != 0) {
        pDiskSpaceStats->result = 3;
        return pDiskSpaceStats;
    }

    pclose(pFilePointer);
    return pDiskSpaceStats;
}
