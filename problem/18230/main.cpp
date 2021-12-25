#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> small(A);
    for (int& num : small) {
        cin >> num;
    }
    sort(small.begin(), small.end());
    vector<int> large(B);
    for (int& num : large) {
        cin >> num;
    }
    sort(large.begin(), large.end());
    int small_idx = A - 1;
    int large_idx = B - 1;
    int ans = 0;
    if (N % 2 == 1) {
        ans += small[small_idx];
        small_idx--;
        N--;
    }
    while (N >= 2 && small_idx >= 1 && large_idx >= 0) {
        int s_num = small[small_idx] + small[small_idx - 1];
        int l_num = large[large_idx];
        if (s_num >= l_num) {
            ans += s_num;
            small_idx -= 2;
        } else {
            ans += l_num;
            large_idx--;
        }
        N -= 2;
    }
    while (N >= 2 && small_idx >= 1) {
        ans += small[small_idx] + small[small_idx - 1];
        small_idx -= 2;
        N -= 2;
    }
    while (N >= 2 && large_idx >= 0) {
        ans += large[large_idx];
        large_idx--;
        N -= 2;
    }
    cout << ans << "\n";
    return 0;
}
