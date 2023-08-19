#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int X;
    cin >> X;
    string S;
    cin >> S;
    auto sz = S.size();
    string orig_S(S);
    for (int x = 0; x < X; x++) {
        string next_S(S);
        int idx = 0;
        for (int i = 0; i < (sz + 1) / 2; i++) {
            next_S[idx] = S[i * 2];
            idx++;
        }
        for (int i = sz / 2 - 1; i >= 0; i--) {
            next_S[idx] = S[i * 2 + 1];
            idx++;
        }
        swap(S, next_S);
        if (S == orig_S) {
            X = x + 1 + (X % (x + 1));
        }
    }
    cout << S << "\n";
    return 0;
}
