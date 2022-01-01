#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    vector<int> uniq(4);
    vector<int> cache(4);
    uniq[1] = 1;
    uniq[2] = 4;
    uniq[3] = 2;
    cache[1] = 1;
    cache[2] = 5;
    cache[3] = uniq[1] * cache[2] + uniq[2] * cache[1] + uniq[3];
    int max_idx = 3;
    while (T-- > 0) {
        int N;
        cin >> N;
        if (max_idx >= N) {
            cout << cache[N] << "\n";
            continue;
        }
        uniq.resize(N + 1);
        for (int i = max_idx + 1; i <= N; i++) {
            if (i % 2 == 1) {
                uniq[i] = 2;
            } else {
                uniq[i] = 3;
            }
        }
        cache.resize(N + 1);
        for (int i = max_idx + 1; i <= N; i++) {
            cache[i] = uniq[i];
            for (int j = 1; j < i; j++) {
                cache[i] += uniq[j] * cache[i - j];
            }
        }
        cout << cache[N] << "\n";
        max_idx = N;
    }
    return 0;
}
