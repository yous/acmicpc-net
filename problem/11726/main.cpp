#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> cache(N + 1);
    cache[1] = 1;
    cache[2] = 2;
    for (int i = 3; i <= N; i++) {
        cache[i] = (cache[i - 1] + cache[i - 2]) % MOD;
    }
    cout << cache[N] << "\n";
    return 0;
}
