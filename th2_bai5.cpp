#include <stdio.h>

#define PI 3.14159

inline int timMax(int a, int b, int c)
{
    int max = a;

    if (b > max)
        max = b;

    if (c > max)
        max = c;

    return max;
}

float dienTich(float chieuDai, float chieuRong)
{
    return chieuDai * chieuRong;
}

float dienTich(float banKinh)
{
    return PI * banKinh * banKinh;
}

int main()
{
    int a, b, c;

    printf("Nhap a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);

    printf("So lon nhat la: %d\n", timMax(a, b, c));

    float chieuDai, chieuRong;

    printf("\nNhap chieu dai hinh chu nhat: ");
    scanf("%f", &chieuDai);

    printf("Nhap chieu rong hinh chu nhat: ");
    scanf("%f", &chieuRong);

    printf(
        "Dien tich hinh chu nhat: %.2f\n",
        dienTich(chieuDai, chieuRong)
    );

    float banKinh;

    printf("\nNhap ban kinh hinh tron: ");
    scanf("%f", &banKinh);

    printf("Dien tich hinh tron: %.2f\n", dienTich(banKinh));

    return 0;
}