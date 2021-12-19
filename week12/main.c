#include "filter.c"
#include "lib.h"
#include "viewlist.c"
#include "add_song.c"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./prog songs.txt\n");
        return 1;
    }

    // get data from file and save to an array of struct
    FILE* f = fopen(argv[1], "r+");
    song_t* list = NULL;
    char* line = NULL;
    int n = 0;
    while (cgetline(&line, 0, f)) {
        list = realloc(list, (n + 1) * sizeof(struct song));
        char* name = strtok(line, "#*#");
        char* singer = strtok(NULL, "#*#");
        char* composer = strtok(NULL, "#*#");
        list[n].name = strdup(name);
        list[n].singer = strdup(singer);
        list[n].composer = strdup(composer);
        list[n].year = atoi(strtok(NULL, "#*#"));
        n++;
    }
    rewind(f);

    // interactive menu start
    int check = 1;
    while (check) {
        // print main menu
        printf("1. Xem danh sách bài hát\n");
        printf("2. Lọc danh sách bài hát\n");
        printf("3. Thêm bài hát\n");
        printf("4. Xóa bài hát\n");
        printf("5. Thoát\n");
        printf("Lựa chọn của bạn là [1,2,3,4,5]? ");
        int choice0;
        scanf("%d", &choice0);

        // execute input
        switch (choice0) {
            case 1: {
                view_list(&list, n);
                break;
            }

            case 2: {
                filter(list, n);
                break;
            }

            case 3: {
                printf("%d\n", n);
                char name_3[100];
                char singer_3[100];
                char composer_3[100];
                int year_3;
                add_song(&list, &n);
                printf("%d - %s %d\n", n, list[n - 1].name, list[n - 1].year);
                printf("%d - %s %d\n", n, list[n - 1].name, list[n - 1].year);
                write_file(f, &list);
                printf("%d - %s %d\n", n, list[n - 1].name, list[n - 1].year);
                printf("test\n");
                break;
            }

            case 4: {
                break;
            }

            case 5: {
                check = 0;
                break;
            }
        }

        printf("\n");
    }
    fclose(f);
    return 0;
}