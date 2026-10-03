#include <stdio.h>
#include <stdlib.h>

float tinhTienTaxi(
    float soKm,
    int giaMoCua = 15000,
    int giaMoiKm = 12000
)
{
    return giaMoCua + soKm * giaMoiKm;
}

int main(int argc, char *argv[])
{
    if (argc > 4)
    {
        printf("Doi so khong hop le!");
        return 0;
    }

    float soKm = atof(argv[2]);

    if (argc == 3)
        printf("%.0f", tinhTienTaxi(soKm));

    else if (argc == 4)
        printf("%.0f", tinhTienTaxi(soKm, atoi(argv[3])));

    else
        printf("%.0f", tinhTienTaxi(
            soKm,
            atoi(argv[3]),
            atoi(argv[4])
        ));

    return 0;
}