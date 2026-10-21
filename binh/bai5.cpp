#include <stdio.h>
#define PI 3.14
inline int max( int a, int b, int c){
    int Max = a;
    if( Max < b) Max = b;
    else if( Max < c) Max = c;
    return Max;
}
float DienTich(float chieuDai, float chieuRong){
    return chieuDai*chieuRong;
}
float DienTich(float banKinh){
    return PI*banKinh*banKinh;
}
int main(){
    int a = 5;
    int b = 6;
    int c = 9;
    float chieuDai = 30;
    float chieuRong = 50;
    float banKinh = 70;
    printf("So lon nhat trong 2 so a = %d va b = %d la: %d", a, b, max(a,b,c));
    printf("\n Dien tich hinh chu nhat dai %.2f, rong %.2f la: %.2f", chieuDai, chieuRong, DienTich( chieuDai, chieuRong));
    printf("\n Dien tich hinh tron ban kinh %.2f la: %.2f", banKinh, DienTich(banKinh));
}