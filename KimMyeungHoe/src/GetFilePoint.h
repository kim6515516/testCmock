#include <stdio.h>
#include <string.h>
#include "errno.h"

typedef struct {
    FILE *pOpen;
    int terrno;
} filePointAndErrno;

filePointAndErrno GetFilePoint(char *pCmd); /* get FILE pointer */
