#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& num : A) {
        cin >> num;
    }
    sort(A.begin(), A.end());
    long long ans = 0;
    int left_num = A[0];
    int right_num = A[N - 1];
    ans += right_num - left_num;
    int lo = 1;
    int hi = N - 2;
    while (lo <= hi) {
        if (left_num < right_num) {
            int diff_lo = abs(right_num - A[lo]);
            int diff_hi = abs(A[hi] - left_num);
            if (diff_lo > diff_hi) {
                ans += diff_lo;
                right_num = A[lo];
                lo++;
            } else {
                ans += diff_hi;
                left_num = A[hi];
                hi--;
            }
        } else {
            int diff_lo = abs(left_num - A[lo]);
            int diff_hi = abs(A[hi] - right_num);
            if (diff_lo > diff_hi) {
                ans += diff_lo;
                left_num = A[lo];
                lo++;
            } else {
                ans += diff_hi;
                right_num = A[hi];
                hi--;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
