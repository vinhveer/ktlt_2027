#include <stdio.h>

int main()
{
    int n, s, t[30], chon[30];
    int dem = 0;

    printf("Nhap n va s: ");
    scanf("%d%d", &n, &s);

    printf("Nhap cac menh gia:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (t[i] < t[j]) {
                int temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }

    int conLai = s;

    for (int i = 0; i < n; i++) {
        if (t[i] <= conLai) {
            chon[dem] = t[i];
            dem++;
            conLai -= t[i];
        }

        if (conLai == 0)
            break;
    }

    if (conLai != 0) {
        printf("-1\n");
    } else {
        printf("So to tien: %d\n", dem);
        printf("Cac to tien da chon: ");

        for (int i = 0; i < dem; i++)
            printf("%d ", chon[i]);
    }

    return 0;
}
