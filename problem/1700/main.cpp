#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> usage;
vector<bool> in_use;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    usage.resize(K);
    in_use.resize(K);
    for (int& num : usage) {
        cin >> num;
        num--;
    }
    if (N >= K) {
        cout << "0\n";
        return 0;
    }
    int use_cnt = 0;
    for (int i = 0; i < N; i++) {
        int u = usage[i];
        if (!in_use[u]) {
            in_use[u] = true;
            use_cnt++;
        }
    }
    int ans = 0;
    for (int i = N; i < K; i++) {
        if (in_use[usage[i]]) {
            continue;
        }
        if (use_cnt < N) {
            in_use[usage[i]] = true;
            use_cnt++;
            continue;
        }
        int far = i + 1;
        vector<bool> next_use(K);
        if (N > 1) {
            int cnt = 0;
            while (far < K) {
                int u = usage[far];
                if (in_use[u] && !next_use[u]) {
                    next_use[u] = true;
                    cnt++;
                    if (cnt == N - 1) {
                        break;
                    }
                }
                far++;
            }
        }
        for (int u = 0; u < K; u++) {
            if (in_use[u] && !next_use[u]) {
                in_use[u] = false;
                ans++;
                break;
            }
        }
        in_use[usage[i]] = true;
    }
    cout << ans << "\n";
    return 0;
}
