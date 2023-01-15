#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool solve(int idx, string& N, int sz, int target) {
    if (idx >= sz && target == 0) {
        return true;
    }
    int num = 0;
    for (int i = idx; i < sz; i++) {
        num = num * 10 + N[i] - '0';
        if (solve(i + 1, N, sz, target - num)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        int N;
        cin >> N;
        string N_str = to_string(N);
        auto sz = N_str.size();
        bool infinite = true;
        for (int i = 0; i < sz; i++) {
            if (N_str[i] != '0' && N_str[i] != '1') {
                infinite = false;
                break;
            }
        }
        if (infinite) {
            cout << "Hello, BOJ 2023!\n";
            continue;
        }
        int ans = 1;
        int power = 2;
        vector<int> digit_power(10);
        for (int i = 0; i < 10; i++) {
            digit_power[i] = i;
        }
        while (true) {
            for (int i = 0; i < 10; i++) {
                digit_power[i] *= i;
            }
            int sum = 0;
            for (int i = 0; i < sz; i++) {
                sum += digit_power[N_str[i] - '0'];
            }
            if (sum > N) {
                break;
            }
            if (solve(0, N_str, sz, sum)) {
                ans++;
            }
            power++;
        }
        cout << ans << "\n";
    }
    return 0;
}
