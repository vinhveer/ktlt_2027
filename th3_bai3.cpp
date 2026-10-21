#include <stdio.h>

/* Cong thuc truy hoi
S(2) = 2
S(n) = S(n - 2) + n
*/
int tongSoChan(int n)
{
    if (n == 2)
        return 2;

    return tongSoChan(n - 2) + n;
}

/* Cong thuc truy hoi
S(n) = n                    neu n < 10
S(n) = S(n / 10) + n % 10
*/
int tongChuSo(int n)
{
    if (n < 10)
        return n;

    return tongChuSo(n / 10) + n % 10;
}

/* Cong thuc truy hoi
r^0 = 1
r^n = r^(n - 1) * r
*/
double luyThua(double r, int n)
{
    if (n == 0)
        return 1;

    return luyThua(r, n - 1) * r;
}

/* Cong thuc truy hoi
S(0) = a
S(n) = S(n - 1) + a * r^n
*/
double tongCapSoNhan(double a, double r, int n)
{
    if (n == 0)
        return a;

    return tongCapSoNhan(a, r, n - 1) + a * luyThua(r, n);
}

/* Cong thuc truy hoi
S(n) = 0                    neu n < 3
S(n) = S(n - 1) + n         neu n chia het cho 3
S(n) = S(n - 1)             nguoc lai
*/
int tongChiaHetCho3(int n)
{
    if (n < 3)
        return 0;

    if (n % 3 == 0)
        return tongChiaHetCho3(n - 1) + n;

    return tongChiaHetCho3(n - 1);
}

int main()
{
    int n;
    double a, r;

    do
    {
        printf("a) Nhap n chan (2 <= n < 500): ");
        scanf("%d", &n);
    }
    while (n < 2 || n >= 500 || n % 2 != 0);

    printf("Tong cac so chan tu 2 den %d: %d\n\n", n, tongSoChan(n));

    do
    {
        printf("b) Nhap n (1000 <= n < 1000000): ");
        scanf("%d", &n);
    }
    while (n < 1000 || n >= 1000000);

    printf("Tong cac chu so cua %d: %d\n\n", n, tongChuSo(n));

    printf("c) Nhap a: ");
    scanf("%lf", &a);

    printf("Nhap r: ");
    scanf("%lf", &r);

    do
    {
        printf("Nhap n (2 <= n < 10): ");
        scanf("%d", &n);
    }
    while (n < 2 || n >= 10);

    printf("Tong day so hinh hoc: %.2f\n\n", tongCapSoNhan(a, r, n));

    do
    {
        printf("d) Nhap n (2 <= n < 500): ");
        scanf("%d", &n);
    }
    while (n < 2 || n >= 500);

    printf("Tong cac so chia het cho 3 tu 1 den %d: %d\n",
           n, tongChiaHetCho3(n));

    return 0;
}
