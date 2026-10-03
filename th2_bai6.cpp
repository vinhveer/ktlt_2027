#include <stdio.h>

void nhapMang(int a[], int &n)
{
    do
    {
        printf("Nhap so luong phan tu n (3 < n < 50): ");
        scanf("%d", &n);
    }
    while (n <= 3 || n >= 50);

    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

int timLinhCanh(int a[], int n, int x)
{
    a[n] = x;

    int i = 0;

    while (a[i] != x)
        i++;

    if (i < n)
        return 1;

    return 0;
}

int kiemTraGiamDan(int a[], int n)
{
    int flag = 1;

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] <= a[i + 1])
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

int main()
{
    int a[50], n;

    nhapMang(a, n);

    int x;
    printf("\nNhap gia tri x can tim: ");
    scanf("%d", &x);

    if (timLinhCanh(a, n, x))
        printf("Co phan tu %d trong mang.\n", x);
    else
        printf("Khong co phan tu %d trong mang.\n", x);

    if (kiemTraGiamDan(a, n))
        printf("Day so giam dan.\n");
    else
        printf("Day so khong giam dan.\n");

    return 0;
}