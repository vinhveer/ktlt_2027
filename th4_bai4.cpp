#include <stdio.h>

#define MAX 50

void xuat(int t[], int chon[], int n);
void rutTien(int t[], int chon[], int n, int S, int i, int tong);

int main()
{
    int n, S;
    int t[MAX];
    int chon[MAX] = {0};

    scanf("%d %d", &n, &S);

    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);

    rutTien(t, chon, n, S, 0, 0);

    return 0;
}

void xuat(int t[], int chon[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (chon[i] == 1)
            printf("%d ", t[i]);
    }

    printf("\n");
}

void rutTien(int t[], int chon[], int n, int S, int i, int tong)
{
    if (i == n)
    {
        if (tong == S)
            xuat(t, chon, n);

        return;
    }

    chon[i] = 0;
    rutTien(t, chon, n, S, i + 1, tong);

    chon[i] = 1;
    rutTien(t, chon, n, S, i + 1, tong + t[i]);

    chon[i] = 0;
}