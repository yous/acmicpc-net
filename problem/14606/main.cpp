#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<int> cache(N + 1, -1);
    cache[1] = 0;
    cache[2] = 1;
    for (int n = 3; n <= N; n++) {
        int& ans = cache[n];
        for (int i = 1; i <= n / 2; i++) {
            ans = max(ans, cache[i] + cache[n - i] + i * (n - i));
        }
    }
    cout << cache[N] << "\n";
    return 0;
}
