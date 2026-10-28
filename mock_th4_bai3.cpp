#include <stdio.h>

#define MAX 20

void xuatMang(int a[], int k)
{
    for (int i = 0; i < k; i++)
    {
        if (i > 0)
            printf(" + ");

        printf("%d", a[i]);
        
        // if(i < k - 1) 
        //     printf("+ ");
    }
    
    printf("\n");
}

void phanTich(int n, int min, int i, int a[])
{
    if (n == 0)
    {
        xuatMang(a, i);
        return;
    }

    for (int j = min; j <= n; j++)
    {
        a[i] = j;
        phanTich(n - j, j, i + 1, a);
    }
}

int main()
{
    int n;
    int a[MAX];

    do
    {
        printf("N = ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 20);

    phanTich(n, 1, 0, a);

    return 0;
}