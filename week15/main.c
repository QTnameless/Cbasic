#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cgen.h"

typedef struct Product {
    char* pid;
    int price;
    int num;
} product;

typedef struct Order {
    char* oid;
    int k;
    product* pro;
    int total;
} order;

int cmp_p(const void* a, const void* b) {
    product* pA = (product*)a;
    product* pB = (product*)b;
    return strcmp(pA->pid, pB->pid);
}

int cmp_o(const void* a, const void* b) {
    order* oA = (order*)a;
    order* oB = (order*)b;
    return oB->total - oA->total;
}

int binsearch(int l, int r, product* a, char* id) {
    if (l >= r) {
        return 0;
    }
    int i = (l + r) / 2;
    if (strcmp(a[i].pid, id) > 0) {
        return binsearch(l, i, a, id);
    } else if (strcmp(a[i].pid, id) < 0) {
        return binsearch(i + 1, r, a, id);
    }
    return a[i].price;
}

int main(int argc, char* argv[]) {
    BENCH1_START();
    if (argc != 3) {
        printf("Usage: ./prog products.txt orders.txt!\n");
        return 1;
    }

    FILE* p = fopen(argv[1], "r");
    FILE* o = fopen(argv[2], "r");

    int np;
    fscanf(p, "%d", &np);
    product* prod = malloc(np * sizeof(struct Product));
    for (int i = 0; i < np; i++) {
        char id[21];
        fscanf(p, "%s %d", id, &prod[i].price);
        prod[i].pid = strdup(id);
    }

    qsort(prod, np, sizeof(struct Product), cmp_p);

    int no;
    fscanf(o, "%d", &no);
    order* ord = malloc(no * sizeof(struct Order));
    for (int i = 0; i < no; i++) {
        char id[21];
        fscanf(o, "%s %d", id, &ord[i].k);
        ord[i].oid = strdup(id);

        ord[i].total = 0;
        product* tmp = malloc(ord[i].k * sizeof(struct Product));
        for (int j = 0; j < ord[i].k; j++) {
            char id2[21];
            fscanf(o, "%s %d", id2, &tmp[j].num);
            tmp[j].pid = strdup(id2);
            ord[i].total += binsearch(0, np, prod, id2) * tmp[j].num;
        }
        ord[i].pro = tmp;
    }

    qsort(ord, no, sizeof(struct Order), cmp_o);

    for (int i = 0; i < 3; i++) {
        printf("%s %d\n", ord[i].oid, ord[i].total);
    }

    for (int i = 0; i < np; i++) {
        free(prod[i].pid);
    }

    for (int i = 0; i < no; i++) {
        free(ord[i].oid);
        for (int j = 0; j < ord[i].k; j++) {
            free(ord[i].pro[j].pid);
        }
        free(ord[i].pro);
    }
    fclose(p);
    fclose(o);
    BENCH1_END();
    free(prod);
    free(ord);
    return 0;
}