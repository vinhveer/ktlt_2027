#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("So luong doi so khong dung!");
        return 0;
    }

    int x = atoi(argv[1]);
    char opt = argv[2][0];
    int y = atoi(argv[3]);

    switch (opt) 
    {
        case '+':
            printf("%d %c %d = %d", x, opt, y, x + y);
            break;
        case '-':
            printf("%d %c %d = %d", x, opt, y, x - y);
            break;
        case '*':
            printf("%d %c %d = %d", x, opt, y, x * y);
            break;
        case '/':
            printf("%d %c %d = %.2f", x, opt, y, (float) x / y);
            break;
        default:
            printf("Toan tu khong hop le!");
            break;
    }

    return 0;
}