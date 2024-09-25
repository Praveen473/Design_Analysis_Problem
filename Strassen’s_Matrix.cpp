#include <iostream>
using namespace std;

void add(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int A[2][2], int B[2][2], int C[2][2]) {
    int p[2][2], q[2][2], r[2][2], s[2][2], t[2][2], u[2][2], v[2][2];
    int temp1[2][2], temp2[2][2];

    int A11[2][2] = {{A[0][0], A[0][1]}, {A[1][0], A[1][1]}};
    int B11[2][2] = {{B[0][0], B[0][1]}, {B[1][0], B[1][1]}};

    // p = (A11 + A22) * (B11 + B22)
    add(A11, A11, temp1);
    add(B11, B11, temp2);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            p[i][j] = temp1[i][j] * temp2[i][j];

    // q = (A21 + A22) * B11
    add(A11, A11, temp1);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            q[i][j] = temp1[i][j] * B11[i][j];

    // r = A11 * (B12 - B22)
    subtract(B11, B11, temp2);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            r[i][j] = A11[i][j] * temp2[i][j];

    // s = A22 * (B21 - B11)
    subtract(B11, B11, temp2);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            s[i][j] = A11[i][j] * temp2[i][j];

    // t = (A11 + A12) * B22
    add(A11, A11, temp1);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            t[i][j] = temp1[i][j] * B11[i][j];

    // u = (A21 - A11) * (B11 + B12)
    subtract(A11, A11, temp1);
    add(B11, B11, temp2);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            u[i][j] = temp1[i][j] * temp2[i][j];

    // v = (A12 - A22) * (B21 + B22)
    subtract(A11, A11, temp1);
    add(B11, B11, temp2);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            v[i][j] = temp1[i][j] * temp2[i][j];

    // C11 = p + s - t + v
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = p[i][j] + s[i][j] - t[i][j] + v[i][j];
}

int main() {
    int A[2][2], B[2][2], C[2][2];

    cout << "Enter elements of 2x2 matrix A:\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> A[i][j];

    cout << "Enter elements of 2x2 matrix B:\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> B[i][j];

    strassen(A, B, C);

    cout << "Result matrix is \n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
