#include <iostream>
#include <string>

using namespace std;

void search(const string& pattern, const string& text) {
    int M = pattern.length();
    int N = text.length();

    for (int i = 0; i <= N - M; i++) {
        int j;

        for (j = 0; j < M; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == M) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    search(pattern, text);

    return 0;
}
