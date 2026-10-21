#include <stdio.h>

// File luu n o dong dau, day so nguyen o dong tiep theo.
int docFile(int a[], int &n)
{
    FILE *f = fopen("Lab3_2.inp", "r");
    if (f == NULL)
        return 0;

    if (fscanf(f, "%d", &n) != 1 || n < 2 || n > 50)
    {
        fclose(f);
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (fscanf(f, "%d", &a[i]) != 1)
        {
            fclose(f);
            return 0;
        }
    }

    fclose(f);
    return 1;
}

void xuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int timMaxVongLap(int a[], int n)
{
    int max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    return max;
}

/* Cong thuc truy hoi
max(a, 1) = a[0]
max(a, n) = lon hon giua a[n - 1] va max(a, n - 1)
*/
int timMaxDeQuy(int a[], int n)
{
    if (n == 1)
        return a[0];

    int max = timMaxDeQuy(a, n - 1);

    if (a[n - 1] > max)
        return a[n - 1];
    else
        return max;
}

int main()
{
    int a[50];
    int n;

    if (docFile(a, n) == 0)
    {
        printf("Doc file that bai.\n");
        return 1;
    }

    printf("Day so doc duoc tu file:\n");
    xuatMang(a, n);

    printf("So lon nhat (vong lap): %d\n", timMaxVongLap(a, n));
    printf("So lon nhat (de quy): %d\n", timMaxDeQuy(a, n));

    return 0;
}
