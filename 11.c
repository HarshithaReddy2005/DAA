#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PACKAGES 4

int compare_asc(const void *a, const void *b) {
    return ((int)a - (int)b);
}

int compare_desc(const void *a, const void *b) {
    return ((int)b - (int)a);
}

int main() {
    int times[MAX_PACKAGES];
    int count = 0;
    int time;
    int i;
    char order[5];

    printf("Enter time to reach destination:\n");

    while (scanf("%d", &time) == 1 && count < MAX_PACKAGES) {
        times[count++] = time;
    }

    while (getchar() != '\n');

    do {
        printf("Enter 'asc' for ascending order or 'desc' for descending order: ");
        scanf("%4s", order);
        for ( i = 0; order[i]; i++) {
            order[i] = tolower(order[i]);
        }
        if (strcmp(order, "asc") != 0 && strcmp(order, "desc") != 0) {
            printf("Invalid input. Please enter 'asc' or 'desc'.\n");
        }
    } while (strcmp(order, "asc") != 0 && strcmp(order, "desc") != 0);

    
    if (strcmp(order, "asc") == 0) {
        qsort(times, count, sizeof(int), compare_asc);
    } else {
        qsort(times, count, sizeof(int), compare_desc);
    }

    for ( i = 0; i < count; i++) {
        printf("%d\n", times[i]);
    }

    return 0;
}
