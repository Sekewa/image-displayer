#include "../includes/reader.h"

typedef struct {
    char magicNumber[2];
    char fileSize[4];
    char appWhoCreatedFile[4];
    char offset[4];
}HEADER;

FILE* getFile(char* fileName){
    FILE* fileptr = NULL;

    fileptr = fopen(fileName,"r");

    if(fileptr == NULL) {
        fprintf(stderr,"Error : the file don't exist or another error occured");
    }



    fclose(fileptr);

}