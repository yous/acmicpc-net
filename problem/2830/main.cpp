#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> people(N);
    vector<int> digit_nums(20);
    for (auto& num : people) {
        cin >> num;
        for (int i = 0; i < 20; i++) {
            if ((num & (1 << i)) != 0) {
                digit_nums[i]++;
            }
        }
    }
    long long ans = 0;
    int pow = 1;
    for (int i = 0; i < 20; i++) {
        ans += 1LL * pow * (N - digit_nums[i]) * digit_nums[i];
        pow <<= 1;
    }
    cout << ans << "\n";
    return 0;
}
