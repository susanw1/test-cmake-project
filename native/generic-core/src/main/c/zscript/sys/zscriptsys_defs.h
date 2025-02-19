#ifdef _ZS_ZSCRIPTSYS_DEFS_H
#error _ZS_ZSCRIPTSYS_DEFS_H already defined - file should only be included once
#endif
#define _ZS_ZSCRIPTSYS_DEFS_H

#include <stdio.h>
#include "zscriptsys.h"

static ZscriptSystem zscript __attribute__((unused));

void setupZscript() {
    printf("hello setupZscript\n");
}
