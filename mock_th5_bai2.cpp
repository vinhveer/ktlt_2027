#include <stdio.h>

void nhapChuoi(char chuoi[], int i)
{
    int c = getchar();

    if (c == '\n' || c == EOF || i >= 99) {
        chuoi[i] = '\0';
        return;
    }

    chuoi[i] = c;
    nhapChuoi(chuoi, i + 1);
}

int doDai(char chuoi[], int i)
{
    if (chuoi[i] == '\0')
        return i;

    return doDai(chuoi, i + 1);
}

int demKyTu(char chuoi[], int l, int r, char c)
{
    if (l > r)
        return 0;

    if (l == r)
        return chuoi[l] == c;

    int mid = (l + r) / 2;

    return demKyTu(chuoi, l, mid, c)
         + demKyTu(chuoi, mid + 1, r, c);
}

int doiXung(char chuoi[], int l, int r)
{
    if (l >= r)
        return 1;

    if (chuoi[l] != chuoi[r])
        return 0;

    return doiXung(chuoi, l + 1, r - 1);
}

char timNhieuNhat(char chuoi[], int l, int r)
{
    if (l == r)
        return chuoi[l];

    int mid = (l + r) / 2;

    char c1 = timNhieuNhat(chuoi, l, mid);
    char c2 = timNhieuNhat(chuoi, mid + 1, r);

    int dem1 = demKyTu(chuoi, l, r, c1);
    int dem2 = demKyTu(chuoi, l, r, c2);

    if (dem1 >= dem2)
        return c1;

    return c2;
}

int main()
{
    char chuoi[100];
    char c;

    printf("Nhap chuoi: ");
    nhapChuoi(chuoi, 0);

    int n = doDai(chuoi, 0);

    printf("Nhap ky tu can dem: ");
    scanf("%c", &c);

    // Cau a
    printf("\nSo lan xuat hien cua '%c': %d",
           c, demKyTu(chuoi, 0, n - 1, c));

    // Cau b
    if (doiXung(chuoi, 0, n - 1))
        printf("\nChuoi doi xung");
    else
        printf("\nChuoi khong doi xung");

    // Cau c
    if (n > 0) {
        char k = timNhieuNhat(chuoi, 0, n - 1);

        printf("\nKy tu xuat hien nhieu nhat: %c", k);

        printf("\nSo lan xuat hien: %d",
               demKyTu(chuoi, 0, n - 1, k));
    } else {
        printf("\nChuoi rong, khong co ky tu nhieu nhat");
    }

    return 0;
}
