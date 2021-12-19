#include "lib.h"

void print_filter(song_t *list, int choice, void *ptr) {
    printf("\n");
    int i = 0;
    int pos = 1;
    while (list[i].name != NULL) {
        if (choice == 1) {
            if (strstr(list[i].name, (char *)ptr)) {
                printf("%d. %s - %s - %s - %d\n", pos, list[i].name, list[i].singer,
                       list[i].composer, list[i].year);
                pos++;
            }
        } else if (choice == 2) {
            if (strstr(list[i].singer, (char *)ptr)) {
                printf("%d. %s - %s - %s - %d\n", pos, list[i].name, list[i].singer,
                       list[i].composer, list[i].year);
                pos++;
            }
        } else if (choice == 3) {
            if (strstr(list[i].composer, (char *)ptr)) {
                printf("%d. %s - %s - %s - %d\n", pos, list[i].name, list[i].singer,
                       list[i].composer, list[i].year);
                pos++;
            }
        } else {
            if (*((int *)ptr) == list[i].year) {
                printf("%d. %s - %s - %s - %d\n", pos, list[i].name, list[i].singer,
                       list[i].composer, list[i].year);
                pos++;
            }
        }
        i++;
    }
}

void filter(song_t *list, size_t n) {
    printf("\nLọc theo thuộc tính:\n");
    printf("1. Tên bài hát\n");
    printf("2. Ca sĩ\n");
    printf("3. Nhạc sĩ\n");
    printf("4. Năm sáng tác\n");
    printf("Lựa chọn của bạn là [1,2,3,4]? ");

    int choice2;
    scanf("%d", &choice2);
    switch (choice2) {
        case 1: {
            qsort(list, n, sizeof(struct song), cmp_name);
            char name_2[100];
            printf("Nhập tên bài hát cần tìm: ");
            scanf(" %[^\n]", name_2);
            print_filter(list, choice2, name_2);
            break;
        }

        case 2: {
            qsort(list, n, sizeof(struct song), cmp_singer);
            char singer_2[100];
            printf("Nhập tên ca sĩ cần tìm: ");
            scanf(" %[^\n]", singer_2);
            print_filter(list, choice2, singer_2);
            break;
        }

        case 3: {
            qsort(list, n, sizeof(struct song), cmp_composer);
            char composer_2[100];
            printf("Nhập tên nhạc sĩ cần tìm: ");
            scanf(" %[^\n]", composer_2);
            print_filter(list, choice2, composer_2);
            break;
        }

        case 4: {
            qsort(list, n, sizeof(struct song), cmp_year);
            int year_2;
            printf("Nhập năm cần tìm: ");
            scanf("%d", &year_2);
            print_filter(list, choice2, &year_2);
            break;
        }
    }
}