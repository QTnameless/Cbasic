#include "lib.h"

void add_tmp(song_t *list[], size_t n, int choice, void *ptr, song_t** tmp) {
    printf("\n");
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (choice == 1) {
            if (strstr((*list)[i].name, (char *)ptr)) {
                printf("%d. %s - %s - %s - %d\n", i + 1, (*list)[i].name, (*list)[i].singer, (*list)[i].composer, (*list)[i].year);
                (*tmp)[pos] = (*list)[i];
                pos++;
            }
        } else if (choice == 2) {
            if (strstr((*list)[i].singer, (char *)ptr)) {
                printf("%d. %s - %s - %s - %d\n", i + 1, (*list)[i].name, (*list)[i].singer, (*list)[i].composer, (*list)[i].year);
                (*tmp)[pos] = (*list)[i];
                pos++;
            }
        } else if (choice == 3) {
            if (strstr((*list)[i].composer, (char *)ptr)) {
                printf("%d. %s - %s - %s - %d\n", i + 1, (*list)[i].name, (*list)[i].singer, (*list)[i].composer, (*list)[i].year);
                (*tmp)[pos] = (*list)[i];
                pos++;
            }
        } else {
            if (*((int *)ptr) <= (*list)[i].year) {
                printf("%d. %s - %s - %s - %d\n", i + 1, (*list)[i].name, (*list)[i].singer, (*list)[i].composer, (*list)[i].year);
                (*tmp)[pos] = (*list)[i];
                pos++;
            }
        }
    }
}

void filter(song_t *list[], size_t n, song_t** tmp) {
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
            qsort(*list, n, sizeof(struct song), cmp_name);
            char name_2[100];
            printf("Nhập tên bài hát cần tìm: ");
            scanf(" %[^\n]", name_2);
            add_tmp(list, n, choice2, name_2, tmp);
            break;
        }

        case 2: {
            qsort(*list, n, sizeof(struct song), cmp_singer);
            char singer_2[100];
            printf("Nhập tên ca sĩ cần tìm: ");
            scanf(" %[^\n]", singer_2);
            add_tmp(list, n, choice2, singer_2, tmp);
            break;
        }

        case 3: {
            qsort(*list, n, sizeof(struct song), cmp_composer);
            char composer_2[100];
            printf("Nhập tên nhạc sĩ cần tìm: ");
            scanf(" %[^\n]", composer_2);
            add_tmp(list, n, choice2, composer_2, tmp);
            break;
        }

        case 4: {
            qsort(*list, n, sizeof(struct song), cmp_name);
            int year_2;
            printf("Nhập năm cần tìm: ");
            scanf("%d", &year_2);
            add_tmp(list, n, choice2, &year_2, tmp);
            break;
        }
    }
}