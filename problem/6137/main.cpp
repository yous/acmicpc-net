#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
char S[2000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    int cnt = 0;
    int lo = 0;
    int hi = N - 1;
    while (lo < hi) {
        if (S[lo] < S[hi]) {
            cout << S[lo];
            lo++;
        } else if (S[lo] > S[hi]) {
            cout << S[hi];
            hi--;
        } else {
            int _lo = lo;
            int _hi = hi;
            while (_lo < _hi && S[_lo] == S[_hi]) {
                _lo++;
                _hi--;
            }
            if (_lo < _hi) {
                if (S[_lo] <= S[_hi]) {
                    cout << S[lo];
                    lo++;
                } else {
                    cout << S[hi];
                    hi--;
                }
            } else {
                cout << S[lo];
                lo++;
            }
        }
        cnt++;
        if (cnt % 80 == 0) {
            cout << "\n";
        }
    }
    cout << S[lo] << "\n";
    return 0;
}
