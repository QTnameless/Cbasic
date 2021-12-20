#include "lib.h"

void delete(song_t** list, int* n) {
    song_t* tmp = malloc(*n * sizeof(struct song));
    filter(list, *n, &tmp);
    print_list(&tmp);
    int num;
    printf("Nhập số thứ tự của bài hát bạn muốn xóa: ");
    scanf("%d", &num);
    printf("Bạn chuẩn bị xóa bài hát:\n%s - %s - %s - %d\n", tmp[num - 1].name, tmp[num - 1].singer, tmp[num - 1].composer, tmp[num - 1].year);
    printf("Bạn có chắc chắn muốn xóa bài hát? [y/n]:  ");
    char check;
    scanf(" %c", &check);
    if (check == 'y') {
        int i = 0;
        while (strcmp((*list)[i].name, tmp[num - 1].name)) {
            i++;
        }

        while ((*list)[i + 1].name != NULL) {
            (*list)[i] = (*list)[i + 1];
            i++;
        }
        *n -= 1;
        (*list)[i].name = NULL;
        (*list)[i].singer = NULL;
        (*list)[i].composer = NULL;
    }
}