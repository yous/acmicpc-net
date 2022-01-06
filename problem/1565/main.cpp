#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int D, M;
    cin >> D >> M;
    vector<int> d_nums(D);
    for (int& num : d_nums) {
        cin >> num;
    }
    int gcd_num;
    cin >> gcd_num;
    for (int i = 1; i < M; i++) {
        int num;
        cin >> num;
        gcd_num = gcd(gcd_num, num);
    }
    long long lcm_num = 1;
    for (int i = 0; i < D; i++) {
        lcm_num = lcm(lcm_num, d_nums[i]);
        if (lcm_num > gcd_num) {
            cout << "0\n";
            return 0;
        }
    }
    if (gcd_num % lcm_num == 0) {
        int num = gcd_num / lcm_num;
        long long ans = 1;
        for (int i = 2; i * i <= num; i++) {
            int cnt = 0;
            while (num % i == 0) {
                cnt++;
                num /= i;
            }
            ans *= cnt + 1;
        }
        if (num > 1) {
            ans *= 2;
        }
        cout << ans << "\n";
    } else {
        cout << "0\n";
    }
    return 0;
}
