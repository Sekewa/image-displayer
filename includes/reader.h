#ifndef READER_C_INCLUDED
#define READER_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    uint8_t magicNumber[2];
    uint32_t offset;
    uint8_t width;
    uint8_t height;
    FILE* fileptr;
}BMP_FILE;

BMP_FILE* getFile(char* fileName);

DIR* CheckIfImageDir();
char *trimwhitespace(char *str);

#endif // READER_C_INCLUDED