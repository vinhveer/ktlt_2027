#include <stdio.h>

/*
Bai 1.3 a)
Vi so luon luon chi co chan va le, nen:
Nhung dieu kien du thua gom
(n % 2 == 1)
else khong xac dinh
-> Chi can check 1 dieu kien la xong
*/

//int main()
//{
//	int n;
//	scanf("%d", &n);
//	
//	if (n % 2 == 0)
//	{
//		printf("Day la so chan\n");
//	}
//	else
//	{
//		printf("Day la so le\n");
//	}
//	
//	return 0;
//}


/*
Bai 1.3 b)
Chuong trinh dang so sanh cac to hop -> Khong can thiet
Phuong phap don gian hon:
Kiem tra lan luot
if a >= b && a >= c -> lay a, neu khong thoa thi
else if b >= c -> lay b, neu khong thoa thi lay c
*/

int main()
{
	int a, b, c;
	printf("Nhap 3 so: ");
	scanf("%d %d %d", &a, &b, &c);
	
	if (a >= b && a >= c)
		printf("So lon nhat la %d", a);
	else if (b >= c)
		printf("So lon nhat la %d", b);
	else
		printf("So lon nhat la %d", c);
		
	return 0;
}
