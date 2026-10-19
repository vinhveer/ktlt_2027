#include <stdio.h>
#include <math.h>

#define MAX 50

void nhapMang(int a[], int i, int n)
{
	if (i == n)
		return;

	printf("a[%d] = ", i);
	scanf("%d", &a[i]);
	nhapMang(a, i + 1, n);
}

void xuatMang(int a[], int i, int n)
{
	if (i == n)
		return;
	
	printf("%d ", a[i]);
	xuatMang(a, i + 1, n);
}

int laChinhPhuong(int x)
{
	int k;
	
	if (x < 0)
		return 0;
	else
	{
		k = (int)sqrt((double)x);
		if (k * k == x)
			return 1;
		else
			return 0;
	}
}

int tongChinhPhuong(int a[], int i, int n)
{
	int phanTu;
	
	if (i == n)
		return 0;
	else
		if (laChinhPhuong(a[i]) == 1)
			phanTu = a[i];
		else
			phanTu = 0;
	
	return phanTu + tongChinhPhuong(a, i + 1, n);
}

int timDauTien1(int x, int i, int n, int a[])
{
	if (i == n)
		return -1;
	else
		if (a[i] == x)
			return i;
		else
			return timDauTien1(x, i + 1, n, a);
}

int timDauTien2(int x, int i, int n, int a[])
{
	int kq;
	
	if (i == n)
		return -1;
	else
	{
		kq = timDauTien2(x, i + 1, n, a);
		if (a[i] == x)
			return i;
		else
			return kq;
	}
}

int timDauTien3(int x, int i, int a[])
{
	int kq;
	int truoc;
	
	if (i == -1)
		return -1;
	else
	{
		if (a[i] == x)
			kq = i;
		else
			kq = -1;
		
		truoc = timDauTien3(x, i - 1, a);
		
		if (truoc != -1)
			return truoc;
		else
			return kq;
	}
}

int timDauTien4(int x, int i, int a[])
{
	int kq;
	
	if (i == -1)
		return -1;
	else
	{
		kq = timDauTien4(x, i - 1, a);
		if (kq != -1)
			return kq;
		else
			if (a[i] == x)
				return i;
			else
				return -1;
	}
}

void thapHaNoi(int n, char nguon, char dich, char trungGian)
{
	if (n == 0)
		return;
	else
	{
		thapHaNoi(n - 1, nguon, trungGian, dich);
		printf("  Chuyen dia %d tu %c sang %c\n", n, nguon, dich);
		thapHaNoi(n - 1, trungGian, dich, nguon);
	}
}

int main()
{
	int a[MAX];
	int n;
	int x;
	int soDia;
	int vt1, vt2, vt3, vt4;
	
	do
	{
		printf("Nhap n (2 <= n < 50): ");
		scanf("%d", &n);
	} while (n < 2 || n >= 50);
	
	printf("Nhap %d phan tu:\n", n);
	nhapMang(a, 0, n);
	
	printf("Day vua nhap: ");
	xuatMang(a, 0, n);
	printf("\n");
	
	printf("Tong cac so chinh phuong: %d\n", tongChinhPhuong(a, 0, n));
	
	if (n > 3 && n < 20)
	{
		printf("Nhap x can tim: ");
		scanf("%d", &x);
		
		vt1 = timDauTien1(x, 0, n, a);
		vt2 = timDauTien2(x, 0, n, a);
		vt3 = timDauTien3(x, n - 1, a);
		vt4 = timDauTien4(x, n - 1, a);
		
		printf("Vi tri dau tien cua %d (-1 la khong co):\n", x);
		printf("  TH1 (xuoi, kiem tra truoc) : %d\n", vt1);
		printf("  TH2 (xuoi, de quy truoc)   : %d\n", vt2);
		printf("  TH3 (nguoc, kiem tra truoc): %d\n", vt3);
		printf("  TH4 (nguoc, de quy truoc)  : %d\n", vt4);
	}
	else
		printf("(Bo qua cau c vi n khong thoa 3 < n < 20)\n");
	
	printf("Nhap so dia thap Ha Noi: ");
	scanf("%d", &soDia);
	printf("Cac buoc chuyen %d dia tu A sang C:\n", soDia);
	thapHaNoi(soDia, 'A', 'C', 'B');
	
	return 0;
}
