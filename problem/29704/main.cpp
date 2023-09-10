#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, T;
    cin >> N >> T;
    vector<pair<short, short>> problems(N);
    int sum = 0;
    for (auto& [D, M] : problems) {
        cin >> D >> M;
        sum += M;
    }
    vector<int> cache(T + 1);
    for (auto [D, M] : problems) {
        for (int i = T - 1; i >= 0; i--) {
            if (i + D <= T) {
                cache[i + D] = max(cache[i + D], cache[i] + M);
            }
        }
    }
    cout << sum - cache[T] << "\n";
    return 0;
}
