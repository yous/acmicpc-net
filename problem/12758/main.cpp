#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
int T;
int N;
vector<vector<int>> height_divisors;
vector<vector<int>> cache;

void gen_divisors(int n, vector<int>& output) {
    vector<int> output_back;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            output.push_back(i);
            int d = n / i;
            if (d > i) {
                output_back.push_back(d);
            }
        }
    }
    for (int i = 0, sz = output_back.size(); i < sz; i++) {
        output.push_back(output_back[sz - i - 1]);
    }
}

int solve(int pos, int limit_idx) {
    int sz = height_divisors[pos].size();
    if (limit_idx >= sz) {
        return 0;
    }
    if (pos == N - 1) {
        return 1;
    }
    int& ans = cache[pos][limit_idx];
    if (ans >= 0) {
        return ans;
    }
    int limit = height_divisors[pos][limit_idx];
    int next_idx = lower_bound(height_divisors[pos + 1].begin(), height_divisors[pos + 1].end(), limit) - height_divisors[pos + 1].begin();
    int next_sz = height_divisors[pos + 1].size();
    ans = 0;
    for (int i = next_idx; i < next_sz; i++) {
        ans += solve(pos + 1, i);
        ans %= MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        height_divisors.clear();
        height_divisors.resize(N);
        cache.clear();
        cache.resize(N);
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            gen_divisors(num, height_divisors[i]);
            cache[i].resize(height_divisors[i].size());
            fill(cache[i].begin(), cache[i].end(), -1);
        }
        int ans = 0;
        for (int i = 0, sz = height_divisors[0].size(); i < sz; i++) {
            ans += solve(0, i);
            ans %= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}
