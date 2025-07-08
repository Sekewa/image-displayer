#include "../includes/reader.h"

FILE* getFile(char* fileName){
    FILE* fileptr = NULL;

    fileptr = fopen(fileName,"r");

    if(fileptr == NULL) {
        fprintf(stderr,"Error : the file don't exist or another error occured");
    }

    fclose(fileptr);

}