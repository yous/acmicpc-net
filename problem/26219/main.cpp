#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;
short N;

inline int needs_to_map(vector<short>& needs) {
    int num = 0;
    for (int i = 0; i < N; i++) {
        num = num * 2 + (needs[i] > 0 ? 1 : 0);
    }
    return num;
}

inline int needs_to_num(vector<short>& needs) {
    int num = 0;
    for (int i = 0; i < N; i++) {
        num = num * 10 + (needs[i] == 0 ? 0 : needs[i] - 1);
    }
    return num;
}

int get_mod_inv(int num, vector<int>& mod_inv) {
    int& res = mod_inv[num];
    if (res != -1) {
        return res;
    }
    res = 1;
    int mul = num;
    int k = MOD - 2;
    while (k > 0) {
        if (k % 2 == 1) {
            res = 1LL * res * mul % MOD;
            k--;
        } else {
            mul = 1LL * mul * mul % MOD;
            k /= 2;
        }
    }
    return res;
}

int solve(vector<short>& needs, vector<int>& probs, int prob_sum, vector<vector<int>>& cache, vector<int>& mod_inv) {
    int needs_map = needs_to_map(needs);
    int needs_num = needs_to_num(needs);
    int& ans = cache[needs_map][needs_num];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    for (int i = 0; i < N; i++) {
        if (needs[i] == 0) {
            continue;
        }
        int cur_prob = 1LL * probs[i] * get_mod_inv(prob_sum, mod_inv) % MOD;
        needs[i]--;
        if (needs[i] == 0) {
            int next_num = 1LL * prob_sum * get_mod_inv(prob_sum - probs[i], mod_inv) % MOD;
            int next_ans = solve(needs, probs, prob_sum - probs[i], cache, mod_inv);
            ans = (ans + 1LL * cur_prob * (1 + 1LL * next_num * next_ans % MOD) % MOD) % MOD;
        } else {
            int next_ans = solve(needs, probs, prob_sum, cache, mod_inv);
            ans = (ans + 1LL * cur_prob * (1 + next_ans) % MOD) % MOD;
        }
        needs[i]++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int prob_sum = 0;
    vector<short> needs(N);
    vector<int> probs(N);
    int total_num = 1;
    int power = 1;
    for (int i = 0; i < N; i++) {
        cin >> needs[i] >> probs[i];
        prob_sum += probs[i];
        total_num *= 10;
        power *= 2;
    }
    vector<vector<int>> cache(power, vector<int>(total_num, -1));
    vector<int> mod_inv(prob_sum + 1, -1);
    cout << solve(needs, probs, prob_sum, cache, mod_inv) << "\n";
    return 0;
}
