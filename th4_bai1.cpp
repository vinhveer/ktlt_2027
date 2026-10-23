#include <stdio.h>

#define MAX 10

// Prototype
void xuatMang(int a[], int n);
void inChuoiNhiPhan(int a[], int n, int i);

int main()
{
    int a[MAX];
    int n;
    do
    {
        printf("N = ");
        scanf("%d", &n);
    } while (n <= 0 || n > 10);
    

    inChuoiNhiPhan(a, n, 0);


    return 0;
}

void xuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void inChuoiNhiPhan(int a[], int n, int i)
{
    if (i == n)
    {
        xuatMang(a, n);
        return;
    }
    
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        inChuoiNhiPhan(a, n, i + 1);
    }
}