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
    for (auto& num : A) {
        cin >> num;
    }
    long long ans = 0;
    vector<int> digit_nums(31);
    int cur_num = 0;
    for (int i = 0; i < N; i++) {
        int num = A[i];
        cur_num ^= num;
        int rem = cur_num;
        for (int j = 0; rem > 0 && j < 31; j++) {
            if (rem % 2 == 1) {
                digit_nums[j]++;
            }
            rem /= 2;
        }
        ans += cur_num;
    }
    for (int i = 1; i < N; i++) {
        int prev_num = A[i - 1];
        for (int j = 0; prev_num > 0 && j < 31; j++) {
            if (prev_num % 2 == 1) {
                digit_nums[j]--;
                digit_nums[j] = N - i - digit_nums[j];
            }
            prev_num /= 2;
        }
        int pow = 1;
        for (int j = 0; j < 31; j++) {
            ans += 1LL * pow * digit_nums[j];
            pow *= 2;
        }
    }
    cout << ans << "\n";
    return 0;
}
