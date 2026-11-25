#include <stdio.h>

int tongPhanTu(int a[], int left, int right)
{
    if (left == right)
        return a[left];

    int mid = (left + right) / 2;

    int tongTrai = tongPhanTu(a, left, mid);
    int tongPhai = tongPhanTu(a, mid + 1, right);

    return tongTrai + tongPhai;
}

int soLanXuatHienX(int a[], int left, int right, int x)
{
    if (left == right)
        if (a[left] == x)
            return 1;
        else
            return 0;

    int mid = (left + right) / 2;

    int soLanTrai = soLanXuatHienX(a, left, mid, x);
    int soLanPhai = soLanXuatHienX(a, mid + 1, right, x);

    return soLanTrai + soLanPhai;
}

int phanTuNhoNhat(int a[], int left, int right)
{
    if (left == right)
        return left;
        
    int mid = (left + right) / 2;

    int viTriMinLeft = phanTuNhoNhat(a, left, mid);
    int viTriMinRight = phanTuNhoNhat(a, mid + 1, right);

    if (a[viTriMinLeft] <= a[viTriMinRight])
        return viTriMinLeft;

    return viTriMinRight;
}

int main()
{
    int n;
    int a[100];

    do
    {
        printf("N = ");
        scanf("%d", &n);
    } 
    while (n <= 5 || n >= 100);

    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    // int tong_phan_tu = tongPhanTu(a, 0, n - 1);
    // printf("Tong phan tu mang: %d\n", tong_phan_tu);

    // int so_lan_xuat_hien_x = soLanXuatHienX(a, 0, n - 1, 3);
    // printf("So lan xuat hien x: %d\n", so_lan_xuat_hien_x);

    int viTriMin = phanTuNhoNhat(a, 0, n - 1);
    printf("Phan tu nho nhat tai vi tri: %d", viTriMin);
    
    return 0;
}