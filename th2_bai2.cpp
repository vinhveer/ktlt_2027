#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Chua nhap n.");
        return 0;
    }

    int n = atoi(argv[1]);

    if (n <= 2 || n >= 10)
    {
        printf("Khong thoa so luong (2 < n < 10)");
        return 0;
    }

    if (argc != n + 2)
    {
        printf("Nhap khong du hoac vuot qua so luong.");
        return 0;
    }

    double max = atof(argv[2]);

    for (int i = 3; i <= n + 1; i++)
    {
        double temp = atof(argv[i]);

        if (temp > max)
            max = temp;
    }

    printf("Gia tri lon nhat la: %.2f\n", max);

    return 0;
}