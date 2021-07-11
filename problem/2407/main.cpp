#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e18;
int N, M;
long long cache_hi[101][51];
long long cache_lo[101][51];

pair<long long, long long> combi(int n, int m) {
    if (m > n / 2) {
        m = n - m;
    }
    long long& hi = cache_hi[n][m];
    long long& lo = cache_lo[n][m];
    if (hi > 0 || lo > 0) {
        return {hi, lo};
    }
    if (m == 0) {
        hi = 0;
        lo = 1;
        return {hi, lo};
    }
    auto a = combi(n - 1, m - 1);
    auto b = combi(n - 1, m);
    long long new_lo = a.second + b.second;
    hi = a.first + b.first + new_lo / MOD;
    lo = new_lo % MOD;
    return {hi, lo};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    auto p = combi(N, M);
    if (p.first > 0) {
        cout << p.first;
    }
    cout << p.second << "\n";
    return 0;
}
