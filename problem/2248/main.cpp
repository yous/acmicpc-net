#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, L;
unsigned int I;
vector<vector<int>> cache(32, vector<int>(32, -1));

int solve(int pos, int bit_rem, int mask) {
    if (bit_rem < 0) {
        return 0;
    }
    if (pos == N) {
        I--;
        if (I == 0) {
            for (int i = N - 1; i >= 0; i--) {
                cout << ((mask & (1 << i)) != 0);
            }
            cout << "\n";
            exit(0);
        }
        return 1;
    }
    int& ans = cache[pos][bit_rem];
    if (ans >= 0 && ans < I) {
        I -= ans;
        return ans;
    }
    ans = solve(pos + 1, bit_rem, mask) + solve(pos + 1, bit_rem - 1, mask | (1 << (N - pos - 1)));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> L >> I;
    cout << solve(0, L, 0) << "\n";
    return 0;
}
