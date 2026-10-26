#include <stdio.h>

// Prototype
void xuat(int a[], int k);
void phanTich(int n, int min, int a[], int k);

int main()
{
    int n;
    int a[20];

    do
    {
        printf("Nhap n: ");
        scanf("%d", &n);
    }
    while (n <= 0 || n >= 20);

    phanTich(n, 1, a, 0);
}

void xuat(int a[], int k)
{
    for (int i = 0; i < k; i++)
    {
        if (i > 0)
            printf(" + ");

        printf("%d", a[i]);
    }

    printf("\n");
}

void phanTich(int n, int min, int a[], int k)
{
    if (n == 0)
    {
        xuat(a, k);
        return;
    }

    for (int i = min; i <= n; i++)
    {
        a[k] = i;
        phanTich(n - i, i, a, k + 1);
    }
}