#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
int validID(char *sv){
    int k = strlen(sv);
    int check=1;
    if (k==8)
    {
        for (int i=0;i<2;i++){
            if(!((sv[i]>=65 && sv[i]<=90) || (sv[i]>=97) && sv[i]<=122)){
                check = 0;
            }
        }
        for (int i=2; i<k; i++){
            if (sv[i] <48 || sv[i]>57){
                check = 0;
            }
        }
    }
    else{
        check = 0;
    }
    if (check == 0)
    {
        printf("Student ID is not valid, please enter again\n");
    }
}
int validName(char *sv){
    int check =0;
    for (int i=0; i<strlen(sv);i++){
        if (!((sv[i]>=65 && sv[i]<=90) || sv[i]==32 ||  (sv[i]>=97) && sv[i]<=122)){
            check =1;
        }
    }
    if (check==1){
        printf("Student Name is not valid, please enter again\n");
    }
}
int validDate(char *sv){
    int k = strlen(sv);
    int check = 0;
    if (k==10)
    {
        for (int i=0;i<k;i++){
            if (!((sv[i]>=48 && sv[i]<=57) || sv[i]=='/')){
                check = 1;
                break;
            }
        }
    }
    else{
        check = 1;
    }
    if (check==1){
        printf("Date of birth is not valid, please enter again\n");
    }
    return check;
}
int validPhone(char *sv){
    int k=strlen(sv);
    int check = 1;
    if (k==10){
        for (int i=0; i<k;i++){
            if (!(sv[i]>=48 && sv[i]<=57)){
                check = 0;
            }
        }
    }
    else{
            check =0;
    }
    if (check==0){
        printf("Phone number is not valid, please enter again\n");
    }
}
int validFile(char *sv){
    int check =0;
    for (int i=0; i<strlen(sv);i++){
        if (!((sv[i]>=65 && sv[i]<=90) || sv[i]==32 ||  (sv[i]>=97) && sv[i]<=122 ||  (sv[i]>=48) && sv[i]<=57 )){
            check =1;
        }
    }
    if (check==1){
        printf("\n\t\t\t\t\t\t\t     Ten File khong hop le, xin moi nhap lai\n");
    }
}
