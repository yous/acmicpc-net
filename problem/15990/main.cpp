#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = int(1e9) + 9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> cache(100000 + 1, vector<int>(3, 0));
    cache[1] = {1, 0, 0};
    cache[2] = {0, 1, 0};
    cache[3] = {1, 1, 1};
    for (int n = 4; n <= 100000; n++) {
        cache[n] = {
            (cache[n - 1][1] + cache[n - 1][2]) % MOD,
            (cache[n - 2][0] + cache[n - 2][2]) % MOD,
            (cache[n - 3][0] + cache[n - 3][1]) % MOD
        };
    }
    int T;
    cin >> T;
    while (T-- > 0) {
        int N;
        cin >> N;
        cout << ((cache[N][0] + cache[N][1]) % MOD + cache[N][2]) % MOD << "\n";
    }
    return 0;
}
