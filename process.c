#include "structAClass.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct information inf;

int idProcess(char *sv){
    strupr(sv);
}
int nameProcess(char *sv){
    strlwr(sv);
    sv[0] = toupper(sv[0]);
    for (int i=0; i<strlen(sv);i++){
            if (sv[i]==' ' && sv[i+1]!=' '){
                    sv[i+1] = toupper(sv[i+1]);
                }
            }
}
int sortMark(inf danhsach[], int numrecords){
    for (int i=0;i<numrecords;i++){
        for (int j =i+1; j<numrecords;j++){
            if (danhsach[i].diemtb < danhsach[j].diemtb)
            {
                inf luu = danhsach[i];
                danhsach[i] = danhsach[j];
                danhsach[j] = luu;
            }
        }
    }

}
int sortName(inf danhsach[], int numrecords){
    for (int i=0; i<numrecords-1;i++){
        for (int j= i+1; j<numrecords;j++){
            if (strcmp(danhsach[i].name,danhsach[j].name)>0){
                struct information temp = danhsach[i];
                danhsach[i] = danhsach[j];
                danhsach[j] = temp;
            }
        }
    }
}
int totalAverage(inf danhsach[], int numrecords){
    for (int k=0;k<numrecords;k++){
        danhsach[k].diemtb = (danhsach[k].CSI+danhsach[k].CEA+danhsach[k].PRF+danhsach[k].MAE)/4;
        if (danhsach[k].CSI >= 5 && danhsach[k].CEA >= 5 && danhsach[k].PRF >= 5 && danhsach[k].MAE >= 5){
            strcpy(danhsach[k].status,"PASSED");
        }
        else
        {
            strcpy(danhsach[k].status,"NOT PASSED");
        }
    }
}






