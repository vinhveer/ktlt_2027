#include <stdio.h>
#include <stdlib.h>

float tinhTienTaxi(
    float soKm,
    int giaMoCua = 15000,
    int giaMoiKm = 12000
)
{
    if (soKm <= 1)
        return giaMoCua;

    return giaMoCua + (soKm - 1) * giaMoiKm;
}

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 4)
    {
        printf("Doi so khong hop le!");
        return 0;
    }

    float soKm = atof(argv[1]);

    if (argc == 2)
        printf("%.0f", tinhTienTaxi(soKm));

    else if (argc == 3)
        printf("%.0f", tinhTienTaxi(
            soKm,
            atoi(argv[2])
        ));

    else
        printf("%.0f", tinhTienTaxi(
            soKm,
            atoi(argv[2]),
            atoi(argv[3])
        ));

    return 0;
}