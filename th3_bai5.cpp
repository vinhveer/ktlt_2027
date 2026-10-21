#include <stdio.h>

#define MAX 101

// Prototype
void nhapChuoi(char chuoi[], int i);
int demKyTu(char chuoi[], int i);
int demKyTuChuCaiThuong(char chuoi[], int i);
int chuoiDoiXung(char chuoi[], int trai, int phai);
int tongChuSo(char chuoi[], int i);

int main()
{
    char chuoi[MAX];

    printf("Nhap chuoi: ");
    nhapChuoi(chuoi, 0);

    int soKyTu = demKyTu(chuoi, 0);
    printf("So ky tu la: %d\n", soKyTu);
    printf("So ky tu chu cai thuong la: %d\n", demKyTuChuCaiThuong(chuoi, 0));

    printf(chuoiDoiXung(chuoi, 0, soKyTu - 1) ? "La chuoi doi xung\n" : "Khong la chuoi doi xung\n");

    printf("Tong chu so: %d\n", tongChuSo(chuoi, 0));

    return 0;
}

void nhapChuoi(char chuoi[], int i = 0)
{
    char c;
    c = getchar();

    if (c == '\n' || i == MAX)
    {
        chuoi[i] = '\0';
        return;
    }

    chuoi[i] = c;
    nhapChuoi(chuoi, i + 1);
}

int demKyTu(char chuoi[], int i)
{
    if (chuoi[i] == '\0')
        return 0;

    return 1 + demKyTu(chuoi, i + 1);
}

int demKyTuChuCaiThuong(char chuoi[], int i)
{
    if (chuoi[i] == '\0')
        return 0;

    char kyTu = chuoi[i];

    if (kyTu >= 'a' && kyTu <= 'z')
        return 1 + demKyTuChuCaiThuong(chuoi, i + 1);
    
    return 0 + demKyTuChuCaiThuong(chuoi, i + 1);
}

int chuoiDoiXung(char chuoi[], int trai, int phai)
{
    if (trai > phai)
        return 1;

    if (chuoi[trai] != chuoi[phai])
        return 0;

    return chuoiDoiXung(chuoi, trai + 1, phai - 1);
}

int tongChuSo(char chuoi[], int i)
{
    char kyTu = chuoi[i];

    if (kyTu == '\0')
        return 0;
    
    int so;
    if (kyTu >= '0' && kyTu <= '9')
    {
        so = kyTu - '0';
        return so + tongChuSo(chuoi, i + 1);
    }

    return tongChuSo(chuoi, i + 1);
}