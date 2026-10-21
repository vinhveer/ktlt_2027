#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("%d\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");
    
    int x = atoi(argv[1]);
    printf("Sau khi chuyen qua int la: %d + 10 = %d", x, x + 10);

    return 0;
}