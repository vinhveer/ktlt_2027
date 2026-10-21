#include <stdio.h>
#include <math.h>

#define MAX 50

void nhapMangNguoc(int n, int a[])
{
    if (n < 0)
        return;

    printf("a[%d] = ", n);
    scanf("%d", &a[n]);

    return nhapMangNguoc(n - 1, a);
}

void nhapMangXuoi(int i, int a[], int n)
{
    if (n == i)
        return;

    printf("a[%d] = ", i);
    scanf("%d", &a[i]);

    return nhapMangXuoi(i + 1, a, n);
}

void xuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }
}

int laSoChinhPhuong(int so)
{
    if (so < 0)
        return 0;
    
    int k = (int) sqrt(so);

    return k * k == so;
}

int tongChinhPhuong(int a[], int n)
{
    if (n == 0)
        if (laSoChinhPhuong(a[n]) == 0)
            return 0;
        else
            return a[n];
    
    if (laSoChinhPhuong(a[n]) == 0)
        return 0 + tongChinhPhuong(a, n - 1);
    else
        return a[n] + tongChinhPhuong(a, n - 1);
}

/*
Tim vi tri dau tien trong mang
Co 4 cach
*/

/*
n = 5
x = 5
     0  1  2  3  4
a = {0, 5, 4, 5, 6}
*/


// (1) Duyet xuoi, kiem tra truoc
int timViTriDauTien1(int x, int i, int n, int a[])
{
    if (i == n)
        return -1;
    
    if (a[i] == x)
        return i;

    return timViTriDauTien1(x, i + 1, n, a);
}

// (2) Duyet xuoi, kiem tra khi quay lui
int timViTriDauTien2(int x, int i, int n, int a[])
{
    if (i == n)
        return -1;

    int kq = timViTriDauTien1(x, i + 1, n, a);
    
    if (a[i] == x)
        return i;

    return kq;
}


int main()
{
    int n;
    int a[MAX];

    do
    {
        printf("N = ");
        scanf("%d", &n);
    } while (n < 2 || n >= 50);

    nhapMangXuoi(0, a, n);
    xuatMang(a, n);
    printf("\nTong CP la: %d", tongChinhPhuong(a, n - 1));





    return 0;
}