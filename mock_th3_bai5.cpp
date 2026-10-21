#include <stdio.h>

#define MAX 101

void nhapChuoi(char chuoi[], int i)
{
    char c;
    c = getchar();

    if (c == '\n' || i == MAX)
    {
        chuoi[i] = '\0';
        return;
    }
    
    chuoi[i] = c;

    return nhapChuoi(chuoi, i + 1);
}

int demKyTu(char chuoi[], int i)
{
    if (chuoi[i] == '\0')
        return 0;

    return 1 + demKyTu(chuoi, i + 1);
}

int demKyTuChuCaiThuong(char chuoi[], int i)
{
    char c = chuoi[i];
    if (c == '\0')
        return 0;

    if (c >= 'a' && c <= 'z')
        return 1 + demKyTu(chuoi, i + 1);
    
    return demKyTu(chuoi, i + 1);
}

int kiemTraDoiXung(char chuoi[], int trai, int phai)
{
    if (trai > phai)
        return 1;
    
    if (chuoi[trai] != chuoi[phai])
        return 0;

    return kiemTraDoiXung(chuoi, trai + 1, phai - 1);
}

int main()
{
    char chuoi[MAX];

    nhapChuoi(chuoi, 0);

    int soKyTu = demKyTu(chuoi, 0);
    printf("\nDem ky tu: %d\n", soKyTu);

    int soKyTuChuCaiThuong = demKyTuChuCaiThuong(chuoi, 0);
    printf("\nDem ky tu chu cai thuong: %d\n", soKyTuChuCaiThuong);

    if (kiemTraDoiXung(chuoi, 0, soKyTu - 1))
        printf("Chuoi doi xung!");
    else
        printf("Chuoi khong doi xung!");

    return 0;
}