#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<pair<short, short>> jobs(N);
    for (auto& [r, s] : jobs) {
        cin >> r >> s;
    }
    sort(jobs.begin(), jobs.end(), [&](const pair<short, short>& lhs, const pair<short, short>& rhs) {
        auto [r1, s1] = lhs;
        auto [r2, s2] = rhs;
        return s2 * (r2 + 1) < s1 * (r1 + 1);
    });
    long long ans = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        auto [r, s] = jobs[i];
        for (int j = 1; j <= r; j++) {
            ans += 1LL * s / 10 * j * (10 + cnt);
            cnt++;
        }
    }
    cout << ans << "\n";
    return 0;
}
