#include <stdio.h>

#define SWAP(a, b)      \
    do                  \
    {                   \
        int temp = (a); \
        (a) = (b);      \
        (b) = temp;     \
    } while (0)

#define MAX2(a, b) ((a) > (b) ? (a) : (b))

#define MAX3(a, b, c) MAX2(MAX2((a), (b)), (c))

int main()
{
    int a, b;
    int x, y, z;
    int n;
    int daySo[100];

    // a) Hoan doi hai so
    printf("Nhap a: ");
    scanf("%d", &a);

    printf("Nhap b: ");
    scanf("%d", &b);

    printf("Truoc khi hoan doi: a = %d, b = %d\n", a, b);

    SWAP(a, b);

    printf("Sau khi hoan doi: a = %d, b = %d\n", a, b);

    // b) Tim so lon nhat trong 3 so
    printf("\nNhap 3 so x, y, z: ");
    scanf("%d%d%d", &x, &y, &z);

    printf("So lon nhat trong 3 so la: %d\n", MAX3(x, y, z));

    // c) Tim so lon nhat trong day
    printf("\nNhap so luong phan tu: ");
    scanf("%d", &n);

    printf("Nhap cac phan tu:\n");

    for (int i = 0; i < n; i++)
    {
        printf("daySo[%d] = ", i);
        scanf("%d", &daySo[i]);
    }

    int max = daySo[0];

    for (int i = 1; i < n; i++)
        max = MAX2(max, daySo[i]);

    printf("So lon nhat trong day la: %d\n", max);

    return 0;
}