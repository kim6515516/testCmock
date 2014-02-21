#include "GetFilePoint.h"


filePointAndErrno GetFilePoint(char *pInputCommand)
{
    filePointAndErrno filePointer = {NULL, 0};
    FILE *pfPopen = NULL; /* File pointer of popen(); */

    if (pInputCommand == NULL) {
        printf("Error: InputCommand is null ");
        filePointer.terrno = 5;
        return filePointer;
    }
    pfPopen = popen(pInputCommand, "r");  /* excute a command  */
    if (pfPopen == NULL) {
        printf("Error: open popen(): %s\n", strerror(errno));
        filePointer.terrno = errno;
        return filePointer;
    }
    filePointer.pOpen = pfPopen;
    return filePointer;
}
