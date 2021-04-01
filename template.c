#include <stdio.h>
#define MAX 100
#include "structAClass.h"

typedef struct information inf;
struct information *ptr;

int menu()
{
    int n;
    printf("\nCHAO MUNG BAN DA DEN VOI HE THONG QUAN LY PROFILE SINH VIEN DAI HOC FPT");
    printf("\n+----------------+");
    printf("\n+ 1. TAO DANH SACH SINH VIEN");
    printf("\n+ 2. NHAP DIEM CHO SINH VIEN");
    printf("\n+ 3. XOA SINH VIEN");
    printf("\n+ 4. IN RA DANH SACH THONG TIN SINH VIEN");
    printf("\n+ 5. IN RA DANH SACH DIEM SINH VIEN GIAM DAN");
    printf("\n+----------------+");
    printf("\n+ 6. CAP NHAT LAI THONG TIN SINH VIEN");
    printf("\n+ 7. TINH NANG DANG CAP NHAT");
    printf("\n+----------------+");
    printf("\n+ 8. TIM KIEM THONG TIN SINH VIEN THEO MA HOAC TEN");
    printf("\n+----------------+");
    printf("\n+ 9. EXPORT THONG TIN SINH VIEN");
    printf("\n+ 10. EXPORT FILE DANH SACH DIEM CUA SINH VIEN (GIAM DAN)");
    printf("\n+----------------+");
    printf("\n+ 11. TINH NANG DANG CAP NHAT");
    printf("\n+ 12. LUU FILE");
    printf("\n+ 13. TINH NANG DANG CAP NHAT");
    printf("\n+----------------+");
    printf("\n+ 0. EXIT");
    printf("\n+----------------+");
    printf("\nCHON MUC : ");
    do
    {
        scanf("%d",&n);
    }
    while (n<0 || n>13);
    return n;
}

int menuModify()
{
    int n;
    printf("\nBAN MUON SUA DOI THONG TIN NAO SAU DAY");
    printf("\n+----------------+");
    printf("\n+ 1. ID");
    printf("\n+ 2. HO VA TEN");
    printf("\n+ 3. NGAY SINH");
    printf("\n+ 4. GIOI TINH");
    printf("\n+ 5. DIA CHI");
    printf("\n+ 6. DIEN THOAI");
    printf("\n+ 7. DIEM CSI");
    printf("\n+ 8. DIEM CEA");
    printf("\n+ 9. DIEM PRF");
    printf("\n+ 10. DIEM MAE");
    printf("\n+----------------+");
    printf("\n+ 0. THOAT");
    printf("\n+----------------+");
    printf("\nCHON MUC : ");
    do
    {
        scanf("%d",&n);
    }
    while (n<0 || n>10);
    return n;
}
void statusBar()
{
    printf("\n|NO|");
    printf("|___ID___|");
    printf("|_______%s_______|","Student name");
    printf("|___%s___|","Date");
    printf("|_%s__|","Sex");
    printf("|_________________________%s__________________________|","Address");
    printf("|__%s___|\n","Phone");
}
void statusBarMark()
{
    printf("\n|NO|");
    printf("|___ID___|");
    printf("|_______%s_______|","Student name");
    printf("|_%s_|","CSI");
    printf("|_%s_|","CEA");
    printf("|_%s_|","PRF");
    printf("|_%s_|","MAE");
    printf("|_%s_|","Total Average");
    printf("|_%-8s_|\n","Status");
}
void statusCollect()
{
    printf("\n|NO|");
    printf("|___ID___|");
    printf("|____%s____|","Student name");
    printf("|___%s___|","Date");
    printf("|_%s__|","Sex");
    printf("|__________%s___________|","Address");
    printf("|__%s___|","Phone");
    printf("|_%s_|","CSI");
    printf("|_%s_|","CEA");
    printf("|_%s_|","PRF");
    printf("|_%s_|","MAE");
    printf("|_%s_|","Total Average");
    printf("|_%-8s_|\n","Status");
}
inf danhsach[];
void inputCollect(inf console, int i)
{
    printf("|%-2d|",i);
    printf("|%-8s|",console.ID);
    printf("|%-20s|",console.name);
    printf("|%-10s|",console.date);
    printf("|%-6s|",console.sex);
    printf("|%-28s|",console.Address);
    printf("|%-10s|",console.phone);
    printf("|%-5.2f|",console.CSI);
    printf("|%-5.2f|",console.CEA);
    printf("|%-5.2f|",console.PRF);
    printf("|%-5.2f|",console.MAE);
    printf("|%-15.2f|",(console.CSI+console.CEA+console.PRF+console.MAE)/4);
    printf("|%-10s|\n",console.status);
}

void printMark(inf console,int dem)
{
    printf("|%-2d|",dem);
    printf("|%-8s|",console.ID);
    printf("|%-26s|",console.name);
    printf("|%-5.2f|",console.CSI);
    printf("|%-5.2f|",console.CEA);
    printf("|%-5.2f|",console.PRF);
    printf("|%-5.2f|",console.MAE);
    printf("|%-15.2f|",(console.CSI+console.CEA+console.PRF+console.MAE)/4);
    printf("|%-10s|\n",console.status);
}

void printCollect(inf a[], int n)
{
    for (int i=0; i<n; i++)
    {
        inputCollect(a[i],i+1);
    }
}

void exportSV(inf sv)
{
    printf("|%-8s|",sv.ID);
    printf("|%-26s|",sv.name);
    printf("|%-10s|",sv.date);
    printf("|%-6s|",sv.sex);
    printf("|%-58s|",sv.Address);
    printf("|%-10s|\n",sv.phone);

}

int openAndCreateFile(){
    int n;
    printf("\n\t\t\t\t\t\t\t\tHE THONG QUAN LY PROFILE SINH VIEN");
    printf("\n\t\t\t\t\t\t\t\t+--------------------------------+");
    printf("\n\t\t\t\t\t\t\t\t\t 1. TAO FILE MOI");
    printf("\n\t\t\t\t\t\t\t\t\t 2. MO FILE");
    printf("\n\t\t\t\t\t\t\t\t+--------------------------------+");
    printf("\n\t\t\t\t\t\t\t\t\t 0. THOAT");
    printf("\n\t\t\t\t\t\t\t\t+--------------------------------+");
    printf("\n\t\t\t\t\t\t\t\t       Lua chon cua ban la: ");
    do
    {
        scanf("%d",&n);
    }
    while (n<0 || n>2);
    return n;
}



