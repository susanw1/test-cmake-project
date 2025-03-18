#ifndef _ZS_ZSCRIPTSYS_H
#define _ZS_ZSCRIPTSYS_H

#include <stdint.h>
#include <t_zscript/sys/core-version.h>
#include <t_zscript/tokenbuffer/tokenbuffer.h>

typedef struct {
    tokunit *buffer;
} ZscriptSystem;

void setupZscript(void);

#endif // _ZS_ZSCRIPTSYS_H
