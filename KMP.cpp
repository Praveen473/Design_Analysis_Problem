#include <iostream>
#include <vector>
#include <string>

using namespace std;

void computeLPSArray(const string& pattern, vector<int>& lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;

    while (i < pattern.length()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const string& text, const string& pattern) {
    int m = pattern.length();
    int n = text.length();

    vector<int> lps(m);
    computeLPSArray(pattern, lps);

    int i = 0;
    int j = 0;
    vector<int> occurrences;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            occurrences.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
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

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    KMPSearch(text, pattern);

    return 0;
}
