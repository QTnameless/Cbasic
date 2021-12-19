#include "lib.h"

void add_song(song_t* list, int* n, char* name, char* singer, char* composer, int* year) {
    printf("Nhập tên bài hát: ");
    scanf(" %[^\n]", name);
    printf("Nhập tên ca sĩ: ");
    scanf(" %[^\n]", singer);
    printf("Nhập tên nhạc sĩ: ");
    scanf(" %[^\n]", composer);
    printf("Nhập năm sáng tác: ");
    scanf("%d", year);
    *n += 1;
    list = realloc(list, *n * sizeof(struct song));
    list[*n - 1].name = name;
    list[*n - 1].singer = singer;
    list[*n - 1].composer = composer;
    list[*n - 1].year = *year;
}