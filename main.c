#include <stdio.h>
#define MAX 100
#include "structAClass.h";
#include <windows.h>

inf danhsach[MAX];
int numrecords = 0;
char filename[100];

void createFile()
{
    int chon2,check=0,done=0;
    char tmp[100];
    do
    {
        check = enterOpenFile(filename,tmp,check);
        if (check == 1)
        {
            break;
        }
        else if (checkFileExist()!=0)
        {
            printf("\n\t\t\t\t\t\t\t     FILE DA TON TAI, VUI LONG NHAP LAI\n");
            //break;
        }
        else
        {
            mainScreen();
        }
    }
    while (!done);
}
void openFile()
{
    int chon2,check=0,done=0;
    char tmp[100];
    do
    {
        check = enterOpenFile(filename,tmp,check);
        if (check == 1)
        {
            break;
        }
        else if (checkFileExist()==0)
        {
            printf("\n\t\t\t\t\t\t\t     FILE CHUA DUOC TAO, VUI LONG NHAP LAI\n");
            //break;
        }
        else
        {
            getdata();
            mainScreen();
        }
    }
    while (!done);
}
void nhapmoi()
{
    char temp[100];
    int done=0;
    int check;
    do
    {
        done = enterID(danhsach,numrecords,temp,done);
        if (done == 1)
        {
            break;
        }
        else
        {
            enterStudentName(danhsach,numrecords,temp);
            enterDateOfBirth(danhsach,numrecords,temp);
            enterSex(danhsach,numrecords,temp);
            enterAddress(danhsach,numrecords,temp);
            enterPhone(danhsach,numrecords,temp);
            sortName(danhsach,numrecords);
            numrecords++;
        }
    }
    while (!done);
}
void nhapdiem()
{
    int choice=0;
    system("cls");
    printf("1. NHAP DIEM THEO THU TU TU TREN XUONG\n");
    printf("2. NHAP DIEM THEO TEN (HOAC MA SO SINH VIEN) (CHON CHUC NANG 6 CAP NHAT THONG TIN SINH VIEN TAI MENU)\n");
    printf("Lua chon cua ban la: ");
    scanf("%d",&choice);
    if (choice == 1)
    {
        int k=0;
        while (k < numrecords)
        {
            printf("\n%s %s\n",danhsach[k].ID,danhsach[k].name);
            printf("|_%s_|:","DIEM CSI");
            scanf("%f",&danhsach[k].CSI);
            printf("|_%s_|:","DIEM CEA");
            scanf("%f",&danhsach[k].CEA);
            printf("|_%s_|:","DIEM PRF");
            scanf("%f",&danhsach[k].PRF);
            printf("|_%s_|:","DIEM MAE");
            scanf("%f",&danhsach[k].MAE);
            k++;
        }
    }

}
void xoa()
{
    int i, done = 0, found, dump[MAX];
    char hoten[35], hotentmp[35], IDtmp[10];
    system("cls");
    while (!done)
    {
        if (numrecords != 0)
        {
            printf("\nDANH SACH SINH VIEN CO TRONG CO SO DU LIEU CUA BAN\n");
            statusCollect();
            printCollect(danhsach,numrecords);
            printf("\nNHAP HO TEN (HOAC MA SINH VIEN CAN XOA) (ENTER DE THOAT): ");
            fflush(stdin);
            gets(hoten);
            if (strlen(hoten) == 0)
                done = 1;
            else
            {
                i = found = 0;
                do
                {
                    strcpy(hotentmp,danhsach[i].name);
                    strcpy(IDtmp,danhsach[i].ID);
                    if (strcmp(strupr(hoten), strupr(hotentmp)) == 0 || strcmp(strupr(hoten), strupr(IDtmp)) == 0)
                        dump[found++] = i;
                    i++;
                }
                while (i<numrecords);
                if (!found)
                    printf("\nKHONG CO %s TRONG CO SO DU LIEU", hoten);
                else
                {
                    printf("\n|NO|");
                    printf("|___ID___|");
                    printf("|_______Student Name_______|\n");
                    for (i=0; i<found; i++)
                    {
                        printf("| %d|",i+1);
                        printf("|%-8s|",danhsach[dump[i]].ID);
                        printf("|%-26s|",danhsach[dump[i]].name);
                    }
                    printf("\n\nTIM THAY %d SINH VIEN CO TRONG CO SO DU LIEU.", found);
                    printf("\nCHON SO THU TU MA BAN MUON XOA (NEU HUY AN ENTER): ");
                    scanf("%d", &i);
                    if (i >= 1 && i <= found)
                    {
                        printf("\nDA XOA SINH VIEN CO ID: %s VA HO TEN: %s KHOI CO SO DU LIEU.",danhsach[dump[i]].ID,danhsach[dump[i]].name);
                        for (found=dump[i-1]; found<numrecords-1; found++)
                            danhsach[found] = danhsach[found+1];
                        numrecords--;
                    }
                    else
                        printf("\nDA HUY.");
                }
                done = 1;
            }
            getch();
        }
        else
            done = 1;
    }
}
void sua()
{
    int i, done = 0, found, dump[MAX];
    char hoten[35], hotentmp[35], IDtmp[35];
    float diem;
    while (!done)
    {
        if (numrecords != 0)
        {
            system("cls");
            printf("\nDANH SACH TOAN BO THONG TIN SINH VIEN CO TRONG CO SO DU LIEU CUA BAN\n");
            statusCollect();
            printCollect(danhsach,numrecords);
            printf("\nNHAP HO TEN (HOAC MA SINH VIEN CAN SUA) (NHAN ENTER 2 LAN DE THOAT): ");
            fflush(stdin);
            gets(hoten);
            if (strlen(hoten) == 0)
                done = 1;
            else
            {
                i = found = 0;
                do
                {
                    strcpy(hotentmp,danhsach[i].name);
                    strcpy(IDtmp,danhsach[i].ID);
                    if (strcmp(strupr(hoten), strupr(hotentmp)) == 0 || strcmp(strupr(hoten), strupr(IDtmp)) == 0 )
                        dump[found++] = i;
                    i++;
                }
                while (i<numrecords);
                if (!found)
                    printf("\nKHONG CHUA | %s | TRONG CO SO DU LIEU CUA BAN", hoten);
                else
                {
                    system("cls");
                    statusCollect();
                    for (i=0; i<found; i++)
                    {
                        inputCollect(danhsach[dump[i]],i+1);
                    }
                    printf("\nTIM THAY %d SINH VIEN CO TRONG CO SO DU LIEU.\n", found);
                    printf("CHON SO THU TU SINH VIEN MA BAN MUON SUA THONG TIN (NEU HUY AN ENTER): ");
                    scanf("%d%*c", &i);
                    if (i >= 1 && i <= found)
                    {
                        char temp[MAX];
                        int select, success=0;
                        do
                        {
                            system("cls");
                            printf("THONG TIN UPDATE SE DUOC CAP NHAT TAI DAY SAU KHI BAN SUA\n");
                            statusCollect();
                            inputCollect(danhsach[dump[i-1]],i);
                            select = menuModify();
                            switch(select)
                            {
                            case 1 :
                                printf("\nMA SINH VIEN CU LA: %s\nMA SINH VIEN MOI LA: ", danhsach[dump[i-1]].ID);
                                enterID(danhsach,dump[i-1],temp);
                                break;
                            case 2 :
                                printf("\nHO VA TEN CU LA: %s\nHO VA TEN MOI LA: ", danhsach[dump[i-1]].name);
                                enterStudentName(danhsach,dump[i-1],temp);
                                break;
                            case 3 :
                                printf("\nNGAY SINH CUA SINH VIEN CU LA: %s\nNGAY SINH CUA SINH VIEN MOI LA: ", danhsach[dump[i-1]].date);
                                enterDateOfBirth(danhsach,dump[i-1],temp);
                                break;
                            case 4 :
                                printf("\nGIOI TINH CUA SINH VIEN CU LA: %s\nGIOI TINH CUA SINH VIEN MOI LA: ", danhsach[dump[i-1]].sex);
                                enterSex(danhsach,dump[i-1],temp);
                                break;
                            case 5 :
                                printf("\nDIA CHI CUA SINH VIEN CU LA: %s\nDIA CHI CUA SINH VIEN MOI LA: ", danhsach[dump[i-1]].Address);
                                enterAddress(danhsach,dump[i-1],temp);
                                break;
                            case 6 :
                                printf("\nDIEN THOAI CUA SINH VIEN CU LA: %s\nDIEN THOAI CUA SINH VIEN MOI LA: ", danhsach[dump[i-1]].phone);
                                enterPhone(danhsach,dump[i-1],temp);
                                break;
                            case 7 :
                                printf("\nDIEM CSI CUA SINH VIEN CU LA: %.2f\nDIEM CSI CUA SINH VIEN MOI LA: ", danhsach[dump[i-1]].CSI);
                                enterDiemCSI(danhsach,dump[i-1]);
                                break;
                            case 8 :
                                printf("\nDIEM CEA CUA SINH VIEN CU LA: %.2f\nDIEM CEA CUA SINH VIEN MOI LA: ", danhsach[dump[i-1]].CEA);
                                enterDiemCEA(danhsach,dump[i-1]);
                                break;
                            case 9 :
                                printf("\nDIEM PRF CUA SINH VIEN CU LA: %.2f\nDIEM PRF CUA SINH VIEN MOI LA: ", danhsach[dump[i-1]].PRF);
                                enterDiemPRF(danhsach,dump[i-1]);
                                break;
                            case 10:
                                printf("\nDIEM MAE CUA SINH VIEN CU LA: %.2f\nDIEM MAE CUA SINH VIEN MOI LA: ", danhsach[dump[i-1]].MAE);
                                enterDiemMAE(danhsach,dump[i-1]);
                                break;

                            case 0:
                                success =1;
                            }
                        }
                        while (!success);
                    }
                    else
                        printf("\nViec thay doi bi huy bo.");
                }
                done = 0;
            }
            getch();
        }
        else

            done = 1;
    }
}
void indiem()
{
    int k;
    system("cls");
    printf("\t\t\tDANH SACH DIEM SINH VIEN GIAM DAN LA\n");
    if (numrecords != 0)
    {
        statusBarMark();
        totalAverage(danhsach,numrecords);
        sortMark(danhsach,numrecords);
        for (k=0; k<numrecords; k++)
        {
            printMark(danhsach[k],k+1);
        }
    }
    else
    {
        printf("CHUA CO DU LIEU");
    }
    getch();

}
void lietke()
{
    int i;
    system("cls");
    printf("\t\t\t\t\t\tDANH SACH THONG TIN CO BAN CUA SINH VIEN LA\n");
    if (numrecords != 0)
    {
        sortName(danhsach,numrecords);
        statusBar();
        for (i=0; i<numrecords; i++)
        {
            printf("| %d|", i+1);
            exportSV(danhsach[i]);
        }
    }
    else
    {
        printf("CHUA CO DU LIEU");
    }
    getch();
}
void timkiem()
{
    int i, done = 0, found, dump[MAX];
    char hoten[35], hotentmp[35],IDtmp[35];
    float diem;
    system("cls");
    while (!done)
    {
        if (numrecords != 0)
        {
            printf("\nNHAP HO TEN (HOAC MA SO SINH VIEN HOC SINH CAN XEM) : ");
            fflush(stdin);
            gets(hoten);
            if (strlen(hoten) == 0)
                done = 1;
            else
            {
                i = found = 0;
                do
                {
                    strcpy(hotentmp,danhsach[i].name);
                    strcpy(IDtmp,danhsach[i].ID);
                    if (strcmp(strupr(hoten), strupr(hotentmp)) == 0 || strcmp(strupr(hoten), strupr(IDtmp)) == 0 )
                        dump[found++] = i;
                    i++;
                }
                while (i<numrecords);
                if (!found)
                    printf("\nKHONG CO | %s | trong co so du lieu", hoten);
                else
                {
                    statusCollect();
                    for (i=0; i<found; i++)
                    {
                        inputCollect(danhsach[dump[i]],dump[i]+1);
                    }
                }
                done = 1;
            }
            getch();
        }
        else
            printf("CHUA CO DU LIEU)");
        done = 1;
    }
}
void putdata()
{
    FILE *fp;
    if ((fp = fopen(filename, "wb+")) == NULL)
        printf("\nKhong thay ghi tap tin %s", filename);
    else
    {
        fwrite(&danhsach[0], sizeof(inf), numrecords, fp);
        fclose(fp);
        printf("\n\t\t\t\t\t\t\t     TAO FILE THANH CONG\n\n\t\t\t\t\t\t\t     Nhan Enter de tiep tuc....");
        getch();
    }
}
int checkFileExist()
{
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL)
        return 0;
}
void getdata()
{
    char c;
    int start, nrec;
    FILE *fp;
    long curpos, length;
    start = 0;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("\nKHONG THE MO TAP TIN %s", filename);
    }
    else
    {
        curpos = ftell(fp);
        fseek(fp, 0L, SEEK_END);
        length = ftell(fp);
        fseek(fp, curpos, SEEK_SET);
        nrec = length / sizeof(inf);
        fread(&danhsach[start], sizeof(inf), nrec, fp);
        fclose(fp);
        printf("\n\n\t\t\t\t\t\t\t     MO FILE THANH CONG. TRONG FILE CO %d DU DIEU CUA SINH VIEN\n",nrec);
        printf("\n\t\t\t\t\t\t\t     Nhan Enter de tiep tuc....");
        numrecords = numrecords + nrec;
        getch();
    }
}
void putInfoData()
{
    char filenameinfo[50];
    printf("|NHAP TEN FILE BAN MUON LUU (ex: THONG TIN SINH VIEN CUA LOP SE1607)|: ");
    fflush(stdin);
    gets(filenameinfo);
    strcat(filenameinfo,".txt");
    FILE *fp;
    if ((fp = fopen(filenameinfo, "w+")) == NULL)
        printf("\nKhong thay ghi tap tin %s", filenameinfo);
    else
    {
        fprintf(fp,"|%-2s|","NO");
        fprintf(fp,"|%-8s|","ID");
        fprintf(fp,"|%-26s|","Student Name");
        fprintf(fp,"|%-10s|","Date");
        fprintf(fp,"|%-6s|","Sex");
        fprintf(fp,"|%-58s|","Address");
        fprintf(fp,"|%-10s|\n\n","Phone");
        sortName(danhsach,numrecords);
        for (int i=0; i<numrecords; i++)
        {
            fprintf(fp,"|%-2d|",i+1);
            fprintf(fp,"|%-8s|",&danhsach[i].ID);
            fprintf(fp,"|%-26s|",&danhsach[i].name);
            fprintf(fp,"|%-10s|",&danhsach[i].date);
            fprintf(fp,"|%-6s|",&danhsach[i].sex);
            fprintf(fp,"|%-58s|",&danhsach[i].Address);
            fprintf(fp,"|%-10s|\n",&danhsach[i].phone);
        }
        if (fp != NULL)
        {
            printf("EXPORT SUCCESS");
        }
        fclose(fp);
    }
    getch();
}
void putMarkData()
{
    char filenamediem[50];
    printf("|NHAP TEN FILE BAN MUON LUU (ex: DIEM CUA LOP SE1607)|: ");
    fflush(stdin);
    gets(filenamediem);
    strcat(filenamediem,".txt");
    FILE *fp;
    if ((fp = fopen(filenamediem, "w+")) == NULL)
        printf("\nKhong thay ghi tap tin %s", filenamediem);
    else
    {
        fprintf(fp,"|%-2s|","NO");
        fprintf(fp,"|%-8s|","ID");
        fprintf(fp,"|%-26s|","Student Name");
        fprintf(fp,"|%-5s|","CSI");
        fprintf(fp,"|%-5s|","CEA");
        fprintf(fp,"|%-5s|","PRF");
        fprintf(fp,"|%-5s|","MAE");
        fprintf(fp,"|%-15s|","Total Average");
        fprintf(fp,"|%-10s|\n\n","Status");
        totalAverage(danhsach,numrecords);
        sortMark(danhsach,numrecords);
        for (int i=0; i<numrecords; i++)
        {
            fprintf(fp,"|%-2d|",i+1);
            fprintf(fp,"|%-8s|",danhsach[i].ID);
            fprintf(fp,"|%-26s|",danhsach[i].name);
            fprintf(fp,"|%-5.2f|",danhsach[i].CSI);
            fprintf(fp,"|%-5.2f|",danhsach[i].CEA);
            fprintf(fp,"|%-5.2f|",danhsach[i].PRF);
            fprintf(fp,"|%-5.2f|",danhsach[i].MAE);
            fprintf(fp,"|%-15.2f|",(danhsach[i].CSI+danhsach[i].CEA+danhsach[i].PRF+danhsach[i].MAE)/4);
            fprintf(fp,"|%-10s|\n",danhsach[i].status);
        }
        if (fp != NULL)
        {
            printf("EXPORT SUCCESS");
        }
        fclose(fp);
        getch();
    }
}
int mainScreen()
{
    int chon, done = 0;
    do
    {
        system("cls");
        system("color 0a");
        chon = menu();
        switch(chon)
        {
        case 1 :
            nhapmoi();
            break;
        case 2 :
            nhapdiem();
            break;
        case 3 :
            xoa();
            break;
        case 4 :
            lietke();
            break;
        case 5 :
            indiem();
            break;
        case 6 :
            sua();
            break;
//        case 7 :
//            sortMark();
//            break;
        case 8 :
            timkiem();
            break;
        case 9 :
            putInfoData();
            break;
        case 10:
            putMarkData();
            break;
        case 11:
//            createFile();
//            break;
        case 12:
            putdata();
            break;
        case 13:
//            getdata();
//            break;
        case 0 :
            done = 1;
            return 1;
        }
    }
    while (!done);
}
void main()
{
    int chon2, check=0;
    do
    {
        //system("cls");
        system("color 0a");
        chon2 = openAndCreateFile();
        switch(chon2)
        {
        case 1 :
            createFile();
            break;
        case 2 :
            openFile();
            break;
        case 0 :
            printf("\n\t\t\t\t\t\t\t\tCAM ON BAN DA SU DUNG CHUONG TRINH!");
            check =1;
        }
    }
    while (!check);

}


