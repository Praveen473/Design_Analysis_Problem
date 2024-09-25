#include <stdio.h>

int main() {
    int rank;
    int array[100], numElements, kthSmallest, kthLargest, kthSmallestValue, kthLargestValue;
    
    // Reading input values
    printf("Enter the number of elements (N): ");
    scanf("%d", &numElements);
    printf("Enter k for the k-th smallest element: ");
    scanf("%d", &kthSmallest);
    printf("Enter k for the k-th largest element: ");
    scanf("%d", &kthLargest);
    
    printf("Enter the elements: ");
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &array[i]);
    }
    
    // Finding the k-th smallest element
    for (int i = 0; i < numElements; i++) {
        rank = 1;
        for (int j = 0; j < numElements; j++) {
            if (array[i] > array[j]) {
                rank++;
            }
        }
        if (kthSmallest == rank) {
            kthSmallestValue = array[i];
            break;
        }
    }
    
    // Finding the k-th largest element
    for (int i = 0; i < numElements; i++) {
        rank = 1;
        for (int j = 0; j < numElements; j++) {
            if (array[i] < array[j]) {
                rank++;
            }
        }
        if (kthLargest == rank) {
            kthLargestValue = array[i];
            break;
        }
    }
    
    // Printing the results
    printf("The %d-th smallest element is %d\n", kthSmallest, kthSmallestValue);
    printf("The %d-th largest element is %d\n", kthLargest, kthLargestValue);

    return 0;
}
