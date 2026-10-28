#include <stdio.h>

// void xuatMang(int a[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", a[i]);
//     }

//     printf("\n");
// }

int quayLui(int n, int k, int a[], int i)
{
    if (n == i)
        return k <= 0;

    int tong = 0;

    for (int j = 0; j <= 1; j++)
    {
        if (i > 0 && a[i - 1] == 0 && j == 0)
            continue;

        a[i] = j;
        tong += quayLui(n, k - j, a, i + 1);
    }

    return tong;
}

int main()
{
    int n, k;
    int a[100];
    scanf("%d %d", &n, &k);

    int tong = quayLui(n, k, a, 0);
    printf("%d", tong);

    return 0;
}