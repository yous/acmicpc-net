#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T, N;
vector<int> f(1'000'001);
vector<long long> g(1'000'001);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    for (int i = 1; i <= 1'000'000; i++) {
        for (int j = i; j <= 1'000'000; j += i) {
            f[j] += i;
        }
    }
    for (int i = 1; i <= 1'000'000; i++) {
        g[i] = g[i - 1] + f[i];
    }
    while (T-- > 0) {
        cin >> N;
        cout << g[N] << "\n";
    }
    return 0;
}
