#include <stdio.h>

// File luu n o dong dau, day so thuc o dong tiep theo.
int nhapVaGhiFile(double a[], int &n)
{
    do
    {
        printf("Nhap so luong phan tu n (2 <= n <= 30): ");
        if (scanf("%d", &n) != 1)
            return 0;
    }
    while (n < 2 || n > 30);

    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        if (scanf("%lf", &a[i]) != 1)
            return 0;
    }

    FILE *f = fopen("DaySoThuc.inp", "w");
    if (f == NULL)
        return 0;

    int thanhCong = fprintf(f, "%d\n", n) >= 0;
    for (int i = 0; i < n && thanhCong; i++)
        thanhCong = fprintf(f, "%.17g%c", a[i], i == n - 1 ? '\n' : ' ') >= 0;

    if (fclose(f) != 0)
        thanhCong = 0;
    return thanhCong;
}

int docFile(double a[], int &n)
{
    FILE *f = fopen("DaySoThuc.inp", "r");
    if (f == NULL)
        return 0;

    if (fscanf(f, "%d", &n) != 1 || n < 2 || n > 30)
    {
        fclose(f);
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (fscanf(f, "%lf", &a[i]) != 1)
        {
            fclose(f);
            return 0;
        }
    }

    fclose(f);
    return 1;
}

void xuatMang(const double a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%.2f ", a[i]);
    printf("\n");
}

int main()
{
    double a[30], b[30];
    int n, m;

    if (nhapVaGhiFile(a, n) == 0)
    {
        printf("Nhap du lieu hoac ghi file that bai.\n");
        return 1;
    }

    if (docFile(b, m) == 0)
    {
        printf("Doc file that bai.\n");
        return 1;
    }

    printf("Day so doc duoc tu file:\n");
    xuatMang(b, m);

    return 0;
}
