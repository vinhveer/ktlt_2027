#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if ( argc != 4){
        printf(" So luong doi so khong dung!");
        return 0;
    }
    int x = atoi(argv[1]);
    char opt = argv[2][0];
    int y = atoi(argv[3]);
    if ( opt == '+') printf("%d %c %d = %d", x, opt, y, x + y);
    else if ( opt == '-') printf("%d %c %d = %d", x, opt, y, x - y);
    else if ( opt == '*') printf("%d %c %d = %d", x, opt, y, x * y);
    else if ( opt == '/') printf("%d %c %d = %.2f", x, opt, y, (float) x / y);
    else
    printf("Ky tu khong hop le");

    return 0;
}