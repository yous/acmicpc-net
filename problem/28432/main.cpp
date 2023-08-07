#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<string> S(N);
    char start_ch = '?';
    char end_ch = '?';
    for (auto& word : S) {
        cin >> word;
    }
    for (int i = 0; i < N; i++) {
        if (S[i][0] == '?') {
            if (i > 0) {
                start_ch = S[i - 1].back();
            }
            if (i < N - 1) {
                end_ch = S[i + 1].front();
            }
            break;
        }
    }
    short M;
    cin >> M;
    vector<string> A(M);
    for (auto& word : A) {
        cin >> word;
    }
    for (auto& word : A) {
        if ((start_ch == '?' || start_ch == word.front()) && (end_ch == '?' || end_ch == word.back())) {
            bool found = false;
            for (int i = 0; i < N; i++) {
                if (word == S[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << word << "\n";
                break;
            }
        }
    }
    return 0;
}
