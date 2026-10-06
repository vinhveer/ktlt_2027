#include <stdio.h>

struct SinhVien
{
    char maSV[10];
    char tenSV[50];
    float diem;
};

void nhapDanhSach(SinhVien sinhViens[], int &n)
{
    do
    {
        printf("Nhap so luong sinh vien (2 < n <= 50): ");
        scanf("%d", &n);
    }
    while (n <= 2 || n > 50);

    for (int i = 0; i < n; i++)
    {
        printf("\nSinh vien %d:\n", i + 1);

        printf("Nhap ma sinh vien: ");
        scanf("%9s", sinhViens[i].maSV);

        printf("Nhap ten sinh vien: ");
        scanf(" %[^\n]", sinhViens[i].tenSV);

        printf("Nhap diem: ");
        scanf("%f", &sinhViens[i].diem);
    }
}

void inDanhSach(SinhVien sinhViens[], int n)
{
    printf("\nDANH SACH SINH VIEN\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nSinh vien %d:\n", i + 1);
        printf("Ma sinh vien: %s\n", sinhViens[i].maSV);
        printf("Ten sinh vien: %s\n", sinhViens[i].tenSV);
        printf("Diem: %.2f\n", sinhViens[i].diem);
    }
}

int timSinhVienDiemCaoNhat(SinhVien sinhViens[], int n)
{
    int viTriMax = 0;

    for (int i = 1; i < n; i++)
    {
        if (sinhViens[i].diem > sinhViens[viTriMax].diem)
            viTriMax = i;
    }

    return viTriMax;
}

int demSinhVienDat(SinhVien sinhViens[], int n)
{
    int dem = 0;

    for (int i = 0; i < n; i++)
    {
        if (sinhViens[i].diem >= 5)
            dem++;
    }

    return dem;
}

int main()
{
    SinhVien sinhViens[50];
    int n;

    nhapDanhSach(sinhViens, n);

    inDanhSach(sinhViens, n);

    int viTriMax = timSinhVienDiemCaoNhat(sinhViens, n);

    printf("\nSinh vien co diem cao nhat:\n");
    printf("Ma sinh vien: %s\n", sinhViens[viTriMax].maSV);
    printf("Ten sinh vien: %s\n", sinhViens[viTriMax].tenSV);
    printf("Diem: %.2f\n", sinhViens[viTriMax].diem);

    printf("\nSo sinh vien dat: %d\n",
           demSinhVienDat(sinhViens, n));

    return 0;
}