#include "../includes/reader.h"

BMP_FILE* getFile(char* fileName){
    FILE* fileptr = NULL;

    fileptr = fopen(fileName,"r");

    if(fileptr == NULL) {
        fprintf(stderr,"Error : the file don't exist or another error occured");
    }

    BMP_FILE* file = calloc(1,sizeof(BMP_FILE));

    file->fileptr = fileptr;

    file->magicNumber[0] = fgetc(file->fileptr);
    file->magicNumber[1] = fgetc(file->fileptr);

    // move to the start of BMP data
    fseek(file->fileptr,10,SEEK_SET);

    file->offset += fgetc(file->fileptr);
    file->offset += fgetc(file->fileptr);
    file->offset += fgetc(file->fileptr);
    file->offset += fgetc(file->fileptr);

    //fprintf(stdout,"Start Addr : %x\n",file->offset);

    fseek(file->fileptr,18,SEEK_SET);

    file->width += fgetc(file->fileptr);
    file->width  += fgetc(file->fileptr);
    file->width  += fgetc(file->fileptr);
    file->width  += fgetc(file->fileptr);

    file->height += fgetc(file->fileptr);
    file->height += fgetc(file->fileptr);
    file->height += fgetc(file->fileptr);
    file->height += fgetc(file->fileptr);

    // moving to the start of data, once there the cursor is set to use data
    fseek(file->fileptr,file->offset,SEEK_SET);

    return file;
}