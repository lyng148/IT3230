#include <stdio.h>
#include <stdlib.h>

void generateBinary(int n) {
    for (int i = 1; i <= n; i++) {
        int num = i;
        int binary[32];
        int j = 0;

        while (num > 0) {
            binary[j] = num % 2;
            num = num / 2;
            j++;
        }


        for (int k = j - 1; k >= 0; k--) {
            printf("%d", binary[k]);
        }

        printf(" ");
    }
}

int main() {
    int n;

    scanf("%d", &n);

    generateBinary(n);

    return 0;
}
