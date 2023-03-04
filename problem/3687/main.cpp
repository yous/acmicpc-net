#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int digit_cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

auto string_cmp = [](auto& lhs, auto& rhs) {
    if (lhs.size() != rhs.size()) {
        return lhs.size() < rhs.size();
    }
    return lhs < rhs;
};

string solve(int num, vector<string>& cache, bool is_max) {
    if (num == 0) {
        return "";
    }
    auto& ans = cache[num];
    if (ans != "") {
        return ans;
    }
    bool found = false;
    for (int i = 0; i <= 9; i++) {
        if (num < digit_cnt[i]) {
            continue;
        }
        string next_ans = solve(num - digit_cnt[i], cache, is_max);
        if (next_ans == "x") {
            continue;
        }
        if (!found) {
            found = true;
            ans = string(1, '0' + i) + next_ans;
            continue;
        }
        if (is_max) {
            ans = max(ans, string(1, '0' + i) + next_ans, string_cmp);
        } else {
            ans = min(ans, string(1, '0' + i) + next_ans, string_cmp);
        }
    }
    if (!found) {
        ans = "x";
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    vector<string> min_cache(101, "");
    vector<string> max_cache(101, "");
    solve(100, min_cache, false);
    solve(100, max_cache, true);
    while (T-- > 0) {
        short N;
        cin >> N;
        string min_ans = string(N, '9');
        string max_ans = "";
        for (int i = 1; i <= 9; i++) {
            if (N < digit_cnt[i]) {
                continue;
            }
            if (min_cache[N - digit_cnt[i]] != "x") {
                min_ans = min(min_ans, string(1, '0' + i) + min_cache[N - digit_cnt[i]], string_cmp);
            }
            if (max_cache[N - digit_cnt[i]] != "x") {
                max_ans = max(max_ans, string(1, '0' + i) + max_cache[N - digit_cnt[i]], string_cmp);
            }
        }
        cout << min_ans << " " << max_ans << "\n";
    }
    return 0;
}
