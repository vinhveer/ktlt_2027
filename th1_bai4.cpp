#include <stdio.h>

#define MAX 100

void inRaManHinh(float arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%.2f ", arr[i]);
		
	printf("\n");
}

int timPhanTuLonNhat(float arr[], int n)
{
	// Khoi tao bien tam
	float max = arr[0];
	
	/*
	Duyet mang
		Neu gia tri tai vi tri hien tai > max
			Thay the gia tri do cho max
	*/
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
}

float trungBinhCongDaySo(float arr[], int n)
{
	// Khoi tao bien tam
	float tong = 0;
	
	/*
	Duyet mang
		Cong tung phan tu vao tong
	*/
	for (int i = 0; i < n; i++)
		tong += arr[i];
	
	// Tinh trung binh cong: tong / n
	return tong / n;
}

void sapXepTangDan(float arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				float temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int n;
	float arr[MAX]; // Mang so thuc
	
	// Nhap so luong phan tu mang
	do
	{
		printf("N = ");
		scanf("%d", &n);
	}
	while (n <= 1 && n > MAX);	
	
	// Nhap mang
	for (int i = 0; i < n; i++)
	{
		printf("Nhap arr[%d] = ", i);
		scanf("%f", &arr[i]);
	}
	
	// In ra man hinh
	printf("Cac phan tu trong day gom: ");
	inRaManHinh(arr, n);
	
	// In ra phan tu lon nhat
	float max = timPhanTuLonNhat(arr, n);
	printf("Phan tu lon nhat la: %.2f \n", max);
	
	// In ra trung binh cong day so
	float trungBinhCong = trungBinhCongDaySo(arr, n);
	printf("Trung binh day so: %.2f \n", trungBinhCong);
	
	// Sap xep tang dan va in ra man hinh
	sapXepTangDan(arr, n);
	inRaManHinh(arr, n);
	
	return 0;
}
