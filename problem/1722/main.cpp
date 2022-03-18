#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    long long n_fact = 1;
    for (int i = 2; i <= N; i++) {
        n_fact *= i;
    }
    short cmd;
    cin >> cmd;
    if (cmd == 1) {
        long long K;
        cin >> K;
        K--;
        vector<short> ans(N);
        vector<bool> used(N);
        for (int i = 0; i < N; i++) {
            n_fact /= (N - i);
            for (int j = 1; j <= N; j++) {
                if (used[j - 1]) {
                    continue;
                }
                if (K >= n_fact) {
                    K -= n_fact;
                } else {
                    ans[i] = j;
                    used[j - 1] = true;
                    break;
                }
            }
        }
        cout << ans[0];
        for (int i = 1; i < N; i++) {
            cout << " " << ans[i];
        }
        cout << "\n";
    } else {
        vector<short> nums(N);
        for (short& num : nums) {
            cin >> num;
        }
        long long ans = 1;
        vector<bool> used(N);
        for (int i = 0; i < N; i++) {
            n_fact /= (N - i);
            for (int j = 1; j <= N; j++) {
                if (used[j - 1]) {
                    continue;
                }
                if (nums[i] == j) {
                    used[j - 1] = true;
                    break;
                } else {
                    ans += n_fact;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
