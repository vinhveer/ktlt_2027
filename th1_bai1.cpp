#include <stdio.h>

/*
1.1 a)
- Tach lenh va xuong dong theo ngu nghia
  VD:
  Khai bao bien
  logic tinh
  Xuat ket qua
  ...
*/

//int main()
//{
//	int a, b, c;
//	
//	a = 5;
//	b = 10;
//	c = a + b;
//	
//	printf("%d\n", c);
//	
//	return 0;	
//}

/*
Bai 1.1 b)
De y dieu kien, 0 <= d <= 100. Chuong trinh cu da thoa chua?
Neu chua, cac ban phai rang buoc lai dieu kien (Bat buoc)
In ra thong bao neu khong thoa dieu kien
*/

//int main()
//{
//	int d;
//	printf("Nhap diem: ");
//	scanf("%d", &d);
//	
//	if (d >= 0 && d <= 100)
//	{
//		if (d < 50)
//			printf("Truot");
//		else
//		{
//			if (d < 80)
//				printf("Kha");
//			else
//				printf("Gioi");
//		}
//	} 
//	else 
//		printf("Vuot qua gioi han!");
//	
//	return 0;
//}

/*
1.1 c)
Cach xu ly lap: Co rat nhieu cach de xu ly
VD: Su dung hai vong for long nhau
Hoac cac ban dung while van hop le
*/

int main()
{
	int i;
	int j;
	
	for (i = 1; i <= 10; i++)
	{	
		for (j = 1; j <=10; j++)
		{
			printf("%d x %d = %d\n", i, j, i * j);
		}
		
		printf("\n");
	}
}
