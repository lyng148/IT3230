#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc dữ liệu cho sản phẩm
struct Product {
    int id;
    char name[100];
    double price;
};

int main() {
    // Mở tập tin product.txt để đọc
    FILE *file = fopen("product.txt", "r");
    if (file == NULL) {
        printf("Không thể mở tập tin.\n");
        return 1;
    }

    printf("No\tProduct Name\t\t\tPrice\n");
    struct Product product;
    int lineNumber = 1;

    while (fscanf(file, "%d %s %lf", &product.id, product.name, &product.price) == 3) {
        printf("%d\t%s\t\t\t%.2lf\n", lineNumber, product.name, product.price);
        lineNumber++;
    }

    fclose(file);

    return 0;
}
