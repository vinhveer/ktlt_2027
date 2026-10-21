#include <stdio.h>
#include <math.h>

#define MAX 50

// void nhapMang(int a[], int n)
// {
//     printf("a[%d] = ", n);
//     scanf("%d", &a[n]);

//     if (n == 0)
//         return;

//     nhapMang(a, n - 1);
// }

// void xuatMang(int a[], int n)
// {
//     printf("%d ", a[n]);

//     if (n == 0)
//         return;

//     xuatMang(a, n - 1);
// }

void nhapMang(int a[], int n, int i)
{
    if (i == n)
        return;

    printf("a[%d] = ", i);
    scanf("%d", &a[i]);

    nhapMang(a, n, i + 1);
}

void xuatMang(int a[], int n, int i)
{
    if (i == n)
        return;

    printf("%d ", a[i]);

    xuatMang(a, n, i + 1);
}

int laSoChinhPhuong(int num)
{
    if (num < 0)
        return 0;

    int k = (int) sqrt(num);

    if (k * k == num)
        return 1;
    
    return 0;
}

int tongChinhPhuong(int a[], int n)
{
    if (n == -1)
        return 0;

    if (laSoChinhPhuong(a[n]))
    {
        return a[n] + tongChinhPhuong(a, n - 1);
    }

    return tongChinhPhuong(a, n - 1);
}

int viTriDauTienX(int a[], int n, int i, int x)
{
    if (i == n)
        return -1;

    if (a[i] == x)
        return i;
    
    return viTriDauTienX(a, n, i + 1, x);
}

void thapHaNoi(int n, char nguon, char trungGian, char dich)
{
    if (n == 0)
        return;

    thapHaNoi(n - 1, nguon, dich, trungGian);
    printf("Chuyen dia %c qua %c \n", nguon, dich);
    thapHaNoi(n - 1, trungGian, nguon, dich);
}

int main()
{
    int n;
    do
    {
        printf("N = ");
        scanf("%d", &n);
    } while (n < 2 || n >= 50);
    
    int a[MAX];

    nhapMang(a, n, 0);
    xuatMang(a, n, 0);

    int tong_cp = tongChinhPhuong(a, n - 1);
    printf("Tong chinh phuong: %d\n", tong_cp);

    int x = 5;
    printf("Vi tri dau tien cua X: %d\n", viTriDauTienX(a, n, 0, x));

    thapHaNoi(3, 'A', 'B', 'C');

    return 0;
}


