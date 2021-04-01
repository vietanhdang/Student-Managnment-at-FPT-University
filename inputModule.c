#include "structAClass.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct information inf;
int enterID(inf danhsach[], int numrecords, char *temp, int done)
{
    done = 0;
    while (1)
    {
        printf("Student ID (ex: HE151359): ");
        fflush(stdin);
        gets(temp);
        if (strlen(temp) ==0 )
        {
            return 1;
        }
        else if (validID(temp)!=0)
        {
            idProcess(temp);
            strcpy(danhsach[numrecords].ID,temp);
            break;
        }
    }// Done
}
int enterStudentName(inf danhsach[], int numrecords, char *temp)
{
    while (1)
    {
        printf("Student Name (ex: Dang Viet Anh): ");
        fflush(stdin);
        gets(temp);
        if (validName(temp)!=0)
        {
            nameProcess(temp);
            strcpy(danhsach[numrecords].name,temp);
            break;
        }
    }// Done
}
int enterDateOfBirth(inf danhsach[], int numrecords, char *temp)
{
    while (1)
    {
        printf("Date of birth (ex: 04/07/2001): ");
        fflush(stdin);
        gets(temp);
        if (validDate(temp)==0)
        {
            strcpy(danhsach[numrecords].date,temp);
            break;
        }
    }//Done
}
int enterSex(inf danhsach[], int numrecords, char *temp)
{
    while (1)
    {
        printf("Sex (enter 1 if male, 0 if female): ");
        fflush(stdin);
        gets(temp);
        if (strlen(temp)==1 && temp[0]=='1')
        {
            strcpy(danhsach[numrecords].sex,"Male");
            break;
        }
        else if (strlen(temp)==1 && temp[0]=='0')
        {
            strcpy(danhsach[numrecords].sex,"Female");
            break;
        }
        else
        {
            printf("Sex is not valid, please enter again\n");
        }
    }//Done
}
int enterAddress(inf danhsach[], int numrecords, char *temp)
{
    while (1)
    {
        printf("Address (ex: Van Du, An Thi, Hung Yen): ");
        fflush(stdin);
        gets(temp);
        if (strlen(temp)==0)
        {
            strcpy(danhsach[numrecords].Address,"Updating");
            break;
        }
        else
        {
            nameProcess(temp);
            strcpy(danhsach[numrecords].Address,temp);
            break;
        }
    }//Done
}
int enterPhone(inf danhsach[], int numrecords, char *temp)
{
    while (1)
    {
        printf("Phone (ex: 0368639828): ");
        fflush(stdin);
        gets(temp);
        if (strlen(temp)==0)
        {
            strcpy(danhsach[numrecords].phone,"Updating");
            break;
        }
        else
        {
            if (validPhone(temp)!=0)
            {
                strcpy(danhsach[numrecords].phone,temp);
                break;
            }
        }
    }//Done
}
int enterDiemCSI(inf danhsach[], int numrecords)
{
    float n;
    while (1)
    {
        printf("DIEM CSI MOI LA: ");
        scanf("%f",&n);
        if (n<0 || n>10)
        {
            printf("DIEN CSI KHONG HOP LE MOI NHAP LAI\n");
        }
        else
        {
            danhsach[numrecords].CSI = n;
            break;
        }
    }//Done
}
int enterDiemCEA(inf danhsach[], int numrecords)
{
    float n;
    while (1)
    {
        printf("DIEM CEA MOI LA: ");
        fflush(stdin);
        scanf("%f",&n);
        if (n<0 || n>10)
        {
            printf("DIEN CEA KHONG HOP LE MOI NHAP LAI\n");
        }
        else
        {
            danhsach[numrecords].CEA = n;
            break;
        }
    }//Done
}
int enterDiemPRF(inf danhsach[], int numrecords)
{
    float n;
    while (1)
    {
        printf("DIEM PRF MOI LA: ");
        fflush(stdin);
        scanf("%f",&n);
        if (n<0 || n>10)
        {
            printf("DIEN PRF KHONG HOP LE MOI NHAP LAI\n");
        }
        else
        {
            danhsach[numrecords].PRF = n;
            break;
        }
    }//Done
}
int enterDiemMAE(inf danhsach[], int numrecords)
{
    float n;
    while (1)
    {
        printf("DIEM MAE MOI LA: ");
        fflush(stdin);
        scanf("%f",&n);
        if (n<0 || n>10)
        {
            printf("DIEN MAE KHONG HOP LE MOI NHAP LAI\n");
        }
        else
        {
            danhsach[numrecords].MAE = n;
            break;
        }
    }//Done
}
int enterOpenFile(char *filename, char *temp)
{
    while (1)
    {
        printf("\n\t\t\t\t\t\t\t     Nhap ten file (ex: SE1607): ");
        fflush(stdin);
        gets(temp);
         if (strlen(temp) ==0 )
        {
            return 1;
        }
        else if (validFile(temp)!=0)
        {
            strcat(temp,".DAT");
            strcpy(filename,temp);
            break;
        }
    }// Done
}
