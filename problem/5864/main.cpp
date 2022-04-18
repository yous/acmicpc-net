#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N, A, B;
vector<int> cows;
vector<unsigned int> cache;

unsigned int solve(short idx) {
    if (idx >= N) {
        return 0;
    }
    unsigned int& ans = cache[idx];
    if (ans < 0xFFFFFFFF) {
        return ans;
    }
    int num = cows[idx];
    ans = A * 2 + solve(idx + 1);
    for (int i = idx + 1; i < N; i++) {
        ans = min(ans, A * 2 + B * (cows[i] - num) + solve(i + 1));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> A >> B;
    cows.resize(N);
    for (int& num : cows) {
        cin >> num;
    }
    sort(cows.begin(), cows.end());
    cache.resize(N, 0xFFFFFFFF);
    unsigned int ans = solve(0);
    cout << ans / 2 << (ans % 2 == 1 ? ".5" : "") << "\n";
    return 0;
}
