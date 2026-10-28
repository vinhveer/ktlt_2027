#include <stdio.h>

/*
TH1: Quay lui nhi phan
*/
void quayLui(int n, int i, int a[])
{
    if (n == i)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[j]);
        }

        printf("\n");

        return;
    }

    // Tai nhanh 0, toi se lam gi?
    a[i] = 0;
    quayLui(n, i + 1, a);

    // Tai nhanh 1, toi se lam gi?
    a[i] = 1;
    quayLui(n, i + 1, a);
}

void quayLuiNhieuNhanh(int n, int i, int a[])
{
    if (i == n)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[j]);
        }

        printf("\n");

        return;
    }

    for (int j = 0; j < n; j++)
    {
        a[i] = j;
        quayLuiNhieuNhanh(n, i + 1, a);
    }
}

int main()
{
    int a[100];
    quayLui(3, 0, a);
    quayLuiNhieuNhanh(3,)
}