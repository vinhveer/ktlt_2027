#include <stdio.h>

#define MAX 10

void xuatMang(int t[], int chon[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (chon[i] == 1)
            printf("%d ", t[i]);
    }

    printf("\n");
}

void quayLui(int n, int S, int t[], int chon[], int i, int tong)
{
    if (n == i)
    {
        if (tong == S)
            xuatMang(t, chon, n);
        
        return;
    }

    chon[i] = 0;
    quayLui(n, S, t, chon, i + 1, tong);
    chon[i] = 1;
    quayLui(n, S, t, chon, i + 1, tong + t[i]);   
}

int main()
{
    int n, S;
    int t[MAX];
    int chon[MAX];

    printf("N = ");
    scanf("%d", &n);

    printf("S = ");
    scanf("%d", &S);

    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);

    quayLui(n, S, t, chon, 0, 0);

    return 0;
}