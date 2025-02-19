#ifndef _ZS_ZSCRIPTSYS_H
#define _ZS_ZSCRIPTSYS_H

#include <stdint.h>
#include <zscript/tokenbuffer/tokenbuffer.h>

typedef struct {
    tokunit *buffer;
} ZscriptSystem;

void setupZscript();

#endif // _ZS_ZSCRIPTSYS_H
