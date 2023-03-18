#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N, M;

int solve(int idx, int discomfort, int clean_cnt, vector<short>& people, vector<vector<vector<int>>>& cache) {
    if (idx >= N) {
        return 0;
    }
    auto& ans = cache[idx][discomfort][clean_cnt];
    if (ans >= 0) {
        return ans;
    }
    ans = discomfort * people[idx] + solve(idx + 1, discomfort + people[idx], clean_cnt, people, cache);
    if (clean_cnt < M) {
        ans = min(ans, discomfort * people[idx] + solve(idx + 1, 0, clean_cnt + 1, people, cache));
    }
    return ans;
}

void print_ans(int idx, int discomfort, int clean_cnt, vector<short>& people, vector<vector<vector<int>>>& cache) {
    if (idx >= N) {
        return;
    }
    auto ans = cache[idx][discomfort][clean_cnt];
    if (clean_cnt < M && ans == discomfort * people[idx] + solve(idx + 1, 0, clean_cnt + 1, people, cache)) {
        cout << idx + 1 << (clean_cnt < M - 1 ? " " : "\n");
        print_ans(idx + 1, 0, clean_cnt + 1, people, cache);
    } else {
        print_ans(idx + 1, discomfort + people[idx], clean_cnt, people, cache);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    vector<short> people(N);
    for (auto& num : people) {
        cin >> num;
    }
    vector<vector<vector<int>>> cache(N, vector<vector<int>>(N * 20 + 1, vector<int>(M + 1, -1)));
    cout << solve(0, 0, 0, people, cache) << "\n";
    print_ans(0, 0, 0, people, cache);
    return 0;
}
