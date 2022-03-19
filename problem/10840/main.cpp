#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string SA, SB;
    cin >> SA >> SB;
    short N = SA.size();
    short M = SB.size();
    vector<array<short, 26>> a_list(N * (N + 1) / 2);
    int idx = 0;
    for (int i = 0; i < N; i++) {
        array<short, 26> cur = {0};
        for (int j = i; j < N; j++) {
            cur[SA[j] - 'a']++;
            a_list[idx] = cur;
            idx++;
        }
    }
    sort(a_list.begin(), a_list.end());
    short ans = 0;
    for (int i = 0; i < M; i++) {
        array<short, 26> cur = {0};
        for (int j = i; j < M; j++) {
            cur[SB[j] - 'a']++;
            if (binary_search(a_list.begin(), a_list.end(), cur)) {
                ans = max(ans, short(j - i + 1));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
