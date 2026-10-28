#include <stdio.h>

#define MAX 10

void xuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

void quayLui(int n, int a[], int i)
{
    if (n == i)
    {
        xuatMang(a, n);
        return;
    }

    a[i] = 0;
    quayLui(n, a, i + 1);
    a[i] = 1;
    quayLui(n, a, i + 1);   
}

int main()
{
    int n;
    int a[MAX];

    do
    {
        printf("N = ");
        scanf("%d", &n);
    } while (n <= 0 || n > 10);

    quayLui(n, a, 0);

    return 0;
}