#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S, T;
    cin >> S >> T;
    int S_sz = S.size();
    int T_sz = T.size();
    while (T_sz > S_sz) {
        if (T[T_sz - 1] == 'A') {
            T_sz--;
        } else {
            T_sz--;
            reverse(T.begin(), T.begin() + T_sz);
        }
    }
    if (S == T.substr(0, T_sz)) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }
    return 0;
}
