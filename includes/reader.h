#define READER_C_INCLUDED
#ifdef READER_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t magicNumber[2];
    uint32_t fileSize;
    uint32_t offset;
    FILE* fileptr;
}BMP_FILE;

BMP_FILE* getFile(char* fileName);

#endif // READER_C_INCLUDED