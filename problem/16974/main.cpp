#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long solve(short N, long long X, vector<long long>& totals, vector<long long>& patties) {
    long long ans = 0;
    if (N == 0) {
        if (X == 1) {
            return 1;
        }
        return 0;
    }
    if (X <= 1) {
        return 0;
    }
    X--;
    if (totals[N - 1] >= X) {
        ans += solve(N - 1, X, totals, patties);
        return ans;
    }
    ans += patties[N - 1];
    X -= totals[N - 1];
    if (X >= 1) {
        ans++;
        X--;
    }
    if (totals[N - 1] >= X) {
        ans += solve(N - 1, X, totals, patties);
        return ans;
    }
    ans += patties[N - 1];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    long long X;
    cin >> N >> X;
    vector<long long> totals(N + 1);
    vector<long long> patties(N + 1);
    totals[0] = 1;
    patties[0] = 1;
    for (int i = 1; i <= N; i++) {
        totals[i] = totals[i - 1] * 2 + 3;
        patties[i] = patties[i - 1] * 2 + 1;
    }
    cout << solve(N, X, totals, patties) << "\n";
    return 0;
}
