#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 1000


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i;
    for ( i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for ( i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int orders[MAX_ORDERS];
    int count = 0;
    char input[5000];
    int i;
    printf("Enter orders Priority Number:\n");
    fgets(input, sizeof(input), stdin);

    char* token = strtok(input, ", \n");
    while (token != NULL && count < MAX_ORDERS) {
        orders[count++] = atoi(token);
        token = strtok(NULL, ", \n");
    }

 
    heapSort(orders, count);

    printf("\nAfter Sorting Orders Priority:\n");
    for ( i = 0; i < count; i++) {
        printf("%d", orders[i]);
        if (i < count - 1) {
            printf(",");
        }
    }
    printf("\n");

    return 0;
}
