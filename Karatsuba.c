#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

long long multiply(int x, int y) {
    int n = max(floor(log10(x) + 1), floor(log10(y) + 1));

    if (n == 1) {
        return x * y;
    }

    int m = n / 2;

    int high1 = x / pow(10, m);
    int low1 = x % (int)pow(10, m);
    int high2 = y / pow(10, m);
    int low2 = y % (int)pow(10, m);

    long long z0 = multiply(low1, low2);
    long long z1 = multiply((low1 + high1), (low2 + high2));
    long long z2 = multiply(high1, high2);

    return z2 * pow(10, 2 * m) + (z1 - z2 - z0) * pow(10, m) + z0;
}

int main() {
    int x, y;
    printf("Enter the first number: ");
    scanf("%d", &x);
    printf("Enter the second number: ");
    scanf("%d", &y);

    long long product = multiply(x, y);
    printf("Product of the two numbers: %lld\n", product);

    return 0;
}
