#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

long long solve(int lo, int hi, vector<int>& S) {
    if (hi - lo == 1) {
        return S[lo];
    }
    long long left_ans = 0;
    int left_gcd = S[lo];
    int left_hi = lo + (hi - lo) / 2;
    for (int i = lo + 1; i < left_hi; i++) {
        left_gcd = gcd(left_gcd, S[i]);
    }
    left_ans += left_gcd;
    left_ans += solve(left_hi, hi, S);
    long long right_ans = 0;
    int right_gcd = S[left_hi];
    for (int i = left_hi + 1; i < hi; i++) {
        right_gcd = gcd(right_gcd, S[i]);
    }
    right_ans += right_gcd;
    right_ans += solve(lo, left_hi, S);
    return max(left_ans, right_ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> S(N);
    for (auto& num : S) {
        cin >> num;
    }
    cout << solve(0, N, S) << "\n";
    return 0;
}
