#include "structAClass.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct information inf;

int saveFileAuto(char filename, inf danhsach[], int numrecords)
{
    FILE *fp;
    if ((fp = fopen(filename, "w+")) == NULL)
        printf("\nKhong thay ghi tap tin %s", filename);
    else
    {
        fwrite(&danhsach[0], sizeof(inf), numrecords, fp);
        fclose(fp);
        printf("\nSave file success.");
        getch();
    }
}
