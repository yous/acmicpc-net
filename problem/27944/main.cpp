#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<long long> ans;
    long long num;
    cin >> num;
    ans.emplace_back(num);
    ans.emplace_back(num + 1);
    for (int i = 1; i < N; i++) {
        cin >> num;
        vector<long long> next_ans;
        for (auto prev_ans : ans) {
            long long g = gcd(num, prev_ans);
            if (g != 1) {
                next_ans.emplace_back(g);
            }
            g = gcd(num + 1, prev_ans);
            if (g != 1) {
                next_ans.emplace_back(g);
            }
        }
        swap(ans, next_ans);
    }
    if (ans.empty()) {
        cout << "1\n";
    } else {
        cout << *max_element(ans.begin(), ans.end()) << "\n";
    }
    return 0;
}
