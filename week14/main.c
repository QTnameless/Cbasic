#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    char* id;
    char* name;
    double price;
    int num;
} product;

void print_menu_0() {
    printf("1. Xem thông tin mặt hàng\n");
    printf("2. Tạo đơn hàng\n");
    printf("3. Thoát\n");
    printf("Lựa chọn của bạn: ");
}

void add_bill(product* bill, product p, int num, int count) {
    bill[count].id = p.id;
    bill[count].name = p.name;
    bill[count].price = p.price;
    bill[count].num = num;
}

void print_bill(product* bill, int count) {
    printf("Công ti ABC\n Đơn hàng bán lẻ\n");
    printf("STT   Mặt hàng    Đơn giá Số lượng  Thành tiền\n");
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += bill[i].price * bill[i].num;
        printf("%3d %10s %10.1lf %8d %11.1lf\n", i + 1, bill[i].name, bill[i].price, bill[i].num, bill[i].price * bill[i].num);
    }

    printf("-----------------------------------------------\n");
        printf("                          Tổng tiền: %.1lf\n", total);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage ./prog inp.txt\n");
        return 1;
    }
    FILE* f = fopen(argv[1], "r");

    int n;
    fscanf(f, "%d", &n);

    product list[n];

    for (int i = 0; i < n; i++) {
        char id[10];
        char name[20];
        fscanf(f, "%s %s %lf %d", id, name, &list[i].price, &list[i].num);
        list[i].id = strdup(id);
        list[i].name = strdup(name);
    }

    product* bill = calloc(n, sizeof(struct Product));

    while (1) {
        print_menu_0();
        int choice0;
        scanf("%d", &choice0);
        if (choice0 == 1) {
            printf("Nhập mã số mặt hàng: ");
            char id[10] = {'\0'};
            scanf(" %s", id);

            for (int i = 0; i < n; i++) {
                if (!strcmp(id, list[i].id)) {
                    printf("%s %s %lf %d\n", list[i].id, list[i].name, list[i].price, list[i].num);
                    break;
                }
                if (i == n - 1) {
                    printf("Không tìm thấy mặt hàng!\n");
                }
            }
        } else if (choice0 == 2) {
            int count = 0;
            while (1) {
                printf("Nhập mã số mặt hàng (Nhập \"STOP\" để dừng): ");
                char id[10] = {'\0'};
                scanf(" %s", id);
                if (strcmp(id, "STOP")) {
                    for (int i = 0; i < n; i++) {
                        if (!strcmp(id, list[i].id)) {
                            printf("Nhập số lượng mặt hàng: ");
                            int num;
                            scanf("%d", &num);
                            if (num <= list[i].num) {
                                add_bill(bill, list[i], num, count);
                                count++;
                                break;
                            } else {
                                printf("Không có đủ số lượng mặt hàng!\n");
                                break;
                            }
                        }
                    }
                } else {
                    if (bill[0].id != NULL) {
                        printf("\n");
                        print_bill(bill, count);
                    }
                    break;
                }
            }
        } else if (choice0 == 3) {
            break;
        } else {
            printf("Lựa chọn không hợp lệ!\n");
        }
        printf("\n");
    }

    free(bill);
    fclose(f);
    return 0;
}