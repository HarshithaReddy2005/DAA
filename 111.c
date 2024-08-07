#include <stdio.h>
void sortAscending(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void sortDescending(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main() {
    int n, i, order;
    printf("number of destinations: ");
    scanf("%d", &n);
    int times[n];
    printf("Enter time to reach destination:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &times[i]);
    }
    printf("1 for ascending order or 2 for descending order: ");
    scanf("%d", &order);
    if (order == 1) {
        sortAscending(times, n);
    } else if (order == 2) {
        sortDescending(times, n);
    } else {
        printf("Invalid order choice.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("%d\n", times[i]);
    }
    return 0;
}
