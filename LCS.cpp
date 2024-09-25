#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

pair<int, string> lcs(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));

    // Build the LCS table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1; // Characters match
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); // Characters do not match
            }
        }
    }

    // Reconstruct the LCS string
    string lcsString;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsString.push_back(X[i - 1]); // Add character to LCS
            i--;
            j--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--; // Move up in the table
        } else {
            j--; // Move left in the table
        }
    }

    reverse(lcsString.begin(), lcsString.end()); // Reverse to get the correct order
    return {L[m][n], lcsString}; // Return length and LCS string
}

int main() {
    string X, Y;
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    auto result = lcs(X, Y);
    cout << "Length of Longest Common Subsequence: " << result.first << endl;
    cout << "Longest Common Subsequence: " << result.second << endl;

    return 0;
}