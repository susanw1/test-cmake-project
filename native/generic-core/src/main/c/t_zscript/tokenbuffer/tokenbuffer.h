#ifndef _ZS_TOKENBUFFER_H
#define _ZS_TOKENBUFFER_H

#include <stdint.h>
typedef uint8_t tokunit;

typedef struct {
    tokunit *buffer;
} TokenBuffer ;

static void zs_initTokenBuffer(TokenBuffer *tb);

#endif // _ZS_TOKENBUFFER_H
