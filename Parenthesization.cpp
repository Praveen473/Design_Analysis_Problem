#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Function to compute the minimum number of scalar multiplications
int minScalarMultiplications(vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i] * dims[k+1] * dims[j+1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n-1];
}

// Function to print the optimal parenthesization
void printParenthesization(int i, int j, vector<vector<int>>& s, char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesization(i, s[i][j], s, name);
    printParenthesization(s[i][j] + 1, j, s, name);
    cout << ")";
}

int main() {
    int numMatrices;
    cout << "Enter the number of matrices: ";
    cin >> numMatrices;

    vector<int> dims(numMatrices + 1);
    cout << "Enter the dimensions \n";
    for (int i = 0; i <= numMatrices; i++) {
        cin >> dims[i];
    }

    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> s(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i] * dims[k+1] * dims[j+1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of scalar multiplications: " << dp[0][n-1] << endl;

    char name = 'A';
    cout << "Optimal parenthesization: ";
    printParenthesization(0, n - 1, s, name);
    cout << endl;

    return 0;
}
