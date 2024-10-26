#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<short> A(N);
    for (auto& num : A) {
        cin >> num;
        num--;
    }
    short M;
    cin >> M;
    vector<tuple<short, short, short>> ops(M);
    for (auto& [l, r, c] : ops) {
        cin >> l >> r >> c;
        l--;
        r--;
    }
    string A_str;
    for (int i = 0; i < N; i++) {
        A_str.push_back(A[i] + '0');
    }
    string A_sort(A_str);
    sort(A_sort.begin(), A_sort.end());
    unordered_map<string, int> ma;
    unordered_map<string, bool> in_q;
    queue<string> qu;
    ma[A_str] = 0;
    in_q[A_str] = true;
    qu.emplace(A_str);
    while (!qu.empty()) {
        auto nums = qu.front();
        qu.pop();
        in_q[nums] = false;
        for (auto& [l, r, c] : ops) {
            string new_nums(nums);
            swap(new_nums[l], new_nums[r]);
            auto it = ma.find(new_nums);
            if (it == ma.end() || it->second > ma[nums] + c) {
                ma[new_nums] = ma[nums] + c;
                if (!in_q[new_nums]) {
                    in_q[new_nums] = true;
                    qu.emplace(new_nums);
                }
            }
        }
    }
    auto it = ma.find(A_sort);
    if (it != ma.end()) {
        cout << it->second << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}
