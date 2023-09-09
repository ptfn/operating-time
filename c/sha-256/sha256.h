#ifndef _SHA256LIB_H_
#define _SHA256LIB_H_

#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void sha256(uint8_t *initial_msg, size_t initial_len, uint8_t *hash);

#endif