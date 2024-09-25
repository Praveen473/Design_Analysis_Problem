#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define d 256

void RabinKarpSearch(const string& pattern, const string& text, int q) {
    int m = pattern.length();
    int n = text.length();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    vector<int> occurrences;

    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }

            if (j == m) {
                occurrences.push_back(i);
            }
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0) {
                t = (t + q);
            }
        }
    }

    if (!occurrences.empty()) {
        cout << "Pattern found at indices: ";
        for (int index : occurrences) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);
    int q = 101;

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    RabinKarpSearch(pattern, text, q);

    return 0;
}
