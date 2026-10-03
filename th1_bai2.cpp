#include <stdio.h>

#define MAX 100000

/*
Bai 1.2 b)
Cac ban luu y la vong for se co buoc nhay
for (<khai bao bien va gia tri bat dau>, <dieu kien dung>, <buoc nhay>)
*/

int main()
{
	int n;
	int sum = 0;
	
	do
	{
		printf("Nhap 1 <= n <= %d: ", MAX);
		scanf("%d", &n);
	}
	while (n < 1 || n > MAX);
	
	for (int i = 2; i <= n; i+=2)
		sum += i;
	
	printf("Tong cac so chan tu 1 den %d la: %d\n", n, sum);
	
	return 0;
}

/*
Bai 1.2 a)
Su dung cong thuc toan la 
n * (n + 1) / 2
*/

int main()
{
	int n;
	printf("n = ");
	scanf("%d", &n);
	
	int result = n * (n + 1) / 2;
	printf("%d", result);
	
	return 0;
}
