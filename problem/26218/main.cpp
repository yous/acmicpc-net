#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N, B;
long long ans;
vector<short> ans_cnt;

void solve(vector<tuple<short, short, short>>& machines, vector<short>& machine_cnt, vector<long long>& cache) {
    long long prob = 1;
    short cost = 0;
    for (int i = 0; i < N; i++) {
        auto [p, a, c] = machines[i];
        int cur_p = p + a * machine_cnt[i];
        prob *= (cur_p > 100 ? 100 : cur_p);
        cost += c * machine_cnt[i];
    }
    for (int i = 0; i < N; i++) {
        auto [p, a, c] = machines[i];
        if (cost + c > B || p + a * machine_cnt[i] >= 100) {
            continue;
        }
        int cur_p = p + a * machine_cnt[i];
        long long new_prob = prob / (cur_p > 100 ? 100 : cur_p);
        machine_cnt[i]++;
        cur_p = p + a * machine_cnt[i];
        new_prob *= (cur_p > 100 ? 100 : cur_p);
        if (cache[cost + c] < new_prob) {
            cache[cost + c] = new_prob;
            if (ans < new_prob) {
                ans = new_prob;
                ans_cnt = machine_cnt;
            }
            solve(machines, machine_cnt, cache);
        }
        machine_cnt[i]--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> B;
    vector<tuple<short, short, short>> machines(N);
    for (auto& [p, a, c] : machines) {
        cin >> p >> a >> c;
    }
    vector<long long> cache(B + 1);
    long long prob = 1;
    for (auto [p, a, c] : machines) {
        prob *= p;
    }
    cache[0] = prob;
    ans = prob;
    ans_cnt.clear();
    ans_cnt.resize(N);
    vector<short> machine_cnt(N);
    solve(machines, machine_cnt, cache);
    cout << ans << "\n";
    cout << ans_cnt[0];
    for (int i = 1; i < N; i++) {
        cout << " " << ans_cnt[i];
    }
    cout << "\n";
    return 0;
}
