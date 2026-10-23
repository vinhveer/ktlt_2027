#include <stdio.h>

/*
0 -> Nem khong vao ro
1 -> Nem vao ro
*/
int demBong(int a[], int n, int k, int i)
{
    if (i == n)
        return k <= 0;

    int tong = 0;

    for (int j = 0; j <= 1; j++)
    {
        if (i > 0 && a[i - 1] == 0 && j == 0)
            continue;

        a[i] = j;
        tong += demBong(a, n, k - j, i + 1);
    }

    return tong;
}

int main()
{
    int n, k;
    int a[20];

    scanf("%d %d", &n, &k);

    printf("%d\n", demBong(a, n, k, 0));

    return 0;
}