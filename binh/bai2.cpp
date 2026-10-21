#include <stdio.h>
#include <stdlib.h>
int main( int argc, char *argv[]){
    int n;
    n = atoi( argv[1]);
    if (n <=2 || n >= 10){
        printf(" Khong thoa so luong (2 < n < 10)!");
        return 0;
    }
    else if (argc != (n + 2)){
        printf(" So luong khong hop le");
        return 0;
    }
    double max;
    max = atof(argv[2]);
    for( int i = 3; i <= n + 1; i++){
        double temp = atof(argv[i]);
        if( temp > max){
            max = temp;
        }
    }
    printf(" Gia tri lon nhat la : %.2f", max);
    return 0;

}