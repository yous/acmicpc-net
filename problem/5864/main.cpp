#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N, A, B;

unsigned int solve(short idx, vector<int>& cows, vector<unsigned int>& cache) {
    if (idx >= N) {
        return 0;
    }
    unsigned int& ans = cache[idx];
    if (ans < 0xFFFFFFFF) {
        return ans;
    }
    int num = cows[idx];
    ans = A * 2 + solve(idx + 1, cows, cache);
    for (int i = idx + 1; i < N; i++) {
        ans = min(ans, A * 2 + B * (cows[i] - num) + solve(i + 1, cows, cache));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> A >> B;
    vector<int> cows(N);
    for (int& num : cows) {
        cin >> num;
    }
    sort(cows.begin(), cows.end());
    vector<unsigned int> cache(N, 0xFFFFFFFF);
    unsigned int ans = solve(0, cows, cache);
    cout << ans / 2 << (ans % 2 == 1 ? ".5" : "") << "\n";
    return 0;
}
