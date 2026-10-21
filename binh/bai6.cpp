#include <stdio.h>
void NhapMang(int a[], int n){
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        printf("\n a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}
int TimLinhcanh( int a[], int n, int x){
    a[n]=x;
    int i = 0;
    while(a[i] != x)
        i++;
    if( i < n) return 1;
    return 0;
}
int main(){
    int a[50], n, x;
    NhapMang(a,n);
    printf("\nNhap gia tri x can tim: ");
    scanf("%d",&x);
    int kq = TimLinhCanh(a,n,x)
    if(kq==0)
    printf("\nKhong ton tai %d trong mang",x);
    else printf("\nTon tai %d trong mang",x);
}