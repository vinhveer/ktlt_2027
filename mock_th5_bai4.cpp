#include <stdio.h>

int main()
{
    int n, M, w[20], chon[20];
    int dem = 0;

    printf("Nhap n va M: ");
    scanf("%d%d", &n, &M);

    printf("Nhap trong luong cac qua can:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (w[i] < w[j]) {
                int temp = w[i];
                w[i] = w[j];
                w[j] = temp;
            }

    int conLai = M;

    for (int i = 0; i < n; i++) {
        if (w[i] <= conLai) {
            chon[dem] = w[i];
            dem++;
            conLai -= w[i];
        }

        if (conLai == 0)
            break;
    }

    if (conLai != 0) {
        printf("-1\n");
    } else {
        printf("So qua can: %d\n", dem);
        printf("Cac qua can da chon: ");

        for (int i = 0; i < dem; i++)
            printf("%d ", chon[i]);
    }

    return 0;
}
