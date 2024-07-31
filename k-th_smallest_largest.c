#include <stdio.h>

int main() {
    int s;
    int a[100], n, ans1, ans2, ksmall, klarge;
    
    // Reading input values
    printf("Enter N: ");
    scanf("%d", &n);
    printf("Enter ksmall: ");
    scanf("%d", &ksmall);
    printf("Enter klarge: ");
    scanf("%d", &klarge);
    
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Finding the k-th smallest element
    for (int i = 0; i < n; i++) {
        s = 1;
        for (int j = 0; j < n; j++) {
            if (a[i] > a[j]) {
                s++;
            }
        }
        if (ksmall == s) {
            ans1 = a[i];
            break;
        }
    }
    
    // Finding the k-th largest element
    for (int i = 0; i < n; i++) {
        s = 1;
        for (int j = 0; j < n; j++) {
            if (a[i] < a[j]) {
                s++;
            }
        }
        if (klarge == s) {
            ans2 = a[i];
            break;
        }
    }
    
    // Printing the results
    printf("The %d-th smallest element is %d\n", ksmall, ans1);
    printf("The %d-th largest element is %d\n", klarge, ans2);

    return 0;
}