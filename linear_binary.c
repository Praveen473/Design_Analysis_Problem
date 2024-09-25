#include <stdio.h>

int linearSearch(int arr[], int target, int start, int end) {
    int comparisons = 0;
    if (start > end) {
        return -1; // Element not found
    }
    comparisons++;
    if (arr[start] == target) {
        return start;
    }
    return linearSearch(arr, target, start + 1, end);
}

int binarySearch(int arr[], int target, int start, int end) {
    int comparisons = 0;
    if (start > end) {
        return -1; // Element not found
    }
    comparisons++;
    int mid = (start + end) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binarySearch(arr, target, start, mid - 1);
    } else {
        return binarySearch(arr, target, mid + 1, end);
    }
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter target element: ");
    scanf("%d", &target);

    int choice;
    printf("Choose search option:\n1. Linear Search\n2. Binary Search\n");
    scanf("%d", &choice);
    printf("User entered option: %d\n",choice);

    if (choice == 1) {
        int result = linearSearch(arr, target, 0, n - 1);
        if (result == -1) {
            printf("Element not found\n");
        } else {
            printf("Element found at index %d\n", result);
        }
    } else if (choice == 2) {
        int result = binarySearch(arr, target, 0, n - 1);
        if (result == -1) {
            printf("Element not found\n");
        } else {
            printf("Element found at index %d\n", result);
        }
    }

    return 0;
}