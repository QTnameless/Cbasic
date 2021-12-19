#ifndef LIB_H_
#define LIB_H_

#include "cgen.h"
#include "ext/io.h"

typedef struct song {
    char* name;
    char* singer;
    char* composer;
    int year;
} song_t;

int cmp_name(const void *a, const void *b) {
    song_t* song_a = (song_t*) a;
    song_t* song_b = (song_t*) b;
    return strcmp(song_a->name, song_b->name);
}

int cmp_singer(const void *a, const void *b) {
    song_t* song_a = (song_t*) a;
    song_t* song_b = (song_t*) b;
    return strcmp(song_a->singer, song_b->singer);
}

int cmp_composer(const void *a, const void *b) {
    song_t* song_a = (song_t*) a;
    song_t* song_b = (song_t*) b;
    return strcmp(song_a->composer, song_b->composer);
}

int cmp_year(const void *a, const void *b) {
    song_t* song_a = (song_t*) a;
    song_t* song_b = (song_t*) b;
    return song_a->year - song_b->year;
}

void view_list(song_t** list, size_t n);
void write_file(FILE* f, song_t** list) {
    int i = 0;
    while ((*list)[i + 1].name != NULL) {
        fprintf(f, "%s#*#%s#*#%s#*#%d\n", (*list)[i].name, (*list)[i].singer, (*list)[i].composer, (*list)[i].year);
        i++;
    }
    fprintf(f, "%s#*#%s#*#%s#*#%d", (*list)[i].name, (*list)[i].singer, (*list)[i].composer, (*list)[i].year);
}

#endif  // LIB_H_