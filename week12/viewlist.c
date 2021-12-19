#include "lib.h"

void view_list(song_t** list, size_t n) {
    // print sub menu
    printf("\nSắp xếp theo thuộc tính:\n");
    printf("1. Tên bài hát\n");
    printf("2. Ca sĩ\n");
    printf("3. Nhạc sĩ\n");
    printf("4. Năm sáng tác\n");
    printf("Lựa chọn của bạn là [1,2,3,4]? ");
    int choice1;
    scanf("%d", &choice1);

    // execute input
    switch(choice1) {
        case 1: {
            qsort(*list, n, sizeof(song_t), cmp_name);
            break;
        }

        case 2: {
            qsort(*list, n, sizeof(song_t), cmp_singer);
            break;
        }

        case 3: {
            qsort(*list, n, sizeof(song_t), cmp_composer);
            break;
        }

        case 4: {
            qsort(*list, n, sizeof(song_t), cmp_year);
            break;
        }
    }

    // print list
    printf("\n");
    int i = 0;
    while ((*list)[i].name != NULL) {
        printf("%d. %s - %s - %s - %d\n", i + 1, (*list)[i].name, (*list)[i].singer, (*list)[i].composer, (*list)[i].year);
        i++;
    }
}