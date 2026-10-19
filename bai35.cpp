#include <stdio.h>

#define MAX 100

void nhapChuoi(char s[], int i)
{
	char c;
	
	c = getchar();
	if (c == '\n' || i == MAX)
	{
		s[i] = '\0';
		return;
	}
	
	s[i] = c;
	nhapChuoi(s, i + 1);
}

int demKyTu(char s[], int i)
{
	if (s[i] == '\0')
		return 0;
	else
		return 1 + demKyTu(s, i + 1);
}

int demChuThuong(char s[], int i)
{
	int phanTu;
	
	if (s[i] == '\0')
		return 0;
	else
		if (s[i] >= 'a' && s[i] <= 'z')
			phanTu = 1;
		else
			phanTu = 0;
	
	return phanTu + demChuThuong(s, i + 1);
}

int doiXung(char s[], int trai, int phai)
{
	if (trai >= phai)
		return 1;
	else
		if (s[trai] != s[phai])
			return 0;
		else
			return doiXung(s, trai + 1, phai - 1);
}

int tongChuSo(char s[], int i)
{
	int phanTu;
	
	if (s[i] == '\0')
		return 0;
	else
		if (s[i] >= '0' && s[i] <= '9')
			phanTu = s[i] - '0';
		else
			phanTu = 0;
	
	return phanTu + tongChuSo(s, i + 1);
}

int main()
{
	char s[MAX + 1];
	int n;
	
	printf("Nhap chuoi (toi da %d ky tu): ", MAX);
	nhapChuoi(s, 0);
	
	printf("Chuoi vua nhap: \"%s\"\n", s);
	
	n = demKyTu(s, 0);
	printf("So ky tu trong chuoi: %d\n", n);
	
	printf("So chu cai thuong: %d\n", demChuThuong(s, 0));
	
	if (doiXung(s, 0, n - 1) == 1)
		printf("Chuoi doi xung.\n");
	else
		printf("Chuoi khong doi xung.\n");
	
	printf("Tong cac chu so trong chuoi: %d\n", tongChuSo(s, 0));
	
	return 0;
}
