#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) do { int luu = (a); (a) = (b); (b) = luu; } while(0)
#define Max2(a, b)((a)>(b)?(a):(b))
#define Max3(a, b, c)Max2(Max2(a, b),(c))
int main(){
    int a = 3;
    int b = 4;
    int c = 8;
    printf("a) Truoc khi hoan doi a = %d, b = %d", a, b);
    swap(a, b);
    printf("a) Truoc khi hoan doi a = %d, b = %d", a, b);
    int max = Max3(a,b,c);
    printf("b) So lon nhat trong 3 so %d %d %d la: %d", a, b, c, max);

}