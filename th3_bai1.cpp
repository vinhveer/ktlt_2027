#include <stdio.h>

struct HocPhan
{
    char maHP[10];
    char tenHP[50];
    int soTinChi;
};

void xuatHocPhan(HocPhan hp)
{
    printf("Ma hoc phan: %s\n", hp.maHP);
    printf("Ten hoc phan: %s\n", hp.tenHP);
    printf("So tin chi: %d\n", hp.soTinChi);
}

// File nhi phan chi luu lien tiep n hoc phan.
int nhapVaGhiFile(int &n)
{
    do
    {
        printf("Nhap so luong hoc phan (2 <= n < 10): ");
        if (scanf("%d", &n) != 1)
            return 0;
    }
    while (n < 2 || n >= 10);

    FILE *f = fopen("HocPhan.inp", "wb");
    if (f == NULL)
        return 0;

    for (int i = 0; i < n; i++)
    {
        HocPhan hp;

        printf("\nHoc phan %d:\n", i);

        printf("Nhap ma hoc phan: ");
        scanf("%9s", hp.maHP);

        printf("Nhap ten hoc phan: ");
        scanf(" %49[^\n]", hp.tenHP);

        printf("Nhap so tin chi: ");
        scanf("%d", &hp.soTinChi);

        if (fwrite(&hp, sizeof(HocPhan), 1, f) != 1)
        {
            fclose(f);
            return 0;
        }
    }

    if (fclose(f) != 0)
        return 0;
    return 1;
}

int docHocPhanThuP(int p, HocPhan &hp)
{
    FILE *f = fopen("HocPhan.inp", "rb");
    if (f == NULL)
        return 0;

    if (fseek(f, p * sizeof(HocPhan), SEEK_SET) != 0
        || fread(&hp, sizeof(HocPhan), 1, f) != 1)
    {
        fclose(f);
        return 0;
    }

    fclose(f);
    return 1;
}

int docFile(HocPhan ds[], int &n)
{
    FILE *f = fopen("HocPhan.inp", "rb");
    if (f == NULL)
        return 0;

    n = 0;
    while (n < 10 && fread(&ds[n], sizeof(HocPhan), 1, f) == 1)
        n++;

    fclose(f);
    return n > 0;
}

int tinhTongTinChi(HocPhan ds[], int n)
{
    int tong = 0;

    for (int i = 0; i < n; i++)
        tong += ds[i].soTinChi;

    return tong;
}

void inDanhSach(HocPhan ds[], int n)
{
    printf("\nDANH SACH HOC PHAN\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nHoc phan %d:\n", i);
        xuatHocPhan(ds[i]);
    }

    printf("\nTong so tin chi: %d\n", tinhTongTinChi(ds, n));
}

int main()
{
    HocPhan ds[10];
    int n, p;

    if (nhapVaGhiFile(n) == 0)
    {
        printf("Nhap du lieu hoac ghi file that bai.\n");
        return 1;
    }

    do
    {
        printf("\nNhap vi tri p (0 <= p < %d): ", n);
        scanf("%d", &p);
    }
    while (p < 0 || p >= n);

    HocPhan hp;
    if (docHocPhanThuP(p, hp) == 0)
    {
        printf("Doc hoc phan thu %d that bai.\n", p);
        return 1;
    }

    printf("\nHoc phan thu %d:\n", p);
    xuatHocPhan(hp);

    if (docFile(ds, n) == 0)
    {
        printf("Doc file that bai.\n");
        return 1;
    }

    inDanhSach(ds, n);

    return 0;
}
