#include <stdio.h>
#include <string.h>
#include "errno.h"

struct filePointAndErrno {
    FILE *pOpen;
    int result;
};

struct filePointAndErrno GetFilePoint(char *pCmd); /* get FILE pointer */
