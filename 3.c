#include <stdio.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

int main() {
    int i,n;
    printf("Enter the number of orders: ");
    scanf("%d", &n);

    int priorityNumbers[n];
    printf("Enter orders Priority Number:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &priorityNumbers[i]);
    }
    quickSort(priorityNumbers, 0, n-1);
    printf("After Sorting Orders Priority:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", priorityNumbers[i]);
    }
    printf("\n");

    return 0;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
