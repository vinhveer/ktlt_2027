#include "stdio.h"
#include "math.h"

#define MAX 50

// Prototype
void nhapMangNguoc(int a[], int n);
void nhapMangXuoi(int a[], int i, int n);
void xuatMang(int a[], int i, int n);
int laSoChinhPhuong(int num);
int tongSoChinhPhuong(int a[], int n);
int viTriDauTienX(int a[], int n, int x);
int viTriDauTienX2(int a[], int n, int i, int x);
void thapHaNoi(int n, char nguon, char trungGian, char dich);

int main()
{
    int n;
    do
    {
        printf("N = ");
        scanf("%d", &n);
    } while (n < 2 || n >= 50);

    int a[MAX];

    // index bat dau tu n - 1
    // nhapMangNguoc(a, n - 1);

    // index bat dau tu 0
    nhapMangXuoi(a, 0, n - 1);
    xuatMang(a, 0, n - 1);

    printf("Tong so chinh phuong: %d \n", tongSoChinhPhuong(a, n - 1));

    
    int x = 5;
    // Hai cach lam
    int cachGoi1 = viTriDauTienX(a, n - 1, x);
    int cachGoi2 = viTriDauTienX2(a, n - 1, 0, x);
    printf("Vi tri dau tien cua %d: 1) %d ; 2) %d \n", x, cachGoi1, cachGoi2);

    thapHaNoi(4, 'A', 'B', 'C');

    return 0;
}

void nhapMangNguoc(int a[], int n)
{
    printf("a[%d] = ", n);
    scanf("%d", &a[n]);

    if (n == 0)
        return;
    else
        nhapMangNguoc(a, n - 1);
}

void nhapMangXuoi(int a[], int i, int n)
{
    printf("a[%d] = ", i);
    scanf("%d", &a[i]);

    if (i == n)
        return;
    else
        nhapMangXuoi(a, i + 1, n);
}

void xuatMang(int a[], int i, int n)
{
    printf("%d ", a[i]);

    if (i == n)
        return;
    else
        xuatMang(a, i + 1, n);
}

int laSoChinhPhuong(int num)
{
    if (num < 0)
        return 0;

    int k = (int) sqrt(num);

    // Kiem tra
    int kiemTra = k * k;

    if (kiemTra == num)
        return 1;
    else
        return 0;
}

int tongSoChinhPhuong(int a[], int n)
{
    if (n == -1)
        return 0;

    if (laSoChinhPhuong(a[n]) == 1)
        return a[n] + tongSoChinhPhuong(a, n - 1);
    else
        return tongSoChinhPhuong(a, n - 1);
}

// Cach 1
int viTriDauTienX(int a[], int n, int x)
{
    if (n < 0)
        return -1;

    int ketQua = viTriDauTienX(a, n - 1, x);

    if (ketQua != -1)
        return ketQua;
    
    if (a[n] == x)
        return n;

    return -1;
}

// Cach 2
int viTriDauTienX2(int a[], int n, int i, int x)
{
    if (i == n)
        return 0;

    if (a[i] == x)
        return i;
    else
        return viTriDauTienX2(a, n, i + 1, x);
}

void thapHaNoi(int n, char nguon, char trungGian, char dich)
{
    if (n == 0)
        return;

    // Chuyen n - 1 dia tu nguon sang trung gian
    thapHaNoi(n - 1, nguon, dich, trungGian);

    // Chuyen dia n tu nguon sang dich
    printf("Chuyen dia %d tu %c sang %c \n", n, nguon, dich);

    // Chuyen n - 1 dia tu trung gian sang dich
    thapHaNoi(n - 1, trungGian, nguon, dich);
}