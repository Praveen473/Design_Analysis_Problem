#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char brand[50];
    char model[50];
    int ram;
} Mobile;

void merge(Mobile arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Mobile L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].ram <= R[j].ram) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Mobile arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    printf("Enter the number of mobile phones: ");
    scanf("%d", &n);

    Mobile *mobiles = (Mobile *)malloc(n * sizeof(Mobile));

    for (int i = 0; i < n; i++) {
        printf("Mobile %d:\n", i + 1);
        printf("Brand: ");
        scanf("%s", mobiles[i].brand);
        printf("Model: ");
        scanf("%s", mobiles[i].model);
        printf("RAM (in GB): ");
        scanf("%d", &mobiles[i].ram);
    }

    mergeSort(mobiles, 0, n - 1);

    printf("\nMobile phones sorted by RAM:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. Brand: %s, Model: %s, RAM: %dGB\n", i + 1, mobiles[i].brand, mobiles[i].model, mobiles[i].ram);
    }

    free(mobiles);
    return 0;
}
