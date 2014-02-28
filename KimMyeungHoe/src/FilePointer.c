#include "FilePointer.h"

struct filePointAndErrno GetFilePoint(char *pInputCommand)
{
    struct filePointAndErrno filePointer = {NULL, 0};
    FILE *pFilePointer = NULL;/* File pointer of popen(); */

    if (pInputCommand == NULL) {
        printf("Error: InputCommand is null\n");
        filePointer.result = 5;
        return filePointer;
    }
    pFilePointer = popen(pInputCommand, "r");/* excute a command  */
    if (pFilePointer == NULL) {
        printf("Error: open popen(): %s\n", strerror(errno));
        filePointer.result = errno;
        return filePointer;
    }
    filePointer.pOpen = pFilePointer;
    return filePointer;
}
