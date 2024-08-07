#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for ( j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

 
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int products[MAX_PRODUCTS];
    int count = 0;
    char input[1000];
    int i;
    printf("Enter Products IDs:\n");
    fgets(input, sizeof(input), stdin);

    char* token = strtok(input, ", \n");
    while (token != NULL && count < MAX_PRODUCTS) {
        products[count++] = atoi(token);
        token = strtok(NULL, ", \n");
    }

    quickSort(products, 0, count - 1);

    printf("\nAfter Sorting Product IDs:\n");
    for ( i = 0; i < count; i++) {
        printf("%d", products[i]);
        if (i < count - 1) {
            printf(",");
        }
    }
    printf("\n");

    return 0;
}
