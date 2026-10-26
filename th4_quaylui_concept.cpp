#include <stdio.h>

#define MAX 10

void xuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void hoanVi(int a[], int daDung[], int n, int i)
{
    if (i == n)
    {
        xuatMang(a, n);
        return;
    }

    for (int j = 1; j <= n; j++)
    {
        // Nếu j đã được sử dụng thì bỏ qua
        if (daDung[j])
            continue;

        // 1. Chọn
        a[i] = j;
        daDung[j] = 1;

        // 2. Đi tiếp
        hoanVi(a, daDung, n, i + 1);

        // 3. Quay lui: bỏ lựa chọn vừa rồi
        daDung[j] = 0;
    }
}

int main()
{
    int n;
    int a[MAX];
    int daDung[MAX + 1] = {0};

    do
    {
        printf("N = ");
        scanf("%d", &n);
    }
    while (n <= 0 || n > MAX);

    hoanVi(a, daDung, n, 0);

    return 0;
}